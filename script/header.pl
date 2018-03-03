#!/usr/bin/perl
use strict;
sub writeWarning {
	my ($out) = @_;
	print {$out} "// *** DO NOT MODIFY THIS FILE (see header.pl) ***\n";
}

sub writeStruct {
	my ($out, $config) = @_;
	if (defined($config->{manualStruct})) {
		$config->{manualStruct}($out);
		return;
	}

	print {$out} <<END;
struct $config->{typeName}_t
{
END
	my $persist;
	for my $field (@{$config->{fields}}) {
		if (defined($field->{group})) {
			if ($field->{group} eq 'persist') {
				$persist = 1;
				print {$out} "    // ** PERSISTED **\n";
			} elsif ($field->{group} eq 'noPersist') {
				$persist = 0;				
				print {$out} "    // ** not persisted **\n";
			}
			next;
		}

		if (defined($field->{comment})) {
			if (ref($field->{comment}) eq 'ARRAY') {
				for my $comment (@{$field->{comment}}) {
					print {$out} "    // $comment\n";
				}
			} else {
				print {$out} "    // $field->{comment}\n";
			}
		}

		my $stype = spaceAdjustType($field->{type});
		print {$out} "    $stype$field->{name};\n";
	}
	print {$out} <<END;  
};
END
	
}

sub writeNewUnitialized {
	my ($out, $config) = @_;
	print {$out}<<END;
#define $config->{typeName}_newUninitialized() (($config->{typeName}*)sysmem_newptrclear(sizeof($config->{typeName})))
END
}

sub writePredefined {
	my ($out, $config) = @_;
	print {$out}<<END;
struct $config->{typeName}_t;
typedef struct $config->{typeName}_t $config->{typeName};
END
}

sub spaceAdjustType {
	my ($type) = @_;
	return $type =~ /\*$/ ? $type : "$type ";
}

sub setNameFromFieldName {
	my ($fieldName) = @_;
	my ($first, $rest) = ($fieldName =~ /^(.)(.*)$/);
	die "INTERNAL ERROR" unless defined($rest);
	return 'set' . uc($first) . $rest;
}

sub writeAccessor {
	my ($out, $config) = @_;
	my $typeName = $config->{typeName};
	for my $field (@{$config->{fields}}) {
		if (defined($field->{group})) {
			next;
		}


		

		my $getter       = $field->{getter}; 
		my $getterReturn = $field->{getterReturn};
		my $rtype        = $field->{type};
		my $maybeAmper   = '';
		if ($getterReturn eq 'pointer') {
			$rtype      = "$rtype *";
			$maybeAmper = "&";
		}
		my $stype = spaceAdjustType($rtype);

		if (defined($getter)) {			
			if ($getter eq 'proto') {
				print {$out}<<END;
${stype}${typeName}_$field->{name}($typeName *self);
END
		 	} elsif ($getter eq 'none') {
		 		## Nothing
		 	} else {
		 		die "INTERNAL ERROR";
		 	}
		} else {
			print {$out}<<END;
static inline ${stype}${typeName}_$field->{name}($typeName *self){return ${maybeAmper}self->$field->{name};}
END
		}

		my $setter = $field->{setter}; 
		my $setName = setNameFromFieldName($field->{name});
		if (defined($setter)) {	
			if ($setter eq 'proto') {		
				print {$out}<<END;
void ${typeName}_${setName}($typeName *self, ${stype}value);
END
			} elsif ($setter eq 'none') {
				## Do nothing
			} else {
				die "INTERNAL ERROR";
			}
		} else {
			print {$out}<<END;
static inline void ${typeName}_${setName}($typeName *self, ${stype}value){self->$field->{name} = value;}
END
		}


	}
}

sub scanAPIF {
	my ($source) = @_;
	open my $fd, $source or die "Failed to open $source";
	my @a;
	while (<$fd>) {
		next unless /^\s*APIF/;
		my $line = $_;
		chomp($line);
		my $bracket = '{';
		$line =~ s/\s*$bracket?\s*$//;
		$line =~ s/^\s*APIF\s*//;
		push @a, $line;
	}
	close($fd);
	return {funcs=>\@a};
}

sub writeAPIFForType {
	my ($apif, $out, $type) = @_;
	for my $line (@{$apif->{funcs}}) {
		my ($t) = ($line =~ /^\s*\S+\s*\**\s*([^_\s]+)/);
		die "Bad APIF line '$line'" unless defined($t);
		if ($t eq $type) {
			print {$out} <<END;
$line;
END
		}
	}
}

sub premable {
	my ($out) = @_;
	print {$out} <<END;
#define APIF /**/
sds stripBaseName(const char *path);


END
}

sub BinFilePayload_define {
	my %config = (
		typeName => "BinFilePayload",
		fields => [			
			{group=>"noPersist",},
			{name=>"portFind", type=>"PortFind *", getter=>'none', setter=>'none'},
		],

	);
	return \%config;
}

sub BinFile_preAccessor {
	my ($out) = @_;
	print {$out} <<END;
#define BinFile_nullLengthFieldSizeStr "11"
#define BinFile_maxLength              2147483647
#define BinFileFlag_tag                1
static inline PortFind *BinFile_portFindPayload(BinFile *self){ return (self->payload == NULL ? NULL : self->payload->portFind); }
static inline void BinFile_setPayload(BinFile *self, BinFilePayload *payload) { self->payload = payload;}
#define BinFile_writeBackLength(bf, location, err) BinFile_writeBackLengthFlags(bf, location, -1, err)
#define BinFile_readLength(bf, err) BinFile_readLengthFlags(bf, NULL, err)
#define BinFile_writeLength(bf, length, err) BinFile_writeLengthFlags(bf, length, -1, err)
END
}

sub BinFile_define {
	my %config = (
		typeName => "BinFile",
		fields => [			
			{group=>"noPersist",},
			{name=>"version",  type=>"int",},
			{name=>"filename", type=>"sds",},
			{name=>"buffer",   type=>"sds",},
			{name=>"stream",   type=>"FILE *",},
			{name=>"payload",  type=>"BinFilePayload *", getter=>'none', setter=>'none'},
		],
		preAccessor => \&BinFile_preAccessor,
	);
	return \%config;	
}

sub MEvent_manualStruct {
	my ($out) = @_;
	print {$out} <<END;
struct MEvent_t
{
    uint8_t type;
    union
    {
        uint8_t b[2];
        uint16_t bend;
    } b;
    Ticks t;
    Ticks duration;
};
END
}

sub MEvent_preAccessor {
	my ($out) = @_;
	print {$out}<<END;
#define MEvent_type(cell) ((cell).type)
#define MEvent_t(cell) ((cell).t)
#define MEvent_notePitch(cell) ((cell).b.b[0])
#define MEvent_noteVelocity(cell) ((cell).b.b[1])
#define MEvent_noteDuration(cell) ((cell).duration)
#define MEvent_ccNumber(cell) ((cell).b.b[0])
#define MEvent_ccValue(cell) ((cell).b.b[1])
#define MEvent_bendValue(cell) ((cell).b.bend)
END
}

sub MEvent_postAccessor {
	my ($out) = @_;
	print {$out}<<END;
#include "mEventAr.h"
END
}

sub MEvent_define {
	my %config = (
		typeName => "MEvent",
		manualStruct => \&MEvent_manualStruct,
		preAccessor => \&MEvent_preAccessor,
		postAccessor => \&MEvent_postAccessor,
	);
	return \%config;
}

sub Midiseq_preAccessor {
	my ($out) = @_;
	print {$out} <<END;
const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;
END
}



sub Midiseq_define {
	my %config = (
		typeName => "Midiseq",
		fields => [
			{group=>"persist",},
			{name=>"useMasterClock", type=>"bool",},
			{name=>"sequenceLength", type=>"Ticks",},
			{name=>"events",         type=>"MEventAr"},
			{group=>"noPersist",},
			{
				name=>"startTime", 
				type=>"Ticks", 
				comment=>[
					'startTime is the time offset that t = 0 that is stored in the sequence corresponds too.',
    				'Specifically, if useMasterClock is true, the startTime is updated whenever the ptr rolls',
    				'off the end of the sequence, and raps around back to the beginning.',
    			]

			},
			{name=>"ptr",       type=>"int",},
		],
		preAccessor => \&Midiseq_preAccessor,
	);
	return \%config;
}


sub Pad_postAccessor {
	my ($out) = @_;
	print {$out} <<END;
#include "padAr.h"
#include "padPtrAr.h"
END
}

sub Pad_define {
	my %config = (
		typeName => "Pad",
		fields => [
			{group=>"persist",},
			{name=>"trackName",            type=>"t_symbol *",},
			{name=>"padIndex",             type=>"int",},
			{name=>"sequence",             type=>"Midiseq *", setter=>'proto',},
			{name=>"chokeGroupGlobal",     type=>"bool",},
			{name=>"chokeGroupInstrument", type=>"int",},
			{name=>"chokeGroupIndex",      type=>"int",},

			{group=>"noPersist",},
			{name=>"chokeGroup",           type=>"int64_t",},
			{name=>"noteReleasePending",   type=>"bool",},
			{name=>"inEndgroup",           type=>"bool",},
			{name=>"track",                type=>"Track *",},
		],
		postAccessor => \&Pad_postAccessor,
	);
	return \%config;
}

sub PendingNoteOff_manualStruct {
	my ($out) = @_;
	print {$out} <<END;
struct PendingNoteOff_t 
{
    struct PendingNoteOff_t *next;
    union {
        Ticks timestamp;
        int padIndex;
    } ticksOrPadIndex;
    int pitch;
};
END
}

sub PendingNoteOff_preAccessor {
	my ($out) = @_;
	print {$out} <<END;
#define PendingNoteOff_next(pno)      (pno)->next
#define PendingNoteOff_timestamp(pno) (pno)->ticksOrPadIndex.timestamp
#define PendingNoteOff_padIndex(pno)  (pno)->ticksOrPadIndex.padIndex 
#define PendingNoteOff_pitch(pno)     (pno)->pitch
#define PendingNoteOff_increment(pno) do { \\
    if (pno) { \\
        (pno) = PendingNoteOff_next(pno); \\
    } \\
} while (0)
END
}

sub PendingNoteOff_define {
	my %config = (
		typeName => "PendingNoteOff",
		manualStruct => \&PendingNoteOff_manualStruct,
		preAccessor => \&PendingNoteOff_preAccessor,
	);
	return \%config;
}

sub NoteManager_define {
	my %config = (
		typeName => "NoteManager",
		fields => [
			{group=>"noPersist",},
			{name=>"pending",          type=>"PendingNoteOff *",},
			{name=>"endgroups",        type=>"PendingNoteOff *",},
			{name=>"output",           type=>"Port *",},
			{name=>"atoms",            type=>"t_atom *",},
			{name=>"removedPitches",   type=>"int *",},
		],
	);
	return \%config;
}

sub PortFindCell_postAccessor {
	my ($out) = @_;
	print {$out} <<END;
#include "portFindCellAr.h"
END
}

sub PortFindCell_define {
	my %config = (
		typeName => "PortFindCell",
		fields => [
			{group=>"noPersist",},
			{name=>"reciever", type=>"Port *",},
			{name=>"varname",  type=>"t_symbol *",},
		],
		postAccessor => \&PortFindCell_postAccessor,
	);
	return \%config;
}

sub PortFind_define {
	my %config = (
		typeName => "PortFind",
		fields => [
			{group=>"noPersist",},
			{name=>"objects",          type=>"PortFindCellAr"},
			{name=>"hub",              type=>"void *",},
			{name=>"anythingDispatch", type=>"Port_anythingDispatchFunc",},
			{name=>"intDispatch",      type=>"Port_intDispatchFunc",},

		],
		postAccessor => sub {
			my ($out) = @_;
			print {$out} <<END;
#define PortFind_declare(name) PortFind _##name; PortFind *name = &_##name; memset(name, 0, sizeof(PortFind)); PortFind_init(name)			
END
		},
	);
	return \%config;
}

sub PadList_define {
	my %config = (
		typeName => "PadList",
		fields => [
			{name=>"pads",      type=>"PadAr",    getterReturn=>"pointer", setter=>"none"},
			{name=>"running",   type=>"PadPtrAr", getterReturn=>"pointer", setter=>"none"},
		],
	);
	return \%config;
}

sub Track_postAccessor {
	my ($out) = @_;
	print {$out} <<END;
#include "trackAr.h"
END
}

sub Track_define {
	my %config = (
		typeName => "Track",
		fields => [
			{name=>"name",        type=>"t_symbol *"},
			{name=>"noteManager", type=>"NoteManager *"},
		],
		postAccessor => \&Track_postAccessor,
	);
	return \%config;
}

sub TrackList_define {
	my %config = (
		typeName => "TrackList",
		fields => [
			{name => "list", type=>"TrackAr", getterReturn=>"pointer", setter=>"none"},
		],
	);
	return \%config;	
}

sub PortRef_postAccessor {
	my ($out) = @_;
	print {$out} <<END;
#define PortRef_noNew 1
#define PortRef_noInit 1
#define PortRef_noFree 1
#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
	pr->port   = port;
	pr->outlet = outlet;
}
//#define PortRef_value(pr)                      (*pr)
//#define PortRef_clear(pr)                      /**/
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)
END
}

sub PortRef_define {
	my %config = (
		typeName => "PortRef",
		fields => [
			{name=>"port",   type=>"Port *"},
			{name=>"outlet", type=>"int"},
		],
		noNewUnitialized => 1,
		postAccessor => \&PortRef_postAccessor,
	);
	return \%config;	
}
sub DropDown_postAccessor {
	my ($out) = @_;
	print {$out}<<END;
static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}
static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
	dd->portRef = *pr;
}
END
}
sub DropDown_define {
	my %config = (
		typeName => "DropDown",
		fields => [
			{name=>"table",   type=>"t_symbol **"},
			{name=>"selected", type=>"int", setter=>"none"},
			{name=>"portRef", type=>"PortRef", getter=>"none", setter=>"none"},
		],
		postAccessor => \&DropDown_postAccessor,
	);
	return \%config;
}

sub Hub_postAccessor {
	my ($out) = @_;
	print {$out} <<END;
#define Hub_padsPerFrame           24
#define Hub_framesPerBank           8
#define Hub_padsPerBank            (Hub_padsPerFrame*Hub_framesPerBank)
#define Hub_firstMidiNote          48

#define hub_padIndexToBank(index)         (index / Hub_padsPerBank)
#define hub_padIndexToFrame(index)        (index / Hub_framesPerBank)
#define hub_padIndexToRelativePad(index)  (index % Hub_padsPerFrame)

#define Hub_selectedBank(hub)        hub_padIndexToBank(Hub_selectedPad(hub))
#define Hub_selectedFrame(hub)       hub_padIndexToFrame(Hub_selectedPad(hub))
#define Hub_relativeSelectedPad(hub) hub_padIndexToRelativePad(Hub_selectedPad(hub))

#define Hub_padIndexFromInNote(hub, inputNote) (Hub_bank(hub)*Hub_padsPerBank + Hub_frame(hub)*Hub_padsPerFrame + (inputNote - Hub_firstMidiNote))
END
}
sub Hub_define {
	my %config = (
		typeName => "Hub",
		fields => [
			{name=>"padList",           type=>"PadList *"},
			{name=>"trackList",         type=>"TrackList *"},
			{name=>"currBankPort",      type=>"Port *"},
			{name=>"currFramePort",     type=>"Port *"},
			{name=>"selBankPort",       type=>"Port *"},
			{name=>"selFramePort",      type=>"Port *"},
			{name=>"selPadPort",        type=>"Port *"},
			{name=>"chokeGroupPort",    type=>"Port *"},
			{name=>"cgLocalGlobalMenu", type=>"DropDown", setter=>'none', getterReturn=>"pointer"},
			{name=>"cgInstrumentMenu",  type=>"DropDown", setter=>'none', getterReturn=>"pointer"},
			{name=>"cgIndexMenu",       type=>"DropDown", setter=>'none', getterReturn=>"pointer"},
			{name=>"bank",              type=>"int",  comment=>"bank varies from 0-infinity"},
			{name=>"frame",             type=>"int",  comment=>"frame varies from 0-7"},
			{name=>"grabNextTappedPad", type=>"bool", comment=>"true if the next padIndex tapped should be written into selectedPad"},
			{name=>"selectedPad",       type=>"int",  comment=>"which pad has been selected"},

		],
		postAccessor => \&Hub_postAccessor,
	);
	return \%config;
}



sub main {
	my $out = \*STDOUT;
	my $apif = scanAPIF("src/midiseq.c");
	my @classes = (
		BinFilePayload_define(),
		BinFile_define(),
		MEvent_define(),
		Midiseq_define(),
		Pad_define(),
		PendingNoteOff_define(),
		NoteManager_define(),
		PortFindCell_define(),
		PortFind_define(),
		PadList_define(),
		Track_define(),
		TrackList_define(),
		PortRef_define(),
		DropDown_define(),
		Hub_define(),
	);

	writeWarning($out);
	premable($out);

	## Predefined
	for my $class (@classes) {
		writePredefined($out, $class);		
	}

	print {$out} "\n\n";

	## Structs
	for my $class (@classes) {
		writeWarning($out);
		writeStruct($out, $class);
		writeNewUnitialized($out, $class) unless $class->{noNewUnitialized};
		if (defined($class->{preAccessor})) {
			$class->{preAccessor}($out);
		}
		writeAccessor($out, $class);
		if (defined($class->{postAccessor})) {
			$class->{postAccessor}($out);
		}
		writeAPIFForType($apif, $out, $class->{typeName});
		print {$out} "\n";
	}	
}	

main();
