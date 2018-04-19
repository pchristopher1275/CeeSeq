{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 433.0, 236.0, 1486.0, 1091.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 693.0, 354.0, 59.0, 22.0 ],
					"style" : "",
					"text" : "disable 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 615.0, 344.0, 59.0, 22.0 ],
					"style" : "",
					"text" : "disable 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1835.0, 426.0, 142.0, 22.0 ],
					"style" : "",
					"text" : "set \"1\""
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-144",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patching_rect" : [ 1796.0, 286.099976, 227.0, 22.0 ],
					"style" : "",
					"text" : "Port @id chokeGroup @iinps 3 @iouts 3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-139",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1579.0, 704.0, 100.0, 22.0 ],
					"style" : "",
					"text" : "stop"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-136",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1169.0, 766.599976, 50.5, 22.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 1170.0, 765.599976, 43.0, 38.0 ],
					"style" : "",
					"text" : "Conf 3"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-135",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1169.0, 733.599976, 50.5, 22.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 1168.0, 735.599976, 43.0, 38.0 ],
					"style" : "",
					"text" : "Conf 2"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-134",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1169.0, 697.599976, 50.5, 22.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 1169.5, 697.599976, 43.0, 38.0 ],
					"style" : "",
					"text" : "Conf 1"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-133",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1169.0, 664.599976, 48.0, 22.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 1172.599976, 667.400024, 43.0, 38.0 ],
					"style" : "",
					"text" : "Status"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-132",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2196.0, 727.099976, 186.0, 35.0 ],
					"style" : "",
					"text" : "clear, append none, append foo, append bar, append baz"
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-130",
					"items" : [ "none", ",", "foo", ",", "bar", ",", "baz" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1231.800049, 766.599976, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1231.800049, 766.599976, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-129",
					"items" : [ "none", ",", "foo", ",", "bar", ",", "baz" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1231.800049, 733.599976, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1231.800049, 733.599976, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-128",
					"items" : [ "none", ",", "foo", ",", "bar", ",", "baz" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1231.800049, 697.599976, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1231.800049, 697.599976, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-126",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2189.0, 663.699951, 198.0, 35.0 ],
					"style" : "",
					"text" : "clear, append none, append phantom"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontface" : 0,
					"fontsize" : 16.0,
					"id" : "obj-118",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1227.800049, 629.400024, 112.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1229.100098, 629.400024, 109.0, 24.0 ],
					"style" : "",
					"text" : "Ghost             ",
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-122",
					"items" : [ "none", ",", "phantom" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1231.800049, 664.599976, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1233.100098, 664.599976, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontface" : 0,
					"fontsize" : 16.0,
					"id" : "obj-116",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1407.100098, 625.400024, 108.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1405.0, 627.400024, 109.0, 24.0 ],
					"style" : "",
					"text" : "Track             ",
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-117",
					"items" : [ "none", ",", "lead", ",", "rhythm", ",", "piano", ",", "bass", ",", "drums" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1411.100098, 660.599976, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1409.0, 662.599976, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-115",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2189.0, 601.099976, 183.0, 22.0 ],
					"style" : "",
					"text" : "clear, append none, append arm"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontface" : 0,
					"fontsize" : 16.0,
					"id" : "obj-113",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1575.0, 625.400024, 109.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1573.0, 625.400024, 109.0, 24.0 ],
					"style" : "",
					"text" : "Record          ",
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-114",
					"items" : [ "none", ",", "arm" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1579.0, 660.599976, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1577.0, 660.599976, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-112",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2189.0, 519.099976, 208.0, 22.0 ],
					"style" : "",
					"text" : "clear, append thawed, append frozen"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontface" : 0,
					"fontsize" : 16.0,
					"id" : "obj-75",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1575.0, 541.400024, 109.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1581.0, 542.400024, 109.0, 24.0 ],
					"style" : "",
					"text" : "Freeze           ",
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-77",
					"items" : [ "thawed", ",", "frozen" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1579.0, 576.599976, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1585.0, 577.599976, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-73",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1516.599976, 405.0, 43.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1429.599976, 402.400024, 43.0, 22.0 ],
					"style" : "",
					"text" : "Index"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-70",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1489.599976, 364.400024, 75.0, 22.0 ],
					"presentation" : 1,
					"presentation_linecount" : 3,
					"presentation_rect" : [ 1456.599976, 365.399994, 43.0, 53.0 ],
					"style" : "",
					"text" : "Instrument"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-69",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1516.599976, 323.399994, 48.0, 22.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ 1454.599976, 322.399994, 43.0, 38.0 ],
					"style" : "",
					"text" : "Scope"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontface" : 0,
					"fontsize" : 16.0,
					"id" : "obj-64",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1575.0, 455.399994, 109.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1513.0, 455.399994, 109.0, 24.0 ],
					"style" : "",
					"text" : "Clock             ",
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2191.0, 425.5, 212.0, 35.0 ],
					"style" : "",
					"text" : "clear, append trigger, append master, append masterOneTime"
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-62",
					"items" : [ "trigger", ",", "master", ",", "masterOneTime" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1579.0, 490.600006, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1517.0, 490.600006, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontsize" : 16.0,
					"id" : "obj-60",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1575.0, 282.200012, 179.000031, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1513.0, 282.200012, 179.000031, 24.0 ],
					"style" : "",
					"text" : "Choke Group",
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2191.0, 345.099976, 219.0, 49.0 ],
					"style" : "",
					"text" : "clear, append none, append 1, append 2, append 3, append 4, append 5, append 6, append 7, append 8"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"linecount" : 3,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2194.0, 259.099976, 220.0, 49.0 ],
					"style" : "",
					"text" : "clear, append none, append lead, append rhythm, append piano, append bass, append drums"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-48",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2195.0, 167.499969, 219.0, 35.0 ],
					"style" : "",
					"text" : "clear, append local, append global, set local"
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-46",
					"items" : [ "none", ",", "1", ",", "2", ",", "3", ",", "4", ",", "5", ",", "6", ",", "7", ",", "8", ",", "9", ",", "10", ",", "11", ",", "12", ",", "13", ",", "14", ",", "15", ",", "16" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1579.0, 405.0, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1517.0, 405.0, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-45",
					"items" : [ "none", ",", "lead", ",", "rhythm", ",", "piano", ",", "bass", ",", "drums" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1579.0, 364.400024, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1517.0, 364.400024, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"id" : "obj-44",
					"items" : [ "local", ",", "global" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1579.0, 323.399994, 100.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1517.0, 323.399994, 100.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontsize" : 16.0,
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1227.800049, 448.399994, 157.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1227.800049, 448.399994, 157.0, 24.0 ],
					"style" : "",
					"text" : "Midi File Drop           ",
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-29",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1000.499939, 563.400024, 36.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1000.499939, 563.400024, 36.0, 22.0 ],
					"style" : "",
					"text" : "Pad"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-28",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 984.499939, 520.400024, 52.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 984.499939, 520.400024, 52.0, 22.0 ],
					"style" : "",
					"text" : "Frame"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-26",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 992.599976, 479.399994, 43.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 992.599976, 479.399994, 43.0, 22.0 ],
					"style" : "",
					"text" : "Bank"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1637.0, 29.0, 97.0, 22.0 ],
					"style" : "",
					"text" : "Port @id selPad"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1506.0, 29.0, 111.0, 22.0 ],
					"style" : "",
					"text" : "Port @id selFrame"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1388.400024, 29.0, 103.0, 22.0 ],
					"style" : "",
					"text" : "Port @id selBank"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1261.300049, 29.0, 116.0, 22.0 ],
					"style" : "",
					"text" : "Port @id currFrame"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1141.0, 29.0, 109.0, 22.0 ],
					"style" : "",
					"text" : "Port @id currBank"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 955.900024, 1094.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "-3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-127",
					"maxclass" : "newobj",
					"numinlets" : 4,
					"numoutlets" : 4,
					"outlettype" : [ "int", "int", "int", "int" ],
					"patching_rect" : [ 352.0, 936.800049, 80.0, 22.0 ],
					"style" : "",
					"text" : "Port @id ev0"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-124",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 985.399963, 364.400024, 50.200001, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 985.399963, 364.400024, 50.200001, 22.0 ],
					"style" : "",
					"text" : "Frame"
				}

			}
, 			{
				"box" : 				{
					"fontsize" : 14.0,
					"id" : "obj-123",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 992.599976, 323.399994, 43.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 992.599976, 323.399994, 43.0, 22.0 ],
					"style" : "",
					"text" : "Bank"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontsize" : 16.0,
					"id" : "obj-121",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1227.800049, 282.200012, 179.000031, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1227.800049, 282.200012, 179.000031, 24.0 ],
					"style" : "",
					"text" : "Frame adjust up/down",
					"textjustification" : 1,
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontsize" : 16.0,
					"id" : "obj-120",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 990.599976, 282.200012, 185.599976, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 990.599976, 282.200012, 185.599976, 24.0 ],
					"style" : "",
					"text" : "Current Pad Coordinates",
					"textjustification" : 2,
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.287863, 0.333333, 0.329398, 0.0 ],
					"fontsize" : 16.0,
					"id" : "obj-119",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 979.599976, 448.399994, 225.0, 24.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 979.599976, 448.399994, 225.0, 24.0 ],
					"style" : "",
					"text" : "Selected Pad Coordinates",
					"underline" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-108",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1480.300049, 1003.200012, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-109",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1480.300049, 961.466675, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-110",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1480.300049, 919.733337, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-111",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1480.300049, 878.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-104",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1416.000122, 1003.200012, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-105",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1416.000122, 961.466675, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-106",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1416.000122, 919.733337, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-107",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1416.000122, 878.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-100",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1347.200073, 1003.200012, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-101",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1347.200073, 961.466675, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-102",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1347.200073, 919.733337, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-103",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1347.200073, 878.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-96",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1275.0, 1003.200012, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-97",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1275.0, 961.466675, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-98",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1275.0, 919.733337, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-99",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1275.0, 878.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-92",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1142.199951, 1003.200012, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-93",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1142.199951, 961.466675, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-94",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1142.199951, 919.733337, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-95",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1142.199951, 878.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-88",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1079.0, 1003.200012, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1079.0, 961.466675, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-90",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1079.0, 919.733337, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-91",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1079.0, 878.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-84",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1014.200012, 1003.200012, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1014.200012, 961.466675, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-86",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1014.200012, 919.733337, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-87",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1014.200012, 878.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-83",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 947.0, 1003.200012, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-82",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 947.0, 961.466675, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 947.0, 919.733337, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-80",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 863.300049, 1003.200012, 54.0, 22.0 ],
					"style" : "",
					"text" : "duration"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 863.300049, 961.466675, 51.0, 22.0 ],
					"style" : "",
					"text" : "velocity"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-76",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 863.300049, 919.733337, 36.0, 22.0 ],
					"style" : "",
					"text" : "pitch"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-74",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 863.300049, 878.0, 33.0, 22.0 ],
					"style" : "",
					"text" : "time"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-72",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 947.0, 878.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgcolor2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0.0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"gradient" : 1,
					"id" : "obj-71",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1043.199951, 610.200012, 133.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1043.199951, 610.200012, 133.0, 22.0 ],
					"style" : "",
					"text" : "selectNextPushedPad"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgcolor2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0.0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"gradient" : 1,
					"id" : "obj-67",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1252.800049, 364.400024, 133.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1252.800049, 364.400024, 133.0, 22.0 ],
					"style" : "",
					"text" : "decrementFrame"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgcolor2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_angle" : 270.0,
					"bgfillcolor_autogradient" : 0.0,
					"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_color1" : [ 0.92549, 0.364706, 0.341176, 1.0 ],
					"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
					"bgfillcolor_proportion" : 0.39,
					"bgfillcolor_type" : "gradient",
					"gradient" : 1,
					"id" : "obj-65",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1252.800049, 323.399994, 133.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1252.800049, 323.399994, 133.0, 22.0 ],
					"style" : "",
					"text" : "incrementFrame"
				}

			}
, 			{
				"box" : 				{
					"cantchange" : 1,
					"id" : "obj-51",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1043.199951, 364.400024, 133.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1043.199951, 364.400024, 133.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"cantchange" : 1,
					"id" : "obj-55",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1043.199951, 323.399994, 133.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1043.199951, 323.399994, 133.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"cantchange" : 1,
					"id" : "obj-36",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1043.199951, 563.400024, 133.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1043.199951, 563.400024, 133.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"cantchange" : 1,
					"id" : "obj-35",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1043.199951, 520.400024, 133.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1043.199951, 520.400024, 133.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"cantchange" : 1,
					"id" : "obj-21",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1043.199951, 479.399994, 133.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1043.199951, 479.399994, 133.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 883.200073, 645.599976, 125.0, 22.0 ],
					"style" : "",
					"text" : "prepend midiFileDrop"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 882.0, 741.0, 115.0, 22.0 ],
					"style" : "",
					"text" : "Port @id guiBottom"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 517.0, 580.0, 166.0, 22.0 ],
					"style" : "",
					"text" : "midievent 144 65 0"
				}

			}
, 			{
				"box" : 				{
					"autosave" : 1,
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"id" : "obj-7",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 8,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal", "", "list", "int", "", "", "" ],
					"patching_rect" : [ 396.0, 653.0, 92.5, 22.0 ],
					"save" : [ "#N", "vst~", "loaduniqueid", 0, ";" ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_invisible" : 1,
							"parameter_longname" : "vst~[1]",
							"parameter_shortname" : "vst~[1]",
							"parameter_type" : 3
						}

					}
,
					"saved_object_attributes" : 					{
						"annotation_name" : "",
						"parameter_enable" : 1
					}
,
					"snapshot" : 					{
						"filetype" : "C74Snapshot",
						"version" : 2,
						"minorversion" : 0,
						"name" : "snapshotlist",
						"origin" : "vst~",
						"type" : "list",
						"subtype" : "Undefined",
						"embed" : 1,
						"snapshot" : 						{
							"pluginname" : "Kontakt 5.vst",
							"plugindisplayname" : "Kontakt 5",
							"pluginsavedname" : "Kontakt 5",
							"pluginsaveduniqueid" : 0,
							"version" : 1,
							"isbank" : 0,
							"isbase64" : 1,
							"blob" : "94798.CMlaKA....fQPMDZ....A3TZOUC...P.....Afza0MWYf7jYfPEZkAhToMWZtcFHSUma........AHmDRHW.......P.....nMWZtE..........rkhtzgTY.UjmraDRKI4X2ZI.........DMURNYG...P.....HA.........QSkjSpA...D.....F.........PzTI4T.....A....D....P.....A....D....................PChUVgA....3.bP.......A....D....................v.....v..L..C......................D....P..........PzTI4Tc.....EW.......P.....nMWZtE..........Pvo9pkd3M4sf++oPSt2gvAQbA.......DMURNUG...P.....fCW........QSkjSyA...D.....F.........PzTI4T.....A....D....P......7JbA.......A....f1bo4V..........zZnVgat+MTIalCBPOks1CFF.........PzTI4T.....A....D....P.....A..........MKkjSC....rEbA.......A....f1bo4V..........jUt0xYy69DGflFhJwTO76Rm.........PyRI4z.....A....bH.........DMURNUF...P.....RA.........QSkjSpA...D.....F.........PzTI4T.....A....D....P.....A....D....P.....C....PC.x.PM............i2mFCD......B....D.....B....0.fK.XC.t..N.3B.x.PM....A....P..........DMURNwF...fuA........D.....ZyklaA.........fiOZ.p0zwSuhodDR2btnicNF.........QSkjSrA...D.....F.........PzTI4T.....A....D....P.....B....D..........M....3D.kAvc..B.n..Y.TF.lAPX.TG.rA.c.jB......................7++++++++++.....................D....P.....A....3....fU.jF.tA.c.DF.mAPY..B.OAfb.bF.gAfa.LG...........vA....G....vE..AvX.7F.rAva.HG.A.....C.Q....vE..A.Y.TF.1APZ.LF.kA.c.jG.vAPY.XF.rAPX.bF.yAP.....w.vB....bA.P.LG.uAPc.3F.jA.c.jG.vAPY.D.....L.b.....W..D.zAPY.zF.vAva.D.....L.X.....W..D.1APY.HG.rAfA....w.fK.bC.t.PL.PC.F....vE..Afc.TF.xAPa.X....PL.3B.2.fK.DC.z.vA....bA.P.XG.oAvb.jF.hAP.....v.P..........H.....QSkjS4A...fF.........A....f1bo4V..........HRn1wO1mdTinNZTcFG9n5HN.........PzTI4Td....A....fA.........DMURNE....P.....A....D....P..........D..........A....PzTI4Dc....9uV.......P.....nMWZtE..........aHRAY3cVKAeqCw2bYUOOa47ZA.......DMURNQG...P.....0tV........QSkjSyA...D.....F.........PzTI4T.....A....D....P.....AjfuJ..eqE..j1pS0VkqoK8J1CwRSAZsZxs3id+4o6gp0AXSIkUnQiy7VK7lA3i8yXke5GZqVQbt9Es+VnJNTDonDV3VOi.BtPIQU.h7sr2P84jKzgFQIFwsxfb61gLpradfbRO1H5fwZPpNARi9dz0kZYais+Z8T20uVCYyVcWrxi9H36xN+6sfbe3wCRf132IKA0WkVBs2l7mHKwm5w8I5K1Wby5VuUrHmyci3iEODxu82IZQ3TJphR.MbdbMonv9RqrJUck6OUfa9X14FwRzGYN..E4wn+CUJdS+7BtZ.Toy9meqIn1ijiw4z8kEjlsMU6sZquny.gDB1V00FB7VZQH2NiG24n+ryVV2BSQGLn5LftzfAA2WSqoDSZSDqQSMMENn1RVYaoOLHYEj7yaGPM+SoxluHsgW8k9QVX35Tlt3u0mlqJFcp+3ar7pOFnPFwPJNq1ez9yCxqgih6jO9+h0sQrsrIs+GOlVTyfKqjaT.tfkymuQ9ZPFe4wdvStlbqm04UeHSssoVlgJ3pbI7WUumeE.8cqfIPSMI2RfdD7m.JjXhx7hANJyYkPm7hsHgjmYAArLwUTKqmrV2ixg7X4G9trGKvyUd0HU3a3PqFZtyl7oVTmyCGot8Dn8X+6YF7.IlyJAMhR6eo1JzZzoOOupC+pRpxnKPq.3ARNjdj6RBC.I12OOA+ICNTOPC2lGV5r4JNYUEhk0n6CE.lz7iSG+4F8fX3mFy1xNdy0HnvzkpY.6y.kacM68G8k1CuDaeBYL5d0XRZASRoitajfsN3LHzhZ5ScP6CcwLGmllTHRLgL1kwnx8XnmApGndks35Hgvz.3rdi1UvY9J.p.Fu7o1ydMOSgXbOEV7eyBHSYzQjjteMaUSQz4eiMT348UT84jPfwPZDVmOWMiymtJM+8t6DtYfhoQmFl67OdzFU2Jzdc.BsB8W07l+jDgrqKZaa73vtyINfIpF4G8dd3+E.Kf42HHOOd7DKUWpWsctw5.K+D3z9TDQHpf7O1ppl1cN4bFKO3totnF1vqumT8v3pddhACynmxKRF6gjtJ21aPibryfc81zzfxntJNjvnGjT+1GMePGaEqDrbgYsRvFp6GBpOtICU9QxdzlEUIE+F+dupdQB1nHabCfpmZnQMK+QzG5ZWzervqoCKJlFBHrZIBJuyoLyeZpY9GMN3VXVo4KAsYdBc11we0hjpLC43RGl6Xmszd4CTWa67RSrgacJ2DCxKB6F8VMn10PEAxRiaYyXHNzCKZBtskmwbBByiqgG0nt8wgmbxBQJ3VRXhcV11L0MA6jf0Afpc90lH8oNPxypVImIHyxT51.aejQr+D3Q7Le3rvlyUI03tNbpQ2aWFOLHFQ6CJNSpy6chYKqqQEgPHVties4HcZn+KiQloZ6mv.eEYmD1x7QaW3e3sDUcOnRaghlX74H+PlgoMypJSSy9Ps6MJ0W1zGVa6jD6+W4unbZfiaHKyFoeKpNV1zmGgbK7GCPmKgXHSJZECuHVqajli46gtbJ0E8P4+.WhQY8lwcPJ67UQkKXfgPWfgDZBUJU9YqcGZoDNU5EggM.tHBMgs8FpOY1X9TUiWiVCjBrU90RfBlDOhlmdOPYxVX0EdJd9R16CrRLJqsywcpR7YQmcW4PapSH3eED5Rm3wynyqsf3h9eHoC1tH3sAH.qmrk2BmsrkPuqtPSsc2PPRzVJgQd4r4zSepVRnp3m7hJz3g0jFATEtrbU1tW.QcZxHihHHpKwcjUtLY8e8wEnbNmXmkRJmMZ+Ztpz1aMKvqgLPRU1zXDX8Ifj2rZ9hW1p+zfO7sq62QKwPKrqoqOBUQSBPiy26rx9SbX6xxOqAAuLZ6GN+NWU9XItmwi2H9KjJvIFnk2qSF+n6IPRSocoUyoj8tu6UHQxAc.EUI1J39veXq0iEM0jE3MHaCF2anuhVhwg47QL2.xCG0Q76oVv3DCB5PFowOy6EarAPnLkjhd6qvMGqAafMqw5U2YdaV+FlRZqtJ9gnsB+XI62eT.c3P8pYtMPEdUPWJBK66mKliVR4AZrf.GqSymIaDap8XAwFa33OAM4MfFv668aL0oBkKe7cBpIsdVWa6+H1aYLYqbqkAZVcAAQq4PnVx9SvQTnUWW3enEIuC0XJL6IJP8ycL2KuTFYz08p.Ar3MDocDDwZT7Jyztn2p0o11kzT+oMoW0yVqiyyelw2wVYEs8Q2VMPx7wcytVZfvHYqVDj1bdcQAgPY0s60QR1vWDjjtx.gMQA5i2TS0ZA0YvQHavXArnMS7bcWJ0DGMOwyEEx43XhO3setWX.1nUbLFmcc8d.gEJ8FMd0mpCnrL.dsrMAInR7OnvqXMDm5Fbft1SJ8AgIpLvsn2FG4bgTRKH.o4QSv4is+ZP2aQ7Ivn+b.tmR6oHMOwtXl+miHP9rt9Ev1BCNAzqwLOxIv6jZtEK3C5TOd14buKXR.WBfVxZ598lbkKTW3Dw+g8WEsvkvQ9cIxxfytwvp8.bbXJWS8i2rEW8kK5iCHvSCeTjdthRl7I9jAFdCPh7Uqms.Q+FQZ0iFOFqFap7t2B4fMuiE6ML1QQgv8zN9JbsOHBa.xGnhwpAgw8p+aD7sKSo62tvO9z.tUpGMmqjqrboT5i1DhAATVRhrNBRKxsVFsOkW14v+C1XHNJi25auTsdiw.TEyJ5G7tGGaBet4KORmHW6..gYWQVzLG2TPwSEFy8Ze45WTvodYVT+bNwR6YameCussJXjRHP+GJCrwduabJTNT+VT6twyZ+EgT0Si+mqQ3MV99QH.AKudP47q+fxFmiNDDNSSXybNH6w56rJMtRKvZHyqBK3kvi4bA5KzSgWQQUajy7kulV7PqBO+g+Tgqq9x6ITzjLAGbyE0uK3BCTY4ICwKkfoN9K2A04WzbKFthe1MOWczLvy5E2WoSbUd2EkH6aQPTXCRTQBj1.BSw53W.PFl3B.oyzoBeAShw8v3PM6ML0eu0OjfZHvI5BNvo1G.86S55QVkLRdNKOzLAxk4nx4r8pz9qB0367BatfJ0tAEcqc7iRh6Qz44Kub3LgL.VlEeDCA0tIeOzgmkkY1KIL3Yac5uVLxRbH.8Zb5dEUG4Px570ZV.55c1RTb8PX5441bWJLhSDALnNfhj1q55mh511SKVeCIOmbr8j3McjNuu6BHU9w3Ev0QSDN4LnO32CLWjI7Xpd4ZHE.Gm7hsBKjWNFWd1s8RioLYbGmYAIMdA5CpI7XxnTEmdVjyx1DFL0VpFN4RaCh0OpBl.YyaAt4BEhLK3f6J.E66WMxWs9zV0HUfwj2KwjcZbOLys.BwUyDM7thSlAs2w0k3w0U.UoeOTe0H1AUyUaYUPYf+SlWIBpjHX4EZsaQg4hf1gYcYimnAa+1EfxllmoEn+VWk7mct.tUGtkqbws.YHGfy8b5WBZUXU1EVky0TKfiAzfcVe952BhLz1Ezwy+81Awv0vsiVwQXtrxErj5K+B8Ip758GKda72AyMN7KVa21lj5kX146sOFPVm5X3z.XPA7OX8qBBM3xKLIpuJghgZCZm2qZdeGWbgnJEoXj9GbJJcMjixM4oZRs8F4n3C4VW8.F2DBAWgGsatPpBJDgNq02aId2BORAFlpZ6UCVoL1hZrsBU.LJQh2BB88tbQuxHu9ezma7Pz5jJUO1e3wgsAQ8kC772EFdtbMATrkSQLXTJCHr1HH9iVRYOI8EEosL5Cj+UmSIwBJLgxS366SOPdDVzqE3xer6gfWL31DCep3XswcSHaiVlcv6pbhTj3uNUL+fTwhhml6bEfoZc5+OeX1tHe4CrwrcgMrcIomvttFLAtCGm8hjf0TAdctMdYr3qpErOQdAoab0Ig99mjl5JI7UDMAvtIwD9AqTU7dw7jrH+8C3X+Us3U3VwaHaD4dYfH5IcNb9gJpjV5L9Yn.M+F5EAaQMUD9Vw1h6kxrxEBlHjRUE+d3JntbJ20mNc1aw06h8kBYnHojRBTyzSVzTphlwkc57jh7QIHL9EXMoy1Pcr7QdoYRhN+nJNdTj2GL.vDxPRwNkyvpraXW6kdZ9Ieq6Rsmil81UsMTh9ZB1X3r.lwN3ZjvzO0xGSoqf2XH0PCYKnmWPiHhDPLz67mp7Uvlegna2Ce2kdqHvaRtIFl5ofkp8tjk0DBuQilfav4nVuHG6m7zus8nd1IK+A9J5mg+9TvCLtJNsSbQOnX4cFx3+AeUxSjmHOXwXgZYIyfQurgh3sHiiUD.x2gKRq0.cLpgtVhvJm88EJ90khphzixdhSI01vLsTHLnwdUOOKojxl+NN3GT.b5ugp0Ix5gorifxKarnZpSPNOtCoH2lmY02EQGk+0SC2T7xyYwH2sBCtaIM.HL.v779.0z0BgdvtwWTTANfKxpnoiwHHRJIXxnoQn7WhdMQZ+uyaAHJJL37l9X1TM3nlXDa+7WFK2JQukYUVyWbl8JUARpO9yPaaTbhgI8XAlZVTN85ufGaVBuugYKQ+VVmrQwHtpppBmd3JGUh0yAwpUYjs4PUqx+6YsbPZY0W5+u7afbsxjhDQfaw9CN+9yNMyn2VCMfUVl2f5Z8y0GRFhYu2uStDSuozcCksmXoZE99lepVm+NX4+Vi2cBKFjd0wxmEM5WmzMVeu2X11HS5YRbyrJzcNvMnBDS1reyUibOnlIWRxbfFtvlLkCgzs1W1z1B5as7ehz+vXq3rAzHAT8.pJhVwDQm.hzdnrVTCJ6m+IiWs5SI5IeVJqOablLe.KVwvm0wmvixIDztl.DS61iZrhuSixFu4gQPMp0zyTmH1Hu1Nn1YWTMjKGydB+wcjh5eMm6Eegij1UJiL2dtgEanCO7mWZspVV08Gfw9HA6zVaOkbHUMkcehKY.N.XFf4NXsXuK9jEkcOS1OA3wN214q5fUeB6FeMFRac.cq.nU457cfacY+DQtOFYu+BXCJL+U.4V8kRVJYL82AauCM5BMinZ.PfnTleqNodMwA1ANKUzErRmbT.zMFq6HJBnXsZ4FID4kxFrsN1W0MYv73XLZhQjmKFsZTXcwgOPPYh4QkjWdJBn92QJR2k5oWikgxeaRmpB4R8tDURqap68n9Ud6g26UZSzq2E1XNWmo2J05lcwVpI35brQSZRwK8kCHeaCst0KNJ5+4BfG5xwl5HkaCp2j+BpIIlgRH7mWw45ZEL1J7SfwR.tUmCtY3hnAFdlYuhFQJhw6qgE8QjeF6irAYrTEhkdX2zxmOPDeGo8xXJmzpccRahxmgJLZqulbJKKhqryht.SSZ8483sNPL8yZuh1wmTJ4Ou895miTyIxb2rTfkAlSpA3swfQvFi0FGoJi9vribYcG0++npfTQKOGZjXydL8KF3kO7ksq+0cOh3gsTqBfH7iIg0CRQPdUtglTzhEx8KfWiQlibhFITx.xsa.v1D.11g8Y1AIKCsCLhhF6TxQaAy3GNHZP2+c4HCe83636uLwx9RziqKBUDJU4F1PAhbxFV6q+.qC3gKbNvYSeu0O6R8Cy.eH7Irkmnuakymu.mhbvR8lNnSSBZDVrmFtOLITG7j5pFgSuwyNOxi0nx3Mm0TU9Hrbvw7PqMwkA1SQZrkbfDAUahIlghPz+ftEwydJeRjYY3c24kzq7NFPq9u.yC9AxuPjI4Cm6rCF9TA9beHheA1RQXh4zQgRd7XnMbTjIHYPXh8YihJSP6jJSLoXRebVksCNgwn886TCfEZtSxXR4HcJbSF7jPHv8HMVGp9cBIASBpVJfsimRGHWKAAjSJm2275+J9H+kyi4WZABf1jaVfui4f9MCbddgGw.jX5ntA43NstBfVibJ5UTxKIXpO8wtCpEaM7pU.OGC8qhpOKX2Jd9XDVwHOc7FclQ0YJDMA+Onk.So2Wfyfe00W..smnhPe9eVo4onBPEjlNkbdnw2OE5sKopvEpDusOJAffI4FRqPaU67W6zbX3u+bA1uG84KWsOc4muuPUqnkOmNqTHK9UIHqW6OiquWQfthejrJMMUMPoTOV5wFy8helpk5s3FEZPleQRtTxJuMEE.V.6lmOkZbUMsqXCt3T4OVCPtL1usmRIiFSwZK45iY6Kvcv5RJC8.2z2G3ilxdPFsBx8whTeP5hIc0elzfiCJJ5RCB6Ta0GQcX.quEUwRXEZsJVkWfEdpli6dmocNL+GE4nTc93NnDvklfvq6j37L6yxaVHgJd7hhZNUMQuM+vxAekwiXfBkEeWuGxk7xyESj5U62yGb14O+JOHQtJYUPr6xD6biIEo8mLRc1tN9Zmc9fBVp9thlqnMMHF+nnEp2Xn6t08M3l8A4hFwZaj9sNzX0im7HCEwZtlwgKcgf7jeoij.FmbUS1qbuxiUUEC6S.DTBLkwk+qmyWfRh25VAhl3ISz0bmrZ1oCpCUM72LjUPzE5ibBy+4l082vpKDSYNYezv3LFMCn22UNU8CWAcuPaMPXeCIqiisUwQxoY78BSuUa6OuIsPsVxuS6JC7rblvfk3P3cxNJrAVvrkivgo8XimsfJYYF.ASKk3xFYwaZxKA5VqU4jDb5yOfLgj9nuyeqNjU6rj2yRMP6FSSOZ.wJGJZ+XDld7R54CbCiOgXd7uAZo095VzjjE2SACfTZoGank8w7pCkRtruQe5JTmDPAgHoE2o6Sy1.Rf6Cg86gGrEo2EVL5QXfCKIeSAYd8SWKhtD+K7awe7juOAysyekuM6VgZ3+AxlpLEm+r.emvKw4HfwVEWMWoqCLrZsqoWj573rHeLlciP+rvft0rfhohw94d9mXpzTAyv1Eg5bDt69yQOA0sRUgZwVx9w8N8sUHwc7IuLLeut2YCKGMXQZUI4r3vPAPjjELIJSm7qu5p9bKJfRU9XSMAr9v5xK4RmfuPxuOh2vmTnlGqVDEKRF4v54yxcoSIRROnCBhFkx6bfCn4msQ03daI1MZfK26VpMIpznRW5T+vGMEGPKFJ3L1bA2O82YmYdq65HjwSnBplyiT6xQGIaWNNfhd7IlnzPqPHCeTyOhrqbdesGHzjNcg.CAeA0CUlRw5XRdZwachXSztxLrfD4O4745lDkBY5jr7GqstFDZ9rtk1SPp6znvhe8CoWu50arYCDCQvTtVjiL5bpDa6ViOcP8tId0v8m657cs8MRoV4RS.DWC5nc6qrLBrG9qZGy3ImnVxL..eEAfJM5gO.mfSnCFjFVrz1hvmVb6bfcdiLaH+8VUpdtm9zC5cdbext2RyMBooTCN5CRMeq62qmG.vdZXk.PP+YGnHFfb6Y9lzwYX2G67SpI1KWPm5wtaueVzrlqfAGD3w8xeFPNn1Dt5uXhMKoTgS9YMKtq+koSLbOXKS9NOi9aShjY9KAUT1akJfTaRQJ.PHlYdlcRekwTfA1UkvGSB9oEbE8zfOdLudKCgmHeCSquVn0yjcKEOH16+cjgVqVeo5w3Twlroz3AMViLd7CTmwcj3EJVyJkZu5AZpkffJ44B25FGo9QseGMtmYAF.ACReyAq6zBbdsW6mEuwDrwTmftzyAkMbaarwRNnNBqFfK4Y76mf2Oz.TZ2A0C8M3IiPZLYtHlBJFpB8KPPIXpcFjk6Al5Rax+uyLnf7Wkpubds6DYT9pTz1H43nga6kkW2sqLC9iFX4Z4eEg8gjNzYOUfsJYDuWeEIxCU0OdRw8HIOxUnERZHr6Kw6OtOtOJJD49t.msXxCCa+ETlpHXpqCV26aZa8gzUTGlNicdiUZ47UzCTekA7UXXBeCI3iWNhoEzxKphkfr2FU0JyamrkAYEYT+4jZhsUtwd5nXjBSEka5ILBSpb37jnNappGheK8t3Yy1LIOERYYU690svRMcn7aShZS3goEFxRDM6ZqVcaAWlew5L7QXky+b3wgAp9cqD5j0m1mQw3f9krGj0Q4sFRAaICREUvQK1SPh+DGaYBalQL2ls0vcMyC.g+jvVTsiTM3XszVNUODWQ.NGKbWs9FSWarvjzKia7fhfKgFcBSmVNMfPUtxC9.zTvTKBqcwy+LKDanCMe4PqVrOVhoOblnCThFiD0DQbC+Fy4a8X+GMrlG7lWIEnEl0E+OshieXIsJUD7NN4D0cjeo1OlC7tcmOdK383SF5AIavLYlKJ6Appi2.qAqHndA1yqrbVGCC9t.EnaKpr7MxwVeRmG2y.iq1OIwNw4H5rjNYGW7KVGW9C8IlGkpm+LBwJuddi3j..BEzVJ80YVye3AdWH9qhWvRxnd1GxCHff5rzuYycsFEmBDSmdBKXInWJMoe8QWCuqSMyTCC8GZSNeckEh5ChqD3e9adBG9pno18RWpJOJByxOLn5f+QxqzjF.SYXWqZEeZYFCSHbRTEDbnkF7Zl.17VICd810ibgPatz7AvEHgA+7KypyaEH7YdJA2sF5R3j9.ffNuDAxCCwnb7CKpoBmu9haToi+1ClVGMw53r3bX3.3OgcrsRdZWCG0D7tLni6h451EM1OjJm+ZV5To7crdMjZWTLTAqDOOo1Hdu+P21UXZcY7p+lgMvAhhcQmlJagYOEMuT48vFZ6+2d367wgO1FnANC4TZEXT2lKZWgqs9dVyXw08ssn6SsP+Z8zRInofFAruL1SeOnOnjvRvfuh4PNRQ7BV7eTy6sSdtnWnIgrzDZU0676k+UbmuOHvQuP.SNNN92Tp2whiXylqnz5ekXq2SC..PTLLVVLBGnpYMcMojnDX5d898GIkpXJ7vchvGb7KWWJrHjKUlmuDVooYnBwPpNncqpieLa6RuVx9Pf3TCWykMaVk.vDohlw86Y+Y4yKHrC2OdD2QcAr7utAuMuEdIrCw7USP8KsdAvT7LmHsUj3g7KInN68mEOTE4zPdZpXtsOlbfomhi4oeFuvqcWR4Ihab3jouLvXvaYpwPrJAdU0unl43JI+7ce05McLhVBmfjNkvcCMTcaN8v7WNK3pa5DSyFsL5wtkBOFdwizzH2jX7bd1YD+b7LM6b.gHzPoQTpZYo2WqlXINAmxRHIAsOP0FsG3OsLyluSLHEI1+ZMbVQ2dxn+fyR4Omigr8KFvznIXLJvr3xZYAoR+5SM9B.3eJJMYTNb2Gr4hmss5JgxhoLhDkax0MQzN3Y8pxa6A68Y6fvUrQx3ZA9K2eXs83SMVpfPi.PaWu3aK6DAbjLKtt1.svFCyw3+9SwdsjrzoF97.BRHbL02G8DOsOkCLY9KIW5v+5nu0EhhJIcZms082iqVunyIbdpBOfA.6CnD6mqLl0y.rIe9KhTU38dBwFwbpQKhDPq5ATuV5C02MZKfoSkkK6he0H.QiVJza+hT8IVPWSzu90Gl6dfbRodDaq37PTUbwSoe3oR4mkaAWcnm9q.+PqvD0USmda8oJ8M46E9Xu0zb.qmvleBEb6cMnpNFyi2WErYpFv6p6m9eaTJiOvE4KVJYe1VUBsxAbr1xsf2.Rli6XbpcZqhjzlbAJF+AY2VgAd..AyM.OmmDVJxoGbudH5Xmmsked7mD5px0fk1y+sCzggLd3.XUZfGQ4LYahmk6hMQ.9Jd9M4r+yJUQfr2U4nVoJgPfb81IoNox1w8+xnnFJTzc6+xPy9rseycC43TFvYkz9EX7DePh8crW1chKSgWLq.h6GaCci87DmnzO8bjF6YMcIdgj9B1kC2ZoZvW133W5G8VCXXACeq2bJyQkn8SJYsHaHDkycOu5R4t0oCbi.HpNdflYFLaURp+SpCO.S+AXT9XC9AtWY+wp3XvSwRAW9vh7HMn26u4R6nj8qw3Ck7iHwa8vDb4Yf.NvkFASW7hBOeO18aOKxRt4WQNVY3jiCLuGtaYjDJ..fSThNneKYSAUGP8ocQi8lTIaaYQHQa7iGWynBMNqWa1H.EAG3qVk5gdX9OhXAI2jEBcoDNVVLfVH6veqH4mCRkzdswFiJD8Fl8WqWJg57mnu2FMf3Y+9URuGILdBCg0GdWO0smeoSiRsTdi+Id3l46Mp.Bq6qdspQ9QeJUGXj49ZTb9eFVqgghDlxa9qlkhnI2y0SWDPKMvjcB2psZjpLFJhkV7qaPN52gE619yeYAX8AZTsPQlmIvQXanYUJSsrmDrRVOXHL7n1vVXVssvtIb8YapkSq+AdsIwCx7z49l.UzM9nElyx39422HP+QsQs2990Ep9+wD.51wAPYeBRc2VRiWiiAYPzK5.pR.RsqwfjSAfDIewbrBegpvwEtW6.TrMG7PgQYoImUfK7G6MBIrImabiIMDYrfxMFVrg67XFWbpyZ4NMLrU8nEG+Q6c0NM2STth5fZZzbnId+QtSAJrH6Iq6O65CWnncYxXDGm4y3.75nI0UyLFum8zk6g1N4c+.3.pEIfg9BkwJzavqrjQxVVEgC9owcVqTm5nRjyKuqtxDhqWBrPAqLFK0yXO7ug8z9f0bRt+b8Ht.oHqXStOWSHghtMXq7hhZ8rN2ObIXKlHGas7qdpCr6vtA+9l+6YpYr03DbuPrefjB3UqxbYYRb6CUcqr7r8Cxz9tgHFr.qEivhwVXlZFYz4fDal14zSXCF6Dg9pdl1q5SSnrt1QJSE2bAuansGw0ODoMzgS2H66UX6vqlwAHLiULYVXoxGePEsh18V0n8NZo+USRzS5PHbFQbpBsYqUDSiLT4CJKr8y+M77fYVR9k2DQDLOxWwlvURw9.Fx.ZweWDZ7apvWzLywkNeAff+lGxVOgWU6rlFfVqrOpGjRLzl3x1oOjJH1r1cFxbSWnYMazABtKgvFeg3u7S58ThYY6dWCmeitcabV9P3erL5pEMsTcKAOMn+9u0ZNGEoLpOcB7TJVN+m1WSmrCi4Nx5ZKKal30bpHgdjs8EuR5IFpmBinINB075im.aMuZKilOXXOv92G09vPhU5h+fGYd9vij42AdZYhtOtsb+RMhxkic3PRayPX1im6+3F8yJ8rtZK1EFm21KvAvcYVZ9N3XfwuD.XTFFPldKqSIF8IQ1FTA4iLo7RcX7RUoq.pC4UgCIaOnKmzJ0tiw3aXXHm0.4Lgl8owXmkv18EZ1I2gmOocnAefdjK.Entg+h6.r3SlUTp6QaBwX14wPiVArbdXjHZOrlAZ33HrD4ehCsE9vnIZbho7riNtCSN9Qbs80Kab.n.ukk2nmfMnUTBVaGBrOO8DdpGRRAH+FQgDV5V10rsp9uQL8pjw3vmU8jOMHP1w0F4nJfFr.wuTB27nEKmlSyCI4.ddRSBuaUcrbyteW4D6gUgqxMdVKXSLB3+8LbSODap6MXNZhFxUNpuoFu41PujyrugQtdlHlljA1irY7JGIglEVExlOEg3oYrxHTeQqw59YIeg8WcYqVcJA90hzYJ38TMJPppg2RczDBtiNOzR1AGbl1H60+zDFJ.eH2ZAJvQOpaUj5bama0971wKb9cdD5EpEojJuAgX34tnWycPI71Ptj6Rf8S8eDH0iYLTTo3r9FwHoS7+VSBBWhuhrrVPmhxsB52Ljp8BMslaKToBPPGz+KvQJERqczTFmkWNNMX93DL8po1ZArecnfcB.sL66CN6T.wZ7kHfYT9Wd0Dj09fSBhnyJUplJfMeO7Az78GF.BkLch.LoiYeZr6AFlQwolmzXbyJ6Up+u58r84AQZr6hZfjawaca9B48bH5sUjv7bRoXsGu9Pb1OCmtD4Y0CBr5WFaOh3QhRNozlzANU39veDLVrzucglUzmbyziGOakJbZhftETTraiv6bBABpoPKcgmBaFKbXZ3rdACNIBy6JaJ9GuQ0+DB8aZ4aIfHjoyrgOkm8XDCDbROUytWe8bbR+w9lkHHzQpWnLybOyM5fMbwRjslhlponbwlfTyYWgHOQDmHonJWtVDmtSt80iEqUaSHcouAa0ZUDSO+N.iviGGRn3obYZWNjvndJTyotmszBkZJyDxjK7CyfsaSosaMBFXeyQY0bfOwsUiUr1+Vrko+KqlnvindNUzXnTE4eUVKGT0Z7NQ9fOGYgBQ5Hw38jm6D.HptkHpwZ6FJLOI1xkXGcS1S9KmHa0ETckUFDxv4YNW+GwhuAuLV85OP1d4zxdGTsw3B3AJdJ8FO6UY9kHCdlQEmB8byAB4NHdR7BAWi+GV0sE.MODI6QisylK5ZWmFzVC4NhbOHC2AIU5BDH8EUHANw6VxoTAIzMcd3YOkl2nCDeaeGkv1qOegEoyz27i.SpQ2YMgVQHCoOMftORW+PmIlnhqqt7l39iXK8rzzaios5UwBWa.l+Calw.tkSgSMfEVcfcn96LyYI2NbqzCdso7S1fE6ta8h55klODiUmF5OwiURv5tECpa6mIVE6Zb+E0DHIkLtqYq3jWaKf7ZlLtq0h9WhUx44PXerKXAOwQhoWycOR6Ffyfvk6sFjLF+KM.w4ZHEMaBSTOCWyKzKuH0Xw71ZXgzABwvbJlJZL5qRJVVZIymPX3rBjNTLIC9uiV6JgG0gGEH0.LxCI2KTCM5+lg2ZDsHjY6G6OgDqwZnBTUInY+.PpBAWYYG.GVJTyzaEIxfCm1ShtY8a3iO0bR8udU6yV3JDUptxuwrgujXREDCH41URSPiHfcB2ReLqA+aMZvCenIGL+D0io8fDBdbamDA1g.nHL3I4iV+vGt4kqfilwCbWpfcXKVl2V5hiYweGFkzf.Fqnl8CrZTOqN3XUjzEZxblvt5hjVcSn4FPZJ86VbG+4qqHHFf4BQvk+aok.sypbysoRE2TewTpZnyNvJb53NK5QncE03r+WpjICWUAzGuTPeIxNE1Z1Cx4P1JxQEJXMUDdAJSdT8y3JN.aXm6WfYQm1PVVaVOs5tWeGG+SjyzjY8o07JK7vnoL.BraxG5Rjj30Dd6EUTbn+tnG+SBEVwYLuKS4Oi45jktYsd6ZFIjcJkA.SIuvG825ByrsyO7klLcb.z7PHUMBFgJegF0UgCnbgkZoeei+Sm+C9reNrxIpRJn9eYrtwgcJ7dsAQaVnpypbm6sSXbXOMjUXeVME6jIUvuk7SsIo+AfM0p2P7PNF2KB8VGSEwaioHGihQdLtT8p1zig.OK5M+ap5JISSHKm4KoOdRpeZ6ipzD3fzbP5.u+XotWYw1kDXMMcWPKTRhz+unNyWDpoY9BAtPmm9YgCFz9De1SaPLUBOfyJP2ybKtRR2AbJLZn+VY4j4VQpLtHxyBEik0M1DJXfUEoVu+zSDtaOEIkeuuPONqQN1PmN45C1wY9q3.7D6uiToonrdDW0B2I36RogUuvFwkcrlLGa+S9iMvm35URUobAU9WpXPzfLV6WWzVIZYJ9NeS.dtC7bzZ24PUIXoLPwNYyJiQjJfkQjy5py.jSXNud.CagfRWo8XHISic76Z7kzf5ARJNavfNe710jlIGHJduM7A36nhqYmBBCKDXWwWVN+FcZHfhPJvfMgPtlQnJTqRMceArHZhLNBs5Y8a2EYOXs31j6NJd.H7UWRreknSXRFlaww5jPHT8EeJ+0HPAAmsd7iHU.FL4GQlivtV19DRLIuOXeWCMVylXABVY0hKFmFVCGXUfowcASdEG6Ao01iUH52EmnkQfzCSz5utF9RhdCDY8lmsGBdQTIc7J1qiWQf.TPN2JT7jt+WkC967pOBWKWG3kA.KkZG8MBMdR6TgJZAz4rYHCeJ2Gj36NUV4hhqRGekCENHpX5PyNm4ElEVPf0zPr+domYIObzht1bTD2wBsMRKgp4qMPXFWEYmOzlZmpQbHriqfJF0blr9ubmh6e.aZ5ePrV8n2.uTTAwR1s6+yyZ3aFKdkqLHIIaKrX1m0Upo3z+8++NWFT8SrtQ0xX9+659aVnEHuaKvEZlWnpVEJinoGXyC9HZii5tvTEcOiAwUCOadBl7gz6c6mPMzr4jx+xlYSsqAVUn2aOlWi8IrwalX9nhggcASPM7B8azN4XVIJHdk1kv1pEmjV6rIz08KHE1gzWLPOLGmkqx6zytQCirs4OstXD.HaryC7l1u69aCqe3i84Xff6pI93f4niGkMT5rdFqRt9EeI8.WBy3YWvlZBB3pbe+e4fSyj3r9OzCovDyPubiTdl5P.4M4tuLIootB.8bGz7b5hiyUfKIORORXy+.nqIeGEjtEo7mFaSO7Ercz5x40nbagmlXq88bWg4dBbv948o46j29qWCT4mdMOKo.dhzhaIYVLgqY8819wAX8dnVvBPXJCgFovvfEbU.A3c0uV1Xn0ImD9AsA.l80KeHWXe0TeLtP3ztCPmH4qEOfh1lYmtG4YrFYSGMHvnrIfRrEm5IJ3evDiFgvQ.uJVmAsYJtMf6Asqwd9mm9z1UtfAKlZ4hWewcBo7hosIsd1aP1mHApoT.tutagVBmZfB4QC9XKe75zIqL37X2iRyGLmVJwfy6cssRPGT3nOeVUVWJwYahqyxh.zYXdQoun0m28rx8VDyIiG06bkjzQtx56QOBDULs9Hhiy7TfNmX1G1QCo.IAsVD3K+ebpkOrWMXt8Pa2I2AU8U+L9I73rEV45Xz5YOAgPoNPgfynNmaAmLx2bHbpxas4h5GkOP6xa+BeNLM8ROnrYVwE6UdHK3veHor.iQiGKhTNhUP8o+MnUEgAFyOmDJrVo2gutFvL82jepUlVyHvKgcOoKxhPLq3zyJzEvVtPvVBnot3zSdyZumBxeL+VIrp43DFYR.VbaEHxAo3fxJe2zO5USy4pCEDq7L8221HoHhnTKvNx7vnJDkequwMWzZirum64GNYe1hoSZJlW9SCr5r3FkqKm1Pr.AdUEz5zlZpF6tJvNSixbOZAIRrzUtRjaHadNHJxZcLVAX.vKqu9xaJDtzHLo4aY2iezq+6L9AFEKxp3iD.ODXZnXDcMmTVB.2C5u5G2wprNR+xblK4YijEKbPdG1afb7.YE.i+5Vj2yevDK6cp7IHIhseptXb8YRftY7dXZpsmlfSKKhvVph3K5mtY+uZFcdKy2GBWKZ3WpEUqYWaHbs4PS90mHvsjmhK3KOIHHQDWWB8ujT7wFQm47F38zAUoaj9OPj+3MsWCSeQ+mGnALUzC6qjN58Y.3XYCbs+ulyK+sUx.uB5XAn.rU2kaqau5JvWmTl2dr6D3xeUQFtfDb6OyUCfjqKQf58xatMuIR2uikefbJcfGk3LkqChANFJyujVjsRYG9a0ouOQFTFlDfK50.zb4pFBDFlZQugpUlZIqD5h+gvlLkLFGpQZ3hL4EVZUmSDb51kzrYeob251DOke+CrGELwLLyKvfZ77rAuN2hvRbtNwCSpZlmGSKAIv4IbqJ505H7o3+QVk0WWjjeyJuYN9p.t+YFo.xQL2xMBZKsdYzwp2MZwbxPc4av8kx5KYtJZwzy+yMqfbKC81X94ShKyiiAXrBQ69RuwclmeYgrUxYQRnoR.yttugJ0rtxasg+MV47oYKFNgXqubfYTm48qBqQbo0edzVz6ohvPz3P1Mxd5q2eDM+Pnedrwc8EFWdjj1tHM6J13uC1joIA4.RBoTwVPfZMp1fZuXZ1mxw8EG3ymid.hlMgo1s01Zjcyqn2D3jMZdt9pYXc2COAXG3A0zVQX6K8l4c6aRudCX+owSPM7VrmtLTN64.Jx1FnspBKHiCXdisl93lDMZ14a25Zt8izSJ.vixCfypsZkgsh7PKhC0PWF5Tq46ktvizbfrmxOXY582rMCpBVmixCU1bggdrzjhJ.b17q35w+EIs.cq1aDll5WIsU0VoM+109hf1I86+kNaSgjp+80nyOSFvxUI9wuj4Nkm.lmmAjAF98m6+CGCMz3YgnatsNmZPgjFW8RLXIAgg8MPD.QzwSBP3xJlqBEYR9OI7n.hnjyhJjfMI0vOZptE0e5eCwByGUcInNamEHCMK1LDfNxKSmneFAMKeg9QMnOGw0k4H2MStqHzW6biMhgk1JkGb1MbRgw7T9Bl8EBuEdYqtWKt.oWK6.wY6T8m4W92cAKFY2ZB+zcg4Fk40CsgE5h7fNj3z3L3jAdd1JkiDt+DQNESJnfrS0Q38iq29+isv8P2fUC5WGbnPgGLDrBSQeJvCQYZBn2HG.jj7uPF2fOgsT+6UX1i33LkzwOMTEJ2DW1cDe6AUKVwrY0Q7P0pfnMZDpNVK1y6k5MZRWkAWJRvxii2mzsd93sl48iDDVmauCl5L4rCsr9ZJi5LjQsPm70ceVyJV5KnhFO.BXOvIlpxIObsQWuwrbQ.tPjya9FB2rud4b5oh1xwpyCBWY+H61xsepC5Da5F6.he3.HCWaROKOhmWOc9Xlu7kDRAsouZI.TXGnGvIzQ4fLmAo8olHJho+r9.39pDnC5Hlwr6OQi1x1+LlxVViH0V4gijytzzAEB8etaws0s7iaZO6orMENJZFNnp.042CeSYcVo3BPKGInkEIzCzq1Dlfexhp5L0Vllfub1RzzATgfDaaGnJhlBTe.2r1KRBSNsFXOO03eoxx2ANr9l8e2q6gm6HbDCdrEqcYnUoaNhcFvIJBcg8bItYlV2rOMIodva9KOX3oaN.59wP6aEXtsG4T7Y4xd5AVa5L.d+2CDWJArq7iIpO3VY70QTmvLTM520Gi.f.+6iSh49n6WJwngRwaoKg56sc2mvObEjHgqrXjkDYuVsxvt.CJewosRi9wx9hNyNsTw+.sonWouHiRRQbuJRlOnYzYAOiaLsU5oW70dfJ4VVYB3KbyxNg0Hgxkk0YbBad1QpzJOauW87jsMmAWtcseqnBm8v93wpgO9ASbUYKfSlMH.P9EM+frwkYbZAKVvpMXsVUUjSHSQRSe+sGxv8nemZdG4UZuR7pOEFUoUjcNkH5j.uR+hHJcbdvlGr8cvw4.3NsKAsmltNLboQzB6xWhwN4DAlCHxKKG+YPeCrIZR6S6ETMzBAXUtmdM.zCxYSn2zcgXDkuCzXh1zVuKrPQygOvIt.f6GWQneLYovGrTB4KTw8DtF3DAcIVGuY+vzs5UuE1uUs6fInfOJQ5wCv3IO6gSFD1hle0WesDM8l3O6IIHn9ljd29OjcnuIS47Ee+P7M6J6SptCErC96Tep3v5xINC7iGShqzdjwpA9FLdbfcHWbXDizNFJxHIxKqPRujLeHnBMW1w9T8Cg2O2owkWdFpt1DCQP2ZfqmB4awFjkp28xfvAywkxzAa+n8gSKMWIEMPjlLh5+h+5kTC9ZUVQDPdy96sYAkp+VClGTawD+aQ3bFyrrFmYlU0Wqu0d9qJxDlTVyWpo8S8Xz2w8uOVoLWINHnZmY5mYNdHTd8JPYCLtwiRZ8eONJDDcXCREDRTbPc5hhK8W0FANML5nyNFshmlq7Rvqh3HwCziT5WlN6NgOu0fWgibV.UMYxkCkwJSomR2rj6Z2u4y1VSVf8G2jQ3P3fhhHMBT7eIG40r55R0fyWm5VbBL0GtBckDKt6YCz.uzk5GhTP5TNFIDP+TpQswt6KjUm.xxEfE86IGZixgNEP57NGo9VmG62D6rQ49bKYe4Voil1Difvl18YoQZv+exMmX1DasHQ+9AqMSG.swxFTFsI3JNmJQsLraAktketq7UAU2+YB0AlyYMAMq5H4RsjGLgT022Jz+8EPr+7aNT.4yAyeerss1up.pM7exuzpxbx9zBknf+e7OUQQPVz4CnfprgBbixyqB+lnlBcqKCWRVqV7L31sJU08z0DEPv7M70mS3yy85hsvan8OoA4in6ZRI.mFPHz33MQSKv6qjT2qoa2hWzjz9uNUQtN32GjkwNp3or81Ap76PQzdaQnVfr4di7cnKLC53E1P0whNX2TLZdnO.Q4CuwzoR32WrUehV4yeSb69xhAsSad0rCZpKSpbSylnrx8TmT8cdObEhu4lJDa35UQmao8Ui6deV6LN+KLQO1tuurFX0VMazHYqfXaqPH7WiJkWPhuG4f4b3BMow8t0LAHfBvE4QwEH1Nhol1GS1AW3r37ioYRYdo7xKe0a4b.UIqeKIXGm+rouIxmaLEwjFx2FS4dwki55Thzmfd+kcoF0r2XD538ooc2bgnG1g8XxXP8TH1pIW+cHUzEtq1Xv53+FcYasXJXw2oabXea8qqf7SXwTLYU18CDfIdnj+u3OWJlEAEj2pXhCn.vcaZ1TIR.mEQ.Hk194OT0EqlHaWkNAfkyxEyqKJ5KYMdAmDOnLyy1obT50b.cqNRsGexnQ35RaQq74ZdD.X5BfPSlwgT.sWqcxINwWr.Kv8o9hqeoo.KIXRDxHyc+1HyUSLJIU6s3puSMfr9u7YUXtA1FvTZYFCLtKLSO.Qk04IIwuRpoCDp9HVwv0aj.Zq60L9mTPFaxjrvvIndWVbT7HobDJ0HFj+1dXLESJyapH.C3qUmoDIeZDGBjeqc5WUnEKX45vppaJVj+Cdv.ywXT0A89A+YHlOCWALpPl9hRiIBXmU3ku1neF7UHDDJDB86OrOf5dBwp08HpAuDjXKS2axWhR3IYub8k2+qFvxCKOvtRTwu848eSnET0j1dFdf0vXeA4Sbt.cBhRSiqcBNsjeOfRVDMAkIPjXPDpVe0Fij35BuZh5QgpFWxc0DYJYOTV1czBDeG+rKKBTffP35pEU7iOd0E7fXH2V3jqnAXHipD+w52sPILvkBP+N.yFal25Rgw45CsjZyXBiMxOGTLqkt84EuYlYlnroet4k+kpKQqBJxl5KuGKp9ADNFVkeFTbg.T34eUzrehCiY0.i+C6T0K7umSqNScnsDAUrjNVBOCM903XommMLYFYuVVY0f.tFXOAa+i7SIJETZnDJK11NzjUxi57IIvmZgGYQjTKu0Hxn1TTbv4n9RKQdimnqso3vgiPTXJWYcLl+EMX7fgjwaT2J5SVYDHYati.jFgcZARuRlO8rXT.zQx3Pww+wHA.Oi9I7pg160NB82vkMGdc8.jYXT.318ZwYxvAY.PIKB8jHFc0yNx6+g+.lfTI0quEGWn4zUs5Wnznc13D1NJ4bMbbCWZmYwVid2wwCMZHNHimXkNlvseX5HT1dydSfYF6mpELnB2FosOciXFlSNIvFAmij1Vh0AVrBV111F.+owuAoUGx6MQI+hL+INAkW61oKhFBbFzrXDN8UxocV0GiAF1ULyOxdPrbOuzluwceMsz8C87BA3dhdWu5m8703kKG37H8lngvVy5jB5kP1jdqyJ6QRD1vmUcdi0gHZ3e3J4HDS1C9ofsKWw8C7FHAVLWDevCgdfCkRuNWR45Y0l6n4Hr+kks4j9IRmKaYsFtsr6jQOaO9zciEUFF358Mi0TRikHyyDt7EmyhNXjOsU1HjW62X+iZysz1fKiMB2V+ABdo.KEfxOplBBEU3qeNHkWhAydRTWzS4XMojsNVHFfzyVGp3r9rKPVinBJ7SKGGRUauqbmoOl1sxOdZ25TIeFdMoeWqs6YGNMlpL2HyQKhIHhJcLChCrSliMrK2QLKyX7zBBgJNZeJ6YgRZ+Av5wrhSKNBbGyAzadXV6ORnqKE4coKyKTVQPPM3pS5MmqwTweiJzcpoMYSdPyWdPjJV8hph85VZ3UUjIgBzNnYLH31PpWFUgXTBc.pRX..fw2ZQAH5SYsk9Lp8Bj6VJJWO7JLvOAbj3xiW22SOz2UWJtkw.ezuvYlOZqMl.Sz7r2fA9zDGyj95swPAqcboNwlNHK+8ENKvwtlZc8nuTnFaPGZezrsRdLiErbN9RnnLqkEPmT0gfeR+d+o1wsbjIW+jz0rJ54VmbGwDiJo3O7ExZvI60KmPCkI7Ayu.RxNd.IrqWfonFDiNWgafA2So6RkzhKCbahMaqB186dfEFNilVS.XUniTHvfC.YEKtlJPz2y5QWQxONeR+Fax1028ukjmHjqgvmYFTiGjEyoIaWj4SdMQGCF76nW8CByBI94CRhT5nKnb4OyeNgaMgliPjvf0PexMegG0M7PWkzT6aVTu0.eGvRshdS7Vlagh7DQ9QrfIe202Qe5pbwBfZlIgBq8VQ6eyY7oD7DTxG.Pph1bjhzblM1Um8ZPhp2meb1ifCkadw7DkhO.qIkI1HiQLKWP7LSkw1ex6hzox.CYB3PjCKyZscn5sEGQka0xEJbkpisPelBiqOrMF51W2SxObB3bR9aCR8VkeP7yx7+CXFLueDcqALtdvVC3lqjr3uWB4ntX9T1SD5hRs5c58+a4qLvmhuIzRU.A0kvX7SoyytAD+RZ3H3u+wcWBGsgz+ZB1A8KALDW2TJnlKYRVUCG.MzByli9lY1Fn46SgeFQAJ6JuQWj0fblANJT+Gl7S4cyg7EE5KvGSTv4Uaa2wo+Z2rAv5N7iC.dlblV8OoFaxJzpETHFuD7xFKXC+cVs4WCK7ia.01wgw9npzOyxORfX8HqeQnRZC3VNPY40zjQoQ.YoUNMy0tbObp6LJTLRW09rlClHXtiVjCKFk8HTtNtFPT9B1ZC7gR3lMsjF9jxJ7dHgTEUkYhRRsh+G.H+Ot6Ecc3oP4rpJJnxEzxI3nIekLUa.JyrpjvL8SUPqWppnc31UplVRmETAnfK9+TFqrMmTsG+WRKjG8wHqvQkFzT30lPA1bdP1Q+cqYamNEI.+y77T.UYV8FHP6x.1B43LX5O55.mn5V9cLBTzaKay7j1wACP39DrElVx80T3h.3pOnBxZrXkdkN9uXtoL.pTWoqiwD9Dhk3MlblKJuNyERG15s.KCxyi6XZptrlmN8YVllTiVt0tYt1q19tjzAvkbJop+F.AJpdDNQy4imI3Y2rVQiGvApmaY22UugJstAmk9EvxabCo+R5Et9XrRk3yt17LgeLu9zfKaXmTkPav23C2u5mJ6q8176EVfRLiEqGqT4euBK3P+HmifCJmUk9ASoxM1tjSzMZhcDMwqDY0SywTJXRhy9ftk.WYNGeatg68F6slGu3osQv9fi301aH2jFuLpNK2mzHQS8zAUSk+0toaDZI1TFaOXZpfdXbnVs0Nyng2KvwQ09BLvZwIlHJWx0aR5J8bc9Ken9oHL8W00ldg.qMRK4H.0sMF608fC2CkxepQWua+pXj8bwKmBYPWDVR6hcof1Dyh1EHnDS9I6v+3a2pEOeShz94T4IPkPFh0MAtLUO0iwuwC79gkW6dIWSXJYRlOBfgW3+VFVfYHwqER3mQk9bl7.4j52C3hnPbX8Tcxei+IYJhvHcVMWpYyO4MmlZYR87uEKbdZkVDq9ijVE2V5ay9WtmoMEo2pGLy2a2pIuXPm.hKIrZK151+d3ZrexZVe4THp00+Y2qelQ0pHYLl8v4QAvvqrNZ7Ydo8399UXR9RgA89UjvC7Jj3N9sCkLewnT.3FSsPihmFVaW6A356.U28wFVfK7razAZ4n3pMVOD3vwrLUW3N8MfQEN3KcnU2kCP2x8YncYi+mOBvdDy1xW4lNEldgbdVSDdYcfnWR6cHU1gobcmcF0jFf3m4dKzZhS2UNXcOC1EpFI+tVl5rwFQ1Ejju+Z3JbCcgGqJk16hG7ggeHlrSNuyeKYrXO6pq5lx+Kl04S4EEQ5mG9VljLkOSboPj75CGfFuPcG7o.59TsRKOqdy6NJmDJQpHon2fYKE8Iy+vSPF2FM121RgaMjdnF0H0VQ8eIsuP00GHz9EkdG9Hpa420ut5thd8TVqC3fyZFsijfRFgADiCQ8cwoP0WfIRFjyh3Ufbt646167tGY5w4vOzqzaxaSe.8y1FW3gBa1kIdd6rAeIVzYPCwJrSDyxnzEt+ibk+8C1IJZeIRyjwxv3G8YaKEQzah2XSd671td20IKFjlm1fPIRfBYMWh5fBijrFPl4GrAe9MoG7kFIovO9xvDL4E.EcKaSw0HRqyyLBScn62vqWOfxkz8ICxLI612adwme9+uVSiEKs2psEqgMUYySNQN1MG+KhAAePbNJQaPUrN8vERBVcsj154FtmSb.XFQWblzXrlX+THc4iVqUakrkFn7pQOPldPLRSyX2Rk6ozYtR8J0f8DKptjx4yQqrgfWVa6knv5tvm+km8D4ANhkYp1tZPs6kuy5uHasQIwLBlZZaHmZ.F4IwMi1HINnl.r9JjJ6cyUOizFHm7h3VVZcMaUxen5r1TdxPKuT4hYV0GwTA.7TAeEGzfqThtUNoaDVq4ylPU5HKkwXxsiHjzfMsq5yAYHUjnuZ7omoyUoeBRSpFrDuqIzldAOuZgUHGWc2xKvwmOmrp1DaowYEk84qGjq39TxivXcJJcSe23fKjTxX4LMp.ilaNBzPkI0NBmrsgIH1iL8N08Yi1r3ztcs0vQfI4hYrubKzp3KOwljZXnTtzIrVCh0L+g9dnEj+n4xFwKjNWJrEcMoCekPrC3KIy0qgreQLfFfYL2sldFb.r2dKP+cgfh+frobeXD.szGQF7rmcnVm5f+gFlYyTEOU+E4Kj+Siq5f.jSNm0CEAWgBcpG6u4RvHqpRYhU5jaZ0FxDwdRG1sB.Z9VC6+S4M5RpSMC+BTtykiWRN6GG3E8wViLN71t7sMg.PnNi+wiEYWYifHgaEfDXVU9iUvWa.VVBQT+ND2sY6VAZ5dOZDEfLRE234RfHcLwv87+YmTM52tsuT81Q+E15BNzjrF4ztpEyFSMFTXhw3VpACYlpBfVST1h.OCA4pxrCT3h460NNuGM7K563tJKTKVdJDgr8CftS+4OayzMYwhFK19.8sDn+TDgayVXjpS1+lBA5p27D2KNnvuwPUh213UmhfrKclq5vLGhK4vjzLW+6K3coIsuStRjaSy5vsDq3D4bPKVaBm+QQMiaqDkOUsC+GDpVgi1Uv8NEJlJ1BQGdWQApEG9lTAoR1OQwt1wPKWnKLOfiRsw6mW40X+TRvIwZra70fozLcll0x+Z9a4VUUPRaCRXUxvj7U.lLMQyODc2XgTdw4nOC6i0KAj1dg+KY6jtOnvJraxayTv3vx+s.SIXIYNATijrmNSCzEl9a+lMwJzsdgBX+s.8wwNkw.ZaPYkCiErRwhl9L6uhx1vB5QHp5q3PFXy5pfgkOuSwsWH5sCzfRcp8ZDVXzTgC0+fq8oYoONbTdSyzquOCNk2giLfWR9AyE6DnLaZowAlqoXnJ74usN9JtNZsvMKSj+QOX9R5dOjEGqfqaGovrlt1lIqb7yDtwvEwViuH0EEPXbfBX0q04rpzAOyHkfiGS.T9BvIBJcsltFf5A3yXaGnQDJYsqWG1bqRVcTtUbK2JmYPCCvLMKPkp4LKnyiMTExa.E+Zdj2WKk5KijSvFvQV7dA33eLJOo5NYeFUkJ3aFT0Px0EMMjlYWqjWmODRkcu6Kd4G11.tI2AGhU6kLzCVPPhVW0Jcnxuhf7vvwdrUx.1XiiX2QXnG8ct01Cxn2BRJOH3.IeSXvul.+nTlJtpGV5GZKZF8FU6jRt.QwpDCQLGGW414eZ.6GzVK6xXNisSszjYg+b9.odFHyH.E3XL.7AwUj7ONcZ+zKirab1WRisSSv1Zd9bGrj7KLoz0v+OLI4J+qrmlwztQpYxARQHcbjoRe9Av7sakUA1g0Tc5aICOXDYYnaK2qia6oqtl3pCmLWpIqALzLuDGxK4ef62f7w9y5Uh0Rfi6Gkt+1fgRLn9XCtKrIHe3Ts5zGV.lbir9RQKCN7qtpTDLFcJhJSgiznpKbf.IkNq2z9SCPcnY1DE9+J7bqrFgAmkKm7VTqN41hAH1oLjlz9zh55aKmCf3fhjdvhxBZtKvFY7GwTV4lgGD+Skgk.OqaZIzQ0yTpaVox70H1svEe94ETckD2yudzV3QO98tK03EErPYPYjtBZiflLr0vAIFVPH61YHiob+LNhNSBZDlSo0v3RusHRay3Q+HDne3DA8q2uUkzz7Ojp6dYQZVEu6r.xpEdAd5nB41xLeyJAceApzZMpYnReBzufptQBZXhLVdT6CO8+D65P2+u3mbHkCpOZwjnLb0fKhfL1oSn+XVfIP.ydFseYIirnFKFKEcPaXs5YF9+LOHh1ii328I+KEWbvdYFwb3Poq2wqkoYcCkj3dFh0n.fr9sqxgxxfOvFDa5CwaeiFYiXil+Ge7vCjlf0OPUgYpuXZ46tU4IGACiOk2P+NvmDSbh5OA+sYuDPkTmrDxpBCwU0WnuIFXztBxn2VobSA3P1ppW4dQN2jOzQFfbER8tGwpOYRZ.kQvbjqOj4XB0iEkJaKSaXRkTyNpMWJ9GLR5gKs+Dl8za2Qpcg0bLDyOAIMC66EAf.oxH7pi6GtQNQgo0z8q8aYL5QiVVf9Tq1DaevteTmTbV0UiAdEw7tTRtmIOBiS24RU3i6VlVJOv3.G.2NQHh0q5znraAe7S8f3HIhG8xwywVae.pPNm1K07uZRYg1uen0QzbcWCcYv7jTF30mSOnKYvF66L6wiUi54zSqYN9VuMW4UDVGSfCJ3eEutXADY6oIGtDvTXrbRHFhjEza85wpFfWc2jXdrNsMZmPoanKjKDGAbXAINza.HQOI6lxO1DTvvlqabgA0FeuWIMeZIJ9RKNf6.JMTy1v5vdvHk6EOLcp4NcU78P7XUdywwqFSWwR7AsEGSvVaEF3883zpIG.imhzBn2nuMJxkIPciG1yWygo5AGfK0PiFaC7YA2YzFzMfX8emgKIb0GpSuqRek8SfnoRI6emd5aIL0VGeHdqAI8q7HKsPSJc5Gl4hhoXMxdKU0buxGyC79j8GKBM6jnWRlUEq3z3QIscq9RzRwMgT5+369BNLbP3FF1fyC.5imfpVh5S2zvDFHluNSjcKTVBmLnyiD31tSqHMg.Fh6A68FEkopEkcnlhP+oSXFf.0T1kK7po3qUeQVNr+hlF1NYuuOqsLqmbSXdnRgmf0XGsVydOc6ur1cqB+kuYyaJaP6nZ.Tasw0XySjofWb2JRFoJVcuBzue9Ju+Po7ygcAch.9.RNSgeBrMlJCRH.j.l2Sox5xlYZSKUZhXDGojAGDOX9OO+XLsFizBPCQ0RdgX9nCq39gvYfi8WbqHK1XoXT7+5X8zH0+Z1jRyuMxmlyKKh.F889K0WTlVIZygufNu3cDOxaG2sRJrvrtPgSTtnTdwFe.EFBKcqOfY3L2rcO3.dl4HQk2qRGeBiFLvgOiMffAYohRovgh41JafH57vkD.DDxcVZmczuB3xkW7B5+r5uR9jqyJqHOaLehHqjBY0q3mdiT9RXkCYsxlFNgTAGWhQ9WcA.bgh6iarkII9oO8kXG9+NiWiN0Xe68fiFVRg1LFK7YYw7Fs39F4Ro2Yly6+zuPFCHrnIJFMbe5sq4KqOqBZqPJLKKWfd9KTJOd+dUb+qEiqU6+DPq4U.q5kqoEHjVi1vb3gG+4fwItVta6sjxMw.jBNLdYpHY90YjNp7ODbp2Z4Gkjpv24rI0uWjAh15rlm3j4wP3aytYDSGa29SJUV.tvcnrHRQQXbvqqxT8uZ2XPW4IdEu6OR6FA.JMa1Gut.+J3WKO+voqbIT1t.H.6lcFSygzEDBsn+LVvZjf5OJLRU4nd18PJxFW904ZhQnljaeueCl88LBDaVtgJR3O0+vAwz3iegkXZcd1ab+3WA5TXunl+.d88TWNhkJj0dqlaYnYid5OruJZpHMLttm5AWH26iVHfdj3sHzDC14GIgvDy+DYJMTLmvgVFWKPRmoQ25ZQTVMGyL0G0u+FjWjZsM4DJmgV+3yASMN86nT2vITo5WdIMAhgh3otFAb.5V650HfGY41WN9I6igxVyVkrRrTpssUKdcO5tSUcO1g2IPXLgNN9gRokob.DgwvtIVhZGorOb0XMBgxKGQBXFyFA7UY4d2XTxnU2LdX7+L8n7Yc5LZAAronY1jSHiwVJGWHacQ6dDDu84+mu+E7J4ylepDqo.ywY618xOS8Cu4mL2OpZFNZV8+OEHOJlUeCHn1hneeL5MwpmzUWWkm+EFY7ffxJHqMyHOsQwbdZ65KBpFm6AMPHfr+SHG2HKKLdLetYEg0TRZAQrSyqrUa7QUWe5mjHlQKQJejkihTE490uG8CRExlum9cnFmBGBVeSbdsWwZWnJ0A2LIWgYlh3rdk.QXYVxkA4VueGcyJSVJW6XIpTzvZZR52.w4GIXA0x6U5REi+B7kiIi0JYNNCOU6m2VLxM3cLs9.0RWTTpSLc9gJ5mpL0jX9AwPAc3C+wfzSqB63fewqqsFWifEu0OoDT9WIRj2TqAELEqxSnyPOOtDSpfAewLsXsGspyf.0L.ND32UtKWSBMbmx.kQQb6Dk1edUtGXaXM+9Uc.AMlcu4dvRedJr1yol+s+nA.8MjbFJopJladnS4TncLHOwQA2AokBrmqn0P3Lt0ih1X6xHkhxtGWUycGlX1SDVCqL8TVZT7SugXd9iVnHs2H4YRY25++sjXL1lgH9pmkYFooCqrdHVOx2TVBBK1HsSmtSpFcggz+DFQLnrSQUuvR26g4BKj57Ftq18Ye3vR3iQIsvTDKmDzsGSiI5r06Ahrv6cB6R3B7l1enOIrY+7g4gSiY07SY6DZ92jSWBPyssL9RXUJxO0UtidltvZP3m5Jc8kbY6vHKdnMS1ffJN8VwdKhgWFsjz1ups022aSSnCSpC.2CModFdiRD20vSjr+UmnkU1rMcjbAWtC+josGcOnJRa7Md3o32Qt0YMxOSKQet9eCDR2RWaj4A6EDSN43lAkSsNp50wx..RECYx+GwuNzSEsRBhwXcJGiEeyGvPclJiq2uNhGrDsoLa72s5NOQxo2ApjE01BhEnpC5t6nRQSq0nl12xrC0r3rJ4ZMcWRxq0mgn189+.OYkm7GmKFp+cGoO6W9pBEzOhYCP6R20HYXMeK.NXHzpXNlVoHoR4bnoBWdbTFdLU7j9bmq6.e+xKqGKBTbj6Fi6a+eIyGJIAgZZLPhQdORud3.mDlc7hXR47PY2xtu4yN75ajL0UEdm8TMBseuwa.p6UvWZ2VtfKezwOTnWveTN8rMR.nuTA63d+mKiKCgoxEYEHaFI2Ce3xWp70SKw9OuYLnQqdv8kZSZe14u6.2+Km7vCM208s669IE8uX5bcGW3agMrVFPIGfAY9oS2qpA+f0t1UJPcRvZF22.LXE5gxfKoO4R485KA7f2qIsgnRqWI5EOa3O7tG3gl722tQxIAXrmpkW210xWtdO+rzyuJ07wsh9AHRzKBUHgppvceeHNvcst9myhsfwAv05gJ3YfPokiqXY82aOBH84NQDfECgBi2k+eUx+uQ0P3FcnkVF3bhAIxK8rha76rAFZ1z6nRPNz7eBm3O86RWPG27zlHJTyY5wgNgsJqqpHPQ.FhENwGe1dPCBU5hCwl.fDXgbfmlAw4iqbhWi9bMPeUqB8.+mg6X.AAt6jQZVllwmUtWhfBw43O+DWl7kwnbwdKJZq7KRCKbAhm4sUL8TduQ.rDDCOEibZNYRYbSmH5iC1Zo+mfn7.wtMR6y4vqQZ2S0iRQ97Vnr6g.JSenVQ1tSlPzjsmeeDDoPohFKA5t1UqrJZhG+Mrr1GlVqlvyjaE2wk1sPHj.k3EEjV94s7mBJY4cK+es3.xlCw3CFrVBldd1N+Vkq3Ya4z0o8G3kLDIhp+wa4P+OJaVfVY0GKztase89rSkGIF5sOW6jaZozfGXL4CPmFHqhVKl8Uq6pDRJie69HCya31y+6kUjWvKVB+ZKU8XQs4RDeoMli6R4C+XnrSPB9ypyqovv+3kkkVDpcKZgwkVUjwAaCAMkDyW9.OcMICtEkM5PtbJwsycCD0J9ukgrdNq532VgGNxuBrvc3nyJOfnigrMBNIMNJaFWah+0YqbZjWBWRokRryMkU4Y0gD2qT8qlnYvmfohYDBdvN+K16ovTyHSKQ00zvuFfrRlQH.ZOm9mDanhQ2XXeeXD1jnZQs86YADQgOH7QC6Hg5gdktUZ7xkE6iHFv1ba5gLjBcbrhfWAFKAZHAUWSl7ZwYmMBPK11phlyuX1YAt0SPfE1n5VWN6TF.MO1RWZsnYWbEpuFKM9XMf0RK3UtL9zqLTXUNOzgLKWTgKXSKwEmjtIwbrNMR3zRy7fZUyG2ikbxd0ljWhahs6Sa7UXUeU0D4koCdpfk18m+ZjWM2GbYXh2N6f7Nbu0.CyHrnkt0cdsC7CyXUv3pGJV3s5pfNpFsI+1bG3XPsfkFKOrTgeFIKHrKYMHY20DLgQoElqW9WT0xjbrvkrKLMe+IQqf7vLbvOCfSaSlUirAMGBcN9nvYcvJjOVRcOzgARNt5vzqcTPuD+z15LI4rTkWuegWBxL17mcYY+E9.NWp+dUfXSCQ5Tk5tG6YDeanF8Fev5a4vPkxDxTiiY0XC230IvS6.g4OsF7jUDN9EVlT394.Yt..+pwr.imkrEcrvUdieszFXdbbRK8wq3DWu+oJ5OqA7GlS5r0M8mxMiVuo+nleq5o4PBNaS6BVikdibvuebe4iQ8f1BwF+8Pd2F7MY5yy6evA0rut.qsCavp8kj0Ru3DhaLKY+LAQvhQF663ofC5osVhScr6ZvVUukZpQS48ViB6dz49QmXzk788uD.AtSa4j9kGRXLr75eAQYO4GxUiu3L0XV4U7VbTUUXNe+WjslBUCttl7mlA7lk1ozLhpcFnlxegPlgPi8JCUKA9ySQcEoL9Qrh7QWBKHIIT2LP55DYsmM8JGeTzJGYzDx6PiI7D86ZMJ830CQurzZ+B8qeW+++R3vX02GFTHWYJpV.a0ZGmbpPEZTELf1z8YCHOD69.NHBHHBtPTfeuNQMm6pn8o9lyz9t4Q0n6EezZei71LfgFLI99pSlPsLyfGO2jTkveJQA.i3RuDX.u007tKCAMeYsk6kBSHBinPidVFmjC9THD..+FSBVpbk+sgmV.ANVaeV47TcTyEc9VqH4Dr6zG1CRiyVgmPNXdDiBipVRD2Z8GmLYcXHnE39168.fe22RPQ6ajHyM0lSSWc+.0FbEApDh9GwFF1C+TpbrwUuGxWI8J.GT71KrdgQKyNpoaBKdhxHCIjorzheAa1ENAzmhC86jYhTMoxSRdGHqw61tqvOYRGmanM8fckVBkfyq8ZpIsfuFnQs64+8Kyk385nCkcqnz.UekAmrtKLSP8leKfekHCYRgJ67r3T5pt4Me.CLnlPYTYaNn0SmmWt7QLqkDncnrEg1iWUkXvbsuxbDeLrpLwvh92EPsk49z+wtLvXKDG1bpgPbTpmHneWNw.Xp55KOtxdueY50bslCxFUgHyEEsuFPBrzD8VJ66cCFjMRJ37o1kmjWKisKIMCb4IFONr+VEkGEp+Wg2a87pILYiIKIfh41dpFcbRqLtLk5ydop6431fjYtJ0qQW5Ikz0r8YRGvxDSYLbiTp3Opd.mC4xtSLxCsyKXDhpb4jM3WTRwpWr+X+3iScKs1sqUfyV43VuvAJtARNwzkfAlz+MgcxydCD6a1UPdOU0HRLaJkQduMol3FP50f+PvNMJdcAi+eqBQLbFHtj0UPbDbnFDEnZCNvqLq1JsfHk79fsqlxtrC.HOmkgxED2GFQBoZJdu7hu0vb0fcxxPdkj408HiP0z1v0dr3C+VIcvu1jXC32usI2ECLbwmoi7fvSj32CXwQoSMakzHbX6kSZwgOwa8M+Ire4MYd0FnMhIj0qNgpDHM+NB9BnojutAVuyYv1ivnOBrC2Tp1hM9tIldaFw0LPGLs.KjsaJ9Fyn9J60Go7zi1E97TWR2NMwawAI31Fh8P6lVa12oTCdAqKv.4H8rnjVIdshtDnBynYmjZ4mXO7zf5liHQsEv0J4YXCLILdazcbVGtpRsBrWvquYlb2JURdpPwIRrh.gu5Q8nfg32kgB3WV3enjzgjMjR1AEEpzy+wdqjMvItxGUdnRYDOggYAK2HnvTtgcWJ8Q0osvEZhxhgymyk00rQ3uPfIOIcUvSlRzjoh5LDAVQuxW8tAewONZXoljUA7jf0fvh.WpUrbMWXXbT4gMlerkP4vPgz8NLA6sQfhsIkwcJFQl99A3WunSt648wcfjDE+71X1g9XOJ4891+8KCKdoVUhBDayiYMLXiHa2SwTTiQmGHefseYwJ1guFhvTTlwEAYVRqkGzg4K+eFHDLwx+Y4ekdwHtOkOXRZw81AfoT4QXPPGbFLCKtNMr8.Gkt7.A.M7482.uy4sxerPk0di9h5BEwmsT0uT26Kfh05FqVO45+HPw4PoawLdtoOe5J3pX8bBTp8hCA2oI5VNHMywZX5HfC8+kIhwzOIJP1g753S3Gko0jTUQINZA26qwsFO7uNom8hwMF6oQVZ9rh2n7BVuaO1dciT33f+OVJy3UZrpw2idThWca6rkjingEkCZGosYHZvEoEV2RjFv4IS4eBFli2T9jwXOxAyLIxv3ZXsGKv4lOXczkZSPfRo3nNj.w4LJKfluqscFfEAKOOuCo69b1EDOaulT6yVFbiZT4u7zVWx885Ef2Yy0aRCKWQQv+9hmu2clT+r5OblfdJBORbMGWwzQmd3rcjuPM+8hnyjB6XCzxh3HF1x7Ct3NthIQVjljbmdKIhyhAyA5tPk6SWS4ssRn0+YVmAymxdmF8jH30uqUsGFVho+3LlLdobRyvXuhw6T6XVVWY8msaYIiBdpHAocUcMdl2npLyQLziS+K1k850g2K0iQiIHkvCiQIQd2Ghqhrv83XcbXoUHSImu8+5vkYvbEpnWRL3jVTZ.LeDPnIXGbE5Cfv4DeAF0vrnO2SEaqKPTxINV+RMWS3XTd9awf7J0XmyfJB2MzE0ViFuSa9CGkedn8gL2eVQqU9IWvqjzlsrxqlZKUTCXp62+epGOkfHDfzSAdkOqY1AGX0bZJe8Uwn8XIYHjrr1BbLXzHU2zA8.Ab5EVnQbaBfnVVW4EiQMFnD4.+H0MJM.fqzon+hO.UNSGPPExxfy3WacDCCqd8gTcGBlATqjd96P7y4JqIp3TqyB4lIx9+eMXCPy2hgwKES30P2j2Qe1vQ3JK+GrHXXyqHY4eBjdDCgGL2xIxAHI.ri9gEiE0AHoSVOnpPr8+sc8EGqAqcch0ZoySinRBmAepRJfFzB1v2kq4tcldSwxrRvAj8Dc6d6wNP29G7gdoeAMvyddIvmSi2p199.5Edekq.KlPX5F2H6RjZE6eaOzY1yDbcpc9At0ovBW8DC18onvaxjf0sOgtZFowIz2bRvtGQRhAhpp7nGeJCMvph+9.wuRXeocvr7kNVoou3COpMaJsVEbrNYeV.CzFyg20EJ0RQumq0rCQRJg3WMTp2EY8+fDlj7Bn+LWXMxGukZDb7+HmcaH1BBat1htWdFiUn+QfTBWnqkKnhcEIRC.Fx5CovM+eYz47Jp3LJtGSFQPZCjd88kxLkpU1MxVG64cGAE+5Nv2RzwiohrRtT9APprDR+.y+abWhH+JAgv8a92792tgCOBKVSMYmXcb2G8D+9ZOT+kN0sFFX13Bfb037VVfiJIk0OAU6OEE6.iY6cZerua0AjPkBI5U1ovwGEjI9Y1ME3AeM07yQ0YkUZ5Fc9E5HB1ae55YjWj+Spp.Lj5NXPjE0ItEpeAtaeocX+SVEoZEErB5kZ2LgLuT65PFGIKUQwxYfYEk3P55qCOvPxG2pRJecDJGFZk71sXLSzNyQMEVhI+GwQFboRSeDuJdE7DQlSGEv4BBx1OAQwaCjaXSIATW0pOi9G+Ibv2yHlLuToxy1PoKl80Y99RJIwZqM2KTnXl4P.4cLB4bVlQj5equZfTmdEsKHfaFX+hQjPiZ6mKEnvFhRnMacXWhye1uU.0gfNpA0YUr6STG6d05wsFoQgs6HMWnHICEhLpq3zKNdGZwYETPCu4F28ykrvxMJwrLr1k5NHC524zEHGCGG0gnY4D4XSBl3DQnYa47TauAfABsXn4nQLyN.4U9ZwH+yzBHkqk0WbIK8158bsSqlBJjCAoH8dacOISYCJy0w6mCbzD.HjjgZZOx9AatzDv6lukoqEPGxBjN2ExrC.KMoxyWj8+PlRwmKARCZk0Q1D3X+5MyPP5UTpEyn9B2G6R3E9Zq2CzMUubIujiI7XRZ2Z8oTPrEZCGCPWb19ge21ioZpaRDnmeVukHtA0X2ylNDmkVlFf0PiAptiEjJDe3PW4qf2A.XAdCEGP.+d9XZFs2+Kw.hnLsR0lgN8G6l5jrhN1zS09lJHhgrKNnOtmDbWSYde.lzHpNH9+7LveEy2TpghSIN9xhxbPJc4uXMud87QU4CwHm0I++Bp94ULinlP30vqvdmH7U5aiOUdmUFqZounSqbg21UIoUkcfiSun8ggKvspCGRgn2p.APjCIAecCCv3ri8pmeynbklHGFBWyXkkuMIXTVvadnNZXa.ROl.7OiZHVlZ3mXdBo3axWV7fzZntwONSRxDrjNpTEh8k0QjcoKm1Z85nM3jnKGK4EPV7a6CLoi1eRvmv4OqMXzYgITkKV3IQ4ZMPo4nojVt7uL1Le4MbT3nPOlTYoz6o5mgZiSUDXlkCH49YKY3JfjRS9bZQSTAeckL.JITi1xYnS5yhd5tzHubY4oTnAcRXdDiQfKxCZvN48toobJRSYDz8mvUotS0um+.1GcynoXg.LrRPRCxIYgcmcVsShFoCChicCTteWknMaW4EMu5ZyVSadC1Xe47m6fMCS.dPopgjZjaO4faHFJIaUW8AiVj9kKJLkhIUFOw4m+y0YA0LdJY0NaL8kmusKnlVFfZO1UbFZiM3NpEJUs4.t2EmhMcjJ5rmQbIBxpmx1TqkDv1mFKBPdcUXnbpM.AhVCc2csdxnYGbEeciiX88As+w5uxcDEB0RLyMaVQnIdMwcIiutDuEFWQweYvLenqnjbs7PL.05vGk+4RBRcw5ROLtkDT8SHz8nt1kNlTkFQazNmbvhmiTE.1dZbZgCDr18EPRi06YGWEuTClVfIpGUp0Dvj6wQ6qkXUv4i9RBfjw56PaK.TFB5QEbGNCq+EU67cyIy7FFTBVSmh37U504uChmtxywg9V6tnU4pOGH9Li8e3BJ79OFToP6OuFe5aoBjFlO.Ky90RxTfBABUGbopJ.80IUcn4tfhaHZiD56kAE7Ftq96HJDUpWbqswB20nNSTrvCOJpGyB9UhXfw9e1lVMzbJNfIZD71DeVLDmihdeC+teNA21MNz5utaPO6amDxLc8ZLHcPUTQ6HQ4BMh7ZS30UQQlK4hcrbHxN4DH5JLL99J1hHNaOcgvd3BWJWJbe2hv3yK6E+bxxR+PJlYz2Z5JlPzy9SijLVCY9VWvNMRlagl1uMCrdzLuJNl+dQXSobVX5.0EYbpkUEuUUeUT4BVK5b1Cb3pLGEd+wnduV4un+FP+cfCHedZSbMk4GekglsecCXFJJBEwNdVu95cbdTyoMY+o+bPwPiYW8Rnsgr3fKZ2OHuiUas.SwBCHCZiFZMobzIg0ij.MLPSml0wDRQ9VjKNg7ATEN+fNBn3lbAD6zilHV9WrJLz4s0+EZayPEeaz.IOHtLJcZdCog+zL8L5xBiTan1qsWbngD0l1vifxqAhdjBkFa.7IntNuUmMIwExCSom154OHYtjh7QjG6BiK+iEpZHLw8uWOQJpTyUM2lHbRK0U+z5aNH18w.63YRMAVtNYpg7vSbsCaPPRnWwlsMwRMMrD6.0YtCbnDnUiiZ8eCF6vGf789h.JOvket7miP1xpPL21CqSZmJZKzpEg56fizoMY0BL5vx.hKQxFAe3ChbT2EKgqCjofgQILRyFE50lCpRo.MB6S0a4eGxefC.uw87yEdXhwxGDjvKsuDSfAeofSlhOnM8Uu7a9nNfefd7c+TwLr9mYif6wfP7Qsv30AwXM70+hrIxfsKH0cTWeC9CwVKD6cpg1Fw.iVGwyFMGPTc26.ONZYpNRrcQ0.fAHAZ7HSMPl3Za3AhPYioG4hCIWHW.+NoI0lmZoiQ2ELoSmxZaw9qX9chWmGl+upuFWWUblORJUz9eZ.G.jpwnzPUmom1pnvycQ5Z1vTQLvzyU1c10fYFG05EoFUZLgtzEINjdjal5gBW0S4x+6FJZeuc04M5fRRfCFiNhl.BAUb.mkU5lEbRQUtnCKDWuUgKgeqdX37AKV+O6th6WiNgJiULiNQ.SK1qMic5AJ7ZweHRt2CWKWuWuM0HwQymz75ZJ8MHA2n+sWogJ08L98HW4P+.PjD6Cspn2aHV95EsLvBXJDtP5NO73vOleq10IlyodAdrsXc9evUwSSDvYoVu1rCi9VbIVd0kxTfpduOrOh2Ex0gbmT652D+NdvCntV73nj5.hkbBRbPmpCwy7bgc5SYWa6xT0bjfr1xiubaxd.LxyRMcCmDCZfgogAY6a158zihBePHQbjGmQkr2RYi3MEJ2DjJQQItJjWw2YVQ0QhFefUA2hpCE4C8st9PadJA+TyXH5SutU62SNdRjVHlMz3AU8xc5LMZukhbXWhUKLN3+UhUyf.ToW83sULO5MgYk..F.1K23l+5wIoQCsfnY6hv5rdj8vQZMidw1mRoMNpyViiRIlIZurdvEkg2e0tVyFhPokfqrrrolZZkgsVpwCTvY2mO1RWMA0RCZpMuMrvPXZOg9KvjnqCnmR31vY18ow8ffweGE3uvalz5rSjhy2qHoD8H37qkTPgY9+WJH81nJz8RaAX97YU4pZbBr+KL+04xqj67rlcM0rzuc5TnahJEqlc1J0gXVafABdseHoP9EfIIgTVDxT0DTJWhb7w7tL2kzBds5Q0G9K4XC+6wHPVb1C9JZx.9D6gNiGeeEbJDKSdihoy+gQ79lpkRdm.9jjTCdz4SBG3GulXBwZIvlEvF4GpTLGubSXNMf3ipfqcWjvaNe6eZTg+swzsjbkWNJe.zVWfcEnyoUSsYTvSTL4.VfokIWHnmmun2q2TpLBtt9Jl65imiMQ25mdp4jg7z1nz+9TvxHyTvoQf5sruBsgYOaD87HTKYPKzEKizZsQf.hver2WWdjArYA50TkL+7DqD7LkTBR92cACPULpsKg9lVKmnxVskNMsK1ZHhjr..ypnv47o1938n5SN4IzuOInB9cOMznqKK9SZLKJ74nYHetG6+z00.DkUDzb5wGACyExyifpeuCM45XsVsHQrDSbIN4aJW7ras8.T8OM2QYOu0yW9PlMOmpwaAVOF1N3FICsvoAPHuP8vw+LuLm1f7DTmkHFraGz7ChJ9TKmPk5BoiMWU60es8TSqzO3Qy4jumriuQ3JddqH3+GgIHkLj7J30dsym1O9uZupQGwgUxJ83DOjfVig1DtTFocrWnfbEoiYTmFCc7OMLNbwSUd7GK4F.o+6UKKeiADbIW7g0mysAICDLEANRC4KU5Wn9ADBlGMJ8.7RlSU3Wf+qZdItJI+ooIZEZs6bwbySQEmrl1MuCvgEmdcFOApY09uu2WckLMVSQDCEqh.xMGz52db+FZ4bx36sdAdHOxhwrikSluPfVWTNCQy6gX7y2j7+gZEXmiVbnrtc.nhsPjE6h8b47R2dnuNm+0uDnGLP40QnJWpAh6CNXkcX+g+FWlMXsej8wNyxBGcjo94jU9V5el8iaLzM46DOVPrEoavJUOahw3+dk.rnN+4fjbfrlkUM8MZcm5KWsffdCQExBQOqseWBHb9ykOUtIHBKAnKEO6vwBE2W2cgs0sLH1LmH7huLGkMmSTVj.n9dtKgGElwZekuElbTX+hNd+SWGBm5wibeRVWBtAEmZzO7yXI+fcl1VBmvy96DJzm5RnMb6LqziOFdupbd6OZyeQMe6JYb+PIf.LcOZOpr0iDQ4CgDn4w+dy9wGen19kGZ9RKDA3Jq4W5n60IfEAJhus9Ec5SW3ph.C3Bxp+fj0aXmmN4PGP6qPHuslkTcxIOn350vI8C0CJ0E4oQqYMOumnLx+Dij0uOkdjeKrWNZgRKHWqFzeJPjB7o0.1nZyUHWcnoZW5C9D3qZm9CMcQ7ykH3Fc4+BuNrogz4uIOgfi71.LJTR4MNRQvfboevAXaYUuIESHBt+h.Xc1F9nV8B2oM7umdEgMd.dFXqPMhEpWYt.mNru+gyW2JaOWWTJ.cO7cKbWi8zyHif2yjE48Ya34njba2qa7KEXHW8VfArH+NVe9xZ0tb0juLv29KtKRvIqmAnMzDISU3EASvGTuNohMsu3muWRjotGd72N1mU+06LDLTRqZ.1cLIhAAi1FFPNZhoIlbqnH2YrvTwpkBCE8xIOQa53mxLd3C9+TEOkNOiRPvg9YKNTjP9uR0nmgbSVA0ZS5uUsBNNeS2THFeAvan.sYlfeXUTEgrGFN.TczloNAoHUy+LGDBklcK8fid7BzqVgln2bNU4MhfN7ck6ZArB+zPPX7ITaOoMpqBQia1k0Yfa4vcFNSYgaBQVaSN7mCb2VcPqAGL5IRSi21FkqF5wEyaXajwbnUpNob5qIOojlIQnIw.vL8dMbFRqkRdx0Ymw87QuDHS1v76G7VPMUlAcDrr.EStah3tmzN6cGjR93LZAKEutbar+vgrgAx8WEy8fvZreq9SR.l1p6.LvA2gM8MA7KAIqb+Abx6rcjA2I5QlQkvP3OUXsro.pLjBv2HNBMXC0YBlmvfufj+LkCYzamhrvv.kqV7oRE.lS.IfOVTwDipykEFiWXpzW+X3.KjLJ6+sbOOA7gKk1gNslx6dKxjwlcJU99924FxKkOoU2yvNqfkCu4IQyz2.kXo3GL6uv1KjdSo6nFKV2Q2DJTp3mgek3y7YWpT4+z08Yc1ISH3ABEhzs1QkPRagDvfnNrl10tORRp5bp4sKFUVWs1DKPpxhisCnBcmZ4Gb0tp5245D4YrmqgsWQJQVsyGyWf0PTO0Lcm4ODNTcAGri89qMCWtvGDyBHQrXaxYEyUZisX784VZjQqAIIa4sQp.ao1dzqPsqGnxOHhxwXFU6swfDSTodzf0V1RS4gf1vIhPbCoONeL2O5svHnxNkAcCUoGbdy3msxyOie2GXoUa.HE6YDYc56t6X9S3VaGwxtn2v6yVgCMAy2zsKkLOwfX173.VhjZnVp6T4udrg5Mo3zLqI56GEDKKwDpyfSNRhUgBm98zHZPkHjQjO4u.31vcevAqZro8g5YO5UNpiu2wu1w8H07iAioNvmCAdjMOlSul1MM1XACQo30CxCg92OQmW0ZFx6n20TgsFcO9pII8o9Txvivb0k61Ad59I0svSktLb9.mneisZKcXebIdIiflUevvIP.g7Dk1nXfvc1O7FshrET9qasY1iq2EtK69kJ1Yt5AiyD79cH8MjbGjMMEiSrULuPkYYc7gjYE6xLOI6fPDskCbyLeRQxflHi4Q8uEBbMUDhG6YZQgcWlhBAN3LsA6yG88rGNQrHGckPcrOGlFXfgDjUmevXgpJPz7KfA+wCwJyx6bqzD.ItFpVwTk.seoQw7vSjXuzAVQxOU336Z4rS8RoVKRV85fhg3cpN2AVKQZh7U.5kkynlEBOmmZja07fBojEkz8o1LJoHVKgEL8WdYRrXQ8AM3MsTHFWdnJoNqkg99ZtCvOSVjYl1Y+P46oGy.6ORwT8.W1GUTbtWQEPSlyHFry0UaAWJfrxmWF2OwBEPOPb0HpnQmLZ42D7VWytvP1Ty4VAcCvUE3L5ERF98St1CL2j.rg32AabdeSHDHPqBgQoiBBqIqfkiI1UnNBnnf2Btaqpo31UP1SG1xFR64nm2kRX9mKNxUEvDHvxqOAvr5LSLTHFermnm2cUDHGwc5U6WNgPF91ZIGowUZu89PM3hkw.ChXEJsPrHujnCIltUEpX6mJ000OkTcBjHHDR53C2gIsMkjhwpU.UwKnMcn0HKGt3yDBuGZPkPDhNBjp.J0IerxiFi2w81uv3MGt161G97fPzj5PsCeYyY9toC+4Rl.hAGsSQaXoHoRdw2.aI2oN1CBx9ZeGtI82GGWYVTxYox4p+1uM+UnIxeuTyX9tiGJ4Uokh7uk9j2+iPkMnAHhXtW3EDrC+8Md09yU0Jd7qhQB0P72YqrJohweR9jjSPnTALGVFXY5v7L4cfCvBmwFXIkXzUhb6k7pjWKSva1GMGz7sFUYDcM0WqqufcG9CzzHFndtmxJ.SAFG3MjynkXuO85jsecMRMdUG7jmC2qZn5+ZTk.qgKKtiTYnqo6tUE4HZTI5+1QapBZErkVpojpdhnKMZbJoWZQRvf6bh5zjYKkS48PVx2QSpp4.cuxx+FQ1oW9tPJUgdMlV0DyYEh4i57UekLjROIOhwgsAvns+kTAvGEGBIHaBeg7hwt9XFXAV4kMx5qUrsWP7nqhCAwlQGUVb7AQeb7P78KXN+RRxG+ieQ3Etw2eTzzcGrojvN48hxmf5lAVSnpCHUUdrnoxjxoXUqZALrY7lq0TW7J36Rn.jZSIM0vWIOeq50A5jt7S0GIuTxCWHlsoFqBwec2YYHkeHWFLr2XzciM5Rvfe9AulL67ZW867OAgq3r6twrL1R6CqJy3ldQKBPeguiM.f6mje4Gu6qG.D9C1X8jT8KWrXC+pj4QIsqA7Qtg++gn.l7+E9oFw8jhVZpjBY.0mYyK+OECU2T3WsBsv2gqQMN6YBZa+OyqVxwoFgYBNF+jaSeBoI2vW.cCJl4SS40gr8gXkG9DSzNSpBcU1GBd+dxPjQ+eHieDiRwOvqvza00L7oBmu.BFQWnKsIsBvi6mbSszTLAKosiLDbzhckrB0VOxU2+67HQr2sX1QvxgrLGx79Fz3LAePEt7eNZR2U4BaK.CAjFxhB5+msu0yaFP3nJV1Z34OOr.h3qzfe8KMtJjCBKte55e0d0iNVTqcGL8vyIkWI7RIottjErSlDLyMFiodbfcH21Dky.oXP5UBLVwIigMjESu9cFBGizn6i97Z74ORJR58Up9BI9MFJdO34rQRyOA24YEyOW+DeonWQQ0XXg51jTAqUF9XE0FW7o3b5kFlVaa+gJbWflIky5Wx.rz.xtibOtTRjANY6qfqCbyawPPBxt96lFlNwPDidvj4Jp2HBWBxqLFLmevo6WRCbvbzHMZIWzo1o39z7VSyapMmsayCMTrc9pIINcSDUwJ3Dy0tHbnbLxAUoylCcpWzLyihs5p2ES2ZCDGUBK7558FWCPFuKOlWEiGw2hvziueAEWcAzYNrJSDbDNQJbY5N28DsbnpvXA9GgSStVZT8FO8juTI70VslMcFEHu3LAuNkX3qssV.zra.4b6rreNR+0itHwl6E.OyRjM6o7zjQJUnQ9Ea9hIorvCAAXOa0fURT6KFdqeYDdMIYlUsexPmGZEn0jy6u9GyxCKTDfu7jXzQ8rf+FCXIoZHEkgyxUs0.xYY64Vvj4dw+D9kddc70qQrD4bhxtG2mTa3eJlI0CfgM5g2bc9UfWfTa+SWjItwxz.08iUodbINTMHfz01qodyCsLPwMq0Tq6qcEMMPtkzly.E27iAy1A1HdleKxYWSbQtyWYKHn1C4LpI71HYny+k4un0bMIXoPEqG4tugsa2zR2cAk4lDpBngosc.eGpEGmw9Cpl+XeHrIIODafB4Sl9a0QFugf1DWReL41twp1X8uQhKS8SC8st5Dx18vnoDAotVZqUABfD3yvRRgJ2wm2QEp3Y0YHFv.jXWLFoM1FiyJ2KyiPwkLQu9ipgpMEB6KDyrBAbguA.U409E5Zoz8A1mYy9L2fgMxpPAgUdN5C411waG9BMnhfIkR8lCYFT65GLlHT34j9MBhtbi5F8HyvwFpBGglaZbPnnBJsRNZ.TEvMATXNPjLNt14mzn3.qoxcYQTy3ywTz3IyhYf0B+KuKCWRlRrtFncqYb8ZKZcEnGoT.Ffhr9c66p3m3VSgClTSSQavhFXfudgriM0TezLPq6zDKfzBAvLLGEZQpcuYg9Y.qBmNzQ7EgxlnfoEMYe40TyXTlQO8vT6KYMK4oBLSxwI3PWcJ3O+DoPWuixFxK9INp9xAkABWzayeudDAnVnSzyAsT1rrzIk7C9UMWA4hzHvMvRYtOv9aI3OQhVg32WOZJC9QEFtMXBsG1Of2xD3giPclSY36PcAmPOAmqiptJKTCfmGgG+hHikOQiIL6HBAS+xtyP8n+lUFqK6kl+W1mzprsLR6WTzqxpcminMW9EPykeWSRpblE4+mZDYy1.DFSg7r3zS.5Fw+1tY.sd9rIxn18IDdZM4QWJ+wcg6othPNI96VbzYa7mgTPp486Km6RrfAWWx+6+7Kgz8u84iUr0ZDt.fb61FB3OD4Rn18ovMYfFO7kWlCriERsfu7AOxgCWgUhxbRfjB7A2UPPUjyYZmqksk3tBiizJO9rkLWYlCKVH588ZCkrmapOm9U0WJaviPV.h+4A9FNBv3T0hOzy5e8gGd7mWf7E7TSxqQ+RF1aBPIh9WkJE4778sYabYQ82Nl8xHSboHRmshMKT17ohQMcx3nuIyCoeL4Po9dMbHtez1G5p00MhDoblobT7R1lt8OsDeNlLTUi2ZjjL1S0zL9rBb7nYM+Mi7Rlm5mDswy37gLDC+L8fCFko.+r37dV6kst3TDoMsY8kH1h1wS7x+lmDL8ArOw9FKD.VmH3DOZfIf6Fhm+oTMZJa54TmG1HpPDLmSStUMhlkJ3CgDxPQQX3HL8TlNsNQ68II1oxf4qoWZkyQxIoXBOukqiuVEgzi6AcLChJaWkVqq4QQ9z4jL5koZ7fLk3OL.wFsuIF3YWmznONqlWTiQztbYtSeoCTUmOYZvs9MtLLMdKDMe6ypXGvh1ZsT.EnZTxNX4gnWLmjdECUVweve0epF+hjgms4IWiiH7GQXBy3s+GGU+.xAysOGzJjYRJs8cKkIVMzmleKPabMNkW+hNQ2Ef7s98lCQeMnO81lOjHdkHMxroaRQaZX7LfAbpL4xkDfJOtmwP+nECnjm0hpGt9QKXaXcUoLmUINaYMCieB8cdKGK6NqaOyuV9ymN9dUOME4sCnejF+7XZ0llBKejTPmJe4j19KbiQAUKZGwPJvSQaxDPWUyDYLu68JzwGnWp6IZn8QfL4aF21cV4bldxg2juc35TzPu4Yc.gDpAo6sknUfXIPUE9P8TYkrONj4YP3hiyjQv3QR0620oErVjWbmTSGn4owwAHZCRUMr.YVEC5zcbV4KPj3uwioo37T9HKQSPNAoQnUV78Uz4equbsULSmJmmCGeD7PAF+w6CwVQ0VtEiOE5aUmeirm2EdG2FPs.lZYqaVAhSw9owtEKAM4r4NRnW6DnMVTs4+xtGFnA3gKt5+7fKSz9.tCvMQD4GwacBdUIFt+JjcCEWQngPA36uBAP00Tlyl.QKqToL6XEiZMRo0jOj5zSTYaUfBOHC6BMRePT.XrmogUjqmiDy8sewQzW59KTnc3ujhttv3AFcegQmqmALdQgL8gcNl6Qis1l9i0kzyx7va2v4WkpZmGHumMiZNI1Iq0cLzVVAxYSY8TWql4urcGk5IAxcuBLMzAtwJte6M3EVhE4aD9HaKMlawF65TEs0.JsG8vf.S5kfFhcP69deQcPYqxOPuJrAVbMyn3xTYehZ2z2T+8.j8ZKnIX5ZhikP+1XZgCa3Rs.vdRsuVwOt4TW7AcxgpW72J2k24PC+q09MePHp8kvS4rwJLh2kv3ywi2XVQcI2Jzx+NF1iM5.CIUYo8hJcxVif0qTGbzysFoJYWdFMO+Gx7nH2qQd2d7I1QgA0yuwipKncabv9qlhZiNeRRjoUSrmBkMBMvz4j3QF6Ymc8NWjetL.I5f.woODgXbD2pH9tA.jf.YF2YU5jduRUD2zpthMbHcHzj21uy9amuGNOytY6HNnfbKZbH7v91dE0QuBTv5zEScU4KWp+sGWiQoh0NyXWPgIV+U+ZO2VMbfo4.nuRLQDsAzMQ9prgusXfT35xUptU1uAb7Epa9z9GOPZttrqjp0C+qx39jd75tKbFPiQlyuxwQ4mI.xeM92NE25AR199qdHhwGZrleCK4TUf+z1RO66PlAOuMZ8uEw23rvC9bwq6fkwY5.5RS7KGq36JUyIOEMsnwOzIKNdsviUYaaOoyJOfcrTiWIo4YIWuGqCVFqjXUwshpObyWWseSFpr0qCmoFyTQFOtREt4YUla51gAH3chcqHfv4T4XOLMLM4B6zKJ4mUUS6013i4Z4pWoKsvxvfiMHoqOXJPp+86jMHCpARQkcnP+5jXE.aGrmp.1nLbtorwFcix7ZBvvnWZnCbvf8AlSPlCNXLePeB67449dEhFylJGH+C6TaP2nw8ddEFAAcP7DJvlmWKxpyTderUN6SCeMhljISN0Am6ulakqfAwaBC4ADvkIExRJyY3Vm4ooxZHyh3lDrBk5jy81RpOoYyYzqz4F9PVlklBFwfvNN866ehSCMCMz+cHH4hpKeM4WrDOweOxqtnzzGXPtLg0JbIFqGyjsh+en47UJVw0X0NO6ho0HisiHijEb3SQ1qcrCB5EAZaONMsr32786L0XXFVj54alhPdeha9mzfgtOcW9eIsd+2hwe8jfSpb510tZd7c1GWlyZocr2MFouS52p71UttRZPqx4U0ozpW7XXq5ZknOHabjY8qUQdC4s.LIMAUFQiIvpc6v73Qbj.Ojw6Uhy1yZrxhGd2CtfdRcM36W+tiBBv+Y7p9pqBEoSR4ryqPGFZBQ5H0VDf8nPn.k+udpx3UxxFfp++Hg8UXAYEvzigowI7RiRmbRZfqN3roZr7X41SMDsqA9jD6iVf9QJLu6dbbqInzVbpE05dz1lGuvM.vPTDyyQKWDsEQnVbte.iUtp+JzZQCCaoVuENQj5ns8qF2vS2ZP4PPeFnEOxOzdgwhCH6tUEQV+7rB7mBX1u0rSJltp1B.v0beR+.YB+X9FiNTnrkxByGWCYQmu2IHm9bQGULH28.f6uM81Do+NdPEibwSmngMW83IcAbfce3cXt0XNOsJIh7qUYhNlGLPQZtcupiVqjOFTibLFhWdT5yMpUw9QkWjgaiwNBDZG+H3GOw1wyA6l+GnNPRm4U5L5mYcrw7aZic2zwh5Gr3qhb3peIR0xOJvDoOA+ujo9R+FVwSeAHklwL79lSRpg9MkOq80CUIBZr9gk5OZvv.N6OakThgo9ZjJlOKw2eMdAIt7NCfM4HMzzRxTpeljgwD336Lu0TYwxzPQadlcKY7I18NXyXOZX0bM6sdWuxt+0jBkqEp98MXgEk7OTYZpKzvNh8Rbo786f3Dcrnr9EOVKkvyY7enXXctsbsoiA5wc2Bpbn+MIwQfzy66hH3ksNUWtkmgQo6KT2yGbd4angeu2J5+O4bPEloXlsBMfiucOJwkIO4kgHe0qvwG6Cltg0ZpeM2PKfVw6LWgLRSC8JAjLaXd8nNduVTInddnrvM9lR+mKWCNCPjpu0eya0Yx7G1xLLj5Nwj6a0f57QKulgnYvZmO2A+o3xL0QHiHp2XWt7EXbfjRl.bPvWSxWeTaalA.4joKyOUctDgp9Kvk8Pa35lGQyTsF2icoVIOF7qUR8Gi5ZZEO5vuFphfTdUrz8RuSu73wTmCiWiUR2nciE99QrVoykpew26+TyYuKc5xpc00KGDHDGICQVhlJ6OL93YOqkkC9hA6SDyYslpQT4W1Baoi+IMa2VW98y0w9jjdLt6450AwXPueqrZd2gwAUCPLZdbtl9vYawL4GkhLGgpT.nZyRZbIsGtvlx3CxXTpgTMV7Of.xiZDzvLWWN5pCiCydTTK4htdCamWtYWwoC9rEgLU03H8+ljNwXnJJ6e1A.x1i6gIWW8yp3d17oGxOMALJXBnQFKPuQ6gOnKRxKubVtb8KNW8kF5Un2h+VrAKYZFBf2nBp+2XE.mnqGNZPjBXTh0CXkSSwlbjzPNC+CdjxdwyUMxhdIIojlrvcowiWDqjgXzKG4WHgI442DLe2u1v49AQVGGDuSPaOnVp9pak4T.p5xeacR4cK+B4f2Y9iZM1drRs75PpRXrtDR7flwkNcC8jFWihAx4nME.kZ5xQ2vRSBz7bKbbYbx1MmTjTo+I+F..Hv+f87QYChmeVkHTy5xaGnzmmL2MnKWbwVGSzD+YfrD6G8u4ai1OXlQvRXiC.QL5ceXWAOf7EOjCU6zxlHDFWToYNWwg0ed6Y7p7xARaMiX9tQB5Y0afaMFeRDJrrT3ADxx4tWygXOVd4lVjLWGjRO7u03JsT9iPOToaGilJZ7+3irnRKq.ong.d8vUPaAY7ymz0fUSCRyYpfq469AgXGSIkfFPQP7ZtqqWIhP7p4swQ5pwtVj8I9IVvAvwY20UOzB1pWBD5ynTAuIOkFg4RHSHC0BN.0uORmlYt5aazhdsoAxBGUfrfuZaF3Fg+W3bA.7+CbazqrjLoOc5Vj4EdRtUgqD8mSO63xzPZo3dhagzZvCaqZmhcw8jHSKjSIjpjwRUCOFV4I5j.Wk1AeaI6YVYi+L3xmqSOCQ2ZVsZZWioVW6VQjGu9wlF8UccOCspmaReVUb8ySh2Lzh55jvrs8tyG7Cg9oTyiqM3AZp2vIV8uvkF8LmjeCTQAiV4MkG0d4RMZrFENqdNrCZZlQVeRvailOTCrtpYkspoWuQ5N4Y4rZRqc4RW6UybDqHJn8Ucu07t2dWQVr.IBUud0Sptn0YDZBHX+x4qo25P5z3hJ1wEXk5vSZOEiIRtn9Jlm2iBnLGdwTT41pzVJo9CPsQcSv1LkNI9n5klziwznHHH3Xb3BfBPPNWaQb6sGDF2TsMd9kiYC1PS.8cGNXRAPVoeAdIAsOAVPih.IYGwF.Mnn1I+k+oCaqq9ftG+y1Ax.IX+zx27ut398H86gEhk1xi5YoQyIknlowbh+sP1KhU2NfhwktqGOTrDI+6Y63cKZ.JBZFvyJepLKCtSzFa7tMeNAu5+XDHauNe44IRfNCwTZEicVv47+UR4T5rkOciIbl1O.XI5LYD1+vpvKVugAtElxBikF1RLxz+EXM56m8MqQ26NlcjhgK4OQKpVFYff2QmzZ4+GXP+2DexIjUI5InqtflAqELTM.3ujp7+WWWc3AgipkQZxZyJ6z1BW.w6TExtuw3ik9WkFk9Tn232ices427SJk6ZkJy.Y8zoMJba8zRCTozso2pyAWTV0EWTQLG30aNE7i5CT75wO0egollQCgklCSzKl7wEXQvbAIykbhJjRgbM2wRZnDEOrUKA+C0dmADo3mEYahn1VBgQyC8GR79W+2VtDGCB+igFOUWKOzpMh5HL7dgEi9NGwDgZ3xABh06H7RbxDaAyoIcm8rwsafdeDgi1hMK8U+xXyTlKtm1ngfhZK93Z49cklMFqxWIl5HD3C1t8YeeVV4pH4UaM8WsGDBQv61h+4dyti0ICYerNiQi.6xeA8rmRSPgZi7D+xl0FzhzJvw.6evUTf1cC9vQJcbsXIZgy5jPEqeoQkAaat.jd38PJt1jYapctg0pG4yN.aHIAanVXsFYLWTUaHkA+DpsilhRHsem6z8yt50qrbaxJduY06CSNjs8n4obwZrMvDQamCoZY3h7Mnw5pdP7dwdHo5dBl4DkyKrwl4kQ+YwWt2xf1H+ZGBVsW4nQK+vxlKKQo4pBu8H0oubVH.C3onIeKNCMZLhAU252DtCZvm9f+n3VOheD3Pc7XWFVx2uaLlYprf.FaWVqMAXIN8SrBJjZpoOYiwd5QxUUV5uUJr83OtgK5IrmHFy7QtFSQpaiW6DsGPfvV9BxXwc.6oMlGsZ+xE+3gDO4uGvvu1iMl4hM.IMTeQv32lJp5vkJD71UnohLJ2ubu1owZtkjNjN0Yh18XeTcESvAOC7k6NwP06mcqC76Ayw6isn2PG13SZETnL2ZrGT5q5MhzgPZIfyZeavgdyvu+IQAH1ll2ssVI.i7aa9fJc37QHTU2j6Xqvqk7xV6Y1G960BgauE4xJnWbz8kF0uSMz9ym6eJaKNdJsAZndenFEuDD3Ru.3JpuVjDXfGn2i7oYak6w4qd.MZsR25p9wYOrAnpnBzED3f778ZX1DUmerRiOlnXCNNxWl2a.TzLth7041Vf26W+FzE7LTZ4tsGmSbkrM7BPZlTQgNWZTPYeHTvuqqez6r0vtBjCDl2FJKTtodvKKQaqxwgMaTKH01ZufBOMN9ZzQQQL07rQ631bjBXgaNqrzhHvA5dkvgzx.9PH5jjlc0NtQYlrAl.xkgo.SPBIBBrb5MGKKXxWpXydP3w5gr01d8GYeX45jBz9o1ya7S8OoHoZnrJCmxcsIdz5dFr1d7GIXrdRHzlykLn.X8VZHPlo1wZ9sEflwN1ULi21rT2wiK2xSkdDHiFvZPHWQzj5iq.ri6EbenvVYJArf4tSoTBp29O02FcGGHcs+YaVjPbbheMcb5ZEmg47ZkXMpWXtpCasM+2AqSm7G6Y+d000XSWWOJvi29pyx45NfAmlsdafqrQnFRtkRwy8O9zztswEbm+wI8SttbWp4BG.M+YxSFIrgRwNgeE7vnIzb.SmVKNBcMcTFJiVmBVKGkt33EgXkgZQOG4ShQ1L3E7Er7R612CY1H1Q08YWMZ5r0HA5rasqdcEzlz0yV1DP+NQFrHGyxJ3.d7SfFGDdXMVByUlVf+qyuBcmTrNglSGMrsLR9j0jQgWt5qN4NoS8+Wab5BZhEiTZclbeg3h2JEL5PrCyvGJudWxLYuaw.M3mtLJQjba0+xfHn0VGy5UYRbnq.glo7ZjlHfIhyZ0xjf+ryv94v.JxqIj8jAzJp0s.YREK2qh8PdbfacqdwWu1dIHZoDS8U256E1GN20c2enb3C93D.o7lmO5k1+bt1LkXa+nR15Jfv6V6fuWCella7BDaRDd8.JnTsv9lpiHlyN6soe35iJzV5eeodhj8fWlITTqIyO6mJnFK0iAtV.2pBLYtfj.bRGOydcewx8sdMI4e8kRxnbRTYU84x5DZHq.u.g5tw4DtCOBL8hLCZTAhi3pbS4lHolMoRyybXAVXKvilEj8nmuERvqIvy7DwxUU8zEft.LucHEpxBQZJBknLTFbyNEQ4TIGBSTb2uF2qTqpJxMwqrnGbNsL5LH8r4FKBC4lxngJqJmRqqGy8zw7umC.884dbGG9hnqdwcXEpTdspAJNwXk+1oYGcKmtH2XoBFJ7w2ukvd4MZ8m1PmquW2Kj7pIfrZ8DgpKw5s.p09vrGJXyyHL7YxKUmMPB2rLTuyDJ8+BP2JDBlOStWDp75MEoPI9Blf4cxme7t3ce+1xeUkoCCAvI1Xdlr0xiR0bu3KtpZXzMGO6cJipdlXyB9NQU6xzDDwdyYArM+.p1EXwKlRq9e81azKQkS+.SImH++.LJS.tMJGXV.fsM0Dgca63TaWFBa.6f4HITjRNNFPWoIoTuc2ikt.S5EZ2WE2vMoTCuwsMnVHEKED24vfSmC751S+8bz8EF7tNsMZaA0fpBADUpw3AvGUfP8rq+HeM7+3IU69hsMoL3iNgXlYwKDp6PuKfqvO3+za5pF1UyENF5dKpwCJw15vzWuVj9dOJg4pTrJWy0pY5jfXMiFbVkytYbQesSl0H7iLaVWuP5Vpsg4bn4mK67AXs0y4K7s4E88WeWyWM8GcOTghbb9R+7MAbnPatHAjAa9rzO7uO1AlJeFnvz3mLZMKntQxjpJ5p4ipj+CQcABVsOXki7SWtJBR+PV6i0xi8HC8yLaSX9LIi6LpjOpFzfdHUQ2cqebQrs2VMjIDoDAxcS+vSCt0M+hAZUh8TYTV0UfzhHa3lWdTA2VRcjvNBhuKc3J8txP7rvpfyOtxmI0gBC.aoxSSnpn4Kew26l+dW04r1XXCxwBmuzQV87UaQBq6Zjg1M1RLjWWoChMi8.09752MQ2d3RUCHTOjXXUlncYyFPh9IYWSgQIXEdDeo6HAyd2OmZpFlugZsBJa73Hj+Dz7M6FNTSSrCkt+DdZspqsRvNXtPU+hCMRSEZkeKhoiFf.SnsAa4oB.4+ckKwkjtRjOub.NWWg1.cQl1BoiDb2YdCEr8D0edlYS9ZNGVSOOyYbAyZ+O47earejazhVdaHPAKsDJoArmPYcp+JqnZsbk.Fn882jZD9tgHrsoZt2YdHnMqTdaceCua49+8GaRvCgp9QgyP9HZAPFxaqtaLM2CC1kyIG8KI7LgMS8DsfUYR4xcvErPL4IxPFK+MISW+4Aj74TNb0fVF5Z4yqSqshGPAsISSE78CpbcUVPdNIH2IqZZ52nibbNCzRhLmFgh3Edk.2fv0aIYdM66gQ6EURg2Uty.4oIvSv71gBhFZmS.+LJsBEx00PrTtm2Xb8Dt18vDzJeD1dHjiFl.fWt0cwiGUcR.I.djaB46e0LjpgkIULXunCWEHSULScsSFA8ZUk8C64jLJ0QLEAn2VgFWbxZxWgHbBCjkIXctUZiyPECYu7moIhXW0nbzPVuxPJ+Zdd+JyvJXZYYLpA5T1quDWG32gZmqNNmdwMak6d4noa96ESV2D3b2aKEuq7VYYO3tuc01ol5gcfwVAUu8ze0gzGljoDWORlmPgMEw59zrU4T4kWsv2hH9YAlNqhgqKjLSUJccHSTRul16iaHwl04sRAU3VeJyURC.JYFtU683N+1Rx8h3JJpvva0Lvp6fL81QeWFn8T21pJ.EULmhIbTVu3gJqV9jBqUig+bX.HnfkCyCAf694UfH9q+4UOwSNTG5q6dFofrvzb3Qm4YGgSY.m6FXgGyWGwy0FeVNNTk9NYv59CMo3c.6UefpmxxKEtwEaZrb6h5nikifQ1.GdWEt4acgf7d6rsP.HnIH7SVpvD0oFcpSZt27LO+pOiG1p+F8OKXbWgRURYBe7Trz3FjVUs+xkaDfR9EQBoIZFriwJ+OaoCqgEzfGlhIllyKAPsw3Xh0wMJT05uZsu7lNUMnEIcOC.tU3S+VGU6.lK6ew3VrXqln2UXSTqSwp.F8GTyEoaYYYmsaW844B.hEBCSWMM5HK3u0GdPl71sG3IUVKiUox0Y00FOVT32fj3WSRQ55M5X6afrPhVWRChaut8n1Ku9e9.0PZ6E5MWKGxMAZHwQOwGIQCeypAvtKnfNHBdUB.u3jIQxX5f4aXsLzHLJpJlwpHH9XNF6+C4.7Pg29S7YaCJmRxkB94eYyY2B+JfBF89Bx9ZGY4U5b22Zscwhs1Glw8TsDODNsbkzMM6v4L0kr7qXXXDFqIkssJVEs5YuRbqfk3JG8BKb97K9TPCijA.l1kXLh99XsUe0FurgBFd75oRsbfrFj8BCa0CUd9FKe.1pbBORBdg5P5CTuT5NWuP3UK17LMKBHHkMrr7Lr8JhonJUsxaZxZyv9V+ZLKPOI4KlSDqnRkRFvmMNEg1tq1DQZX2viJGq5odVkLOv8w90qdpSWBMyxS2h77mdmANO2DcP5W9y.8u2HlLwKvTAbLUSQ09o7GBhtQ4JjLtZvU075LQwWYGDrnwe1Ywe4RNKlBFxLyzqdGuIYaGj7FTSn55J1XwWhatE2h.byW9SZ.lyvoOq1pfn0yVJof2ejq0QBip+r1wgZY2vlyVkXhPRxPVvXRk8bLTZVHFwbHPVCKqxejHc0IqJj8QdZZVRx0fUjW6bWVpigooftOQTkxTbCQhtXs0CZrPTNcmR+FBP3ma.vFbsS7AfORe.4sy8MUK7jd2JzaF.MZd.1LAyL53AHK1yYdBPaw2N8XkYvcUB.pEIEuK0.BfsFfdGnGaY5hMMGkKzQAd5fJqAN19J40wKaKLxa78ZP3x7rlbBaBCIpV3albrTVvNy11MWUC6GbY9GN85fq3fFAnFHNvfGSgFQqy6II.0jWu.5.mKX2jzNYCVEKVC7XBtX24B0ciDH6S3OFqi7F5QpPuJu2qZEO2iSELYK05ZrNA2PXHElx4lpTBJwdOjwQmxmc9pf3URbl6uzcAdyNfVpx+l3k4zq21Hdwuy2aRz6p53OlCE9vFgAqqCSUHxsoq0RXvosiiQcChchmv+Rj9MD7j5DSZyFTsoVeTYA4sZoh3matR3Cdo095ig2LvpKJLuPsdkIEd1wxIdivhJDloXL+Qy9N8rxWDDqoYBHVRu3iC0UrZd9BZaCX0MSyNzwOWoQR8604BtNj7DJIzCjDJ6AZ3wrG.AE3deT4EqH8lYLp372boAMRQdRPYvCjbH0nAcYhahG6E1pufo8Gnu+pouk.0EPLfK+gjz.DPXetDPlEjLtYLAUTjQLjcYIheAIQIeMDpnnwx.hXlcP2NTNFsKPS1Q9ZkPN2aFLTfw7YaXKcDmiq0LCNOX.1OcObTuVOcYJYXPgX7ot4Ri.fZe8ZvYoZdaURKuW7wYXwu5.7pghVJFM2ZYV0f2IDxZgfdfd4xzQ6FpAJRV8PMN2jDLBdXiiAimNHMa1O.I+cTtxN3jzfRSEB+.DqZkuSUdMKmvetZyh2VPgoLzaew25J7P0m3FujdC+Q2w7wB97ZJu37nB7lMJYEx1th4sI.3RqdYhKCxz+t155HPYORMwfj3eFD4Q0ALLD43jIxsWX31BHk1AlHdJFB6inIt19Rvztt26rjdhmFr6DhwNIa1a75JxxP.y9bnmqyLhxCefGMocNjOLWuRKroj8WkYsvxUF6N20971PNWAApjwcRqSy7s1AsDOJKgOw0gijGw9YoIPjAfB96ylNZAFlnFiiF7ovHqTBM+cbdGu2w6oSKNwYysiMXW1WpFufrRJGnZS2pFCvRaZDiXh1S7nQS2FZ.6O0xBz+MmVo+fs88YsnfzGz+4JiYQg08lBD4RinNQbryRpVn4iZDR47ODHszsr9UUDQoxpsi27ps+u7J0hhPCwfV1ekWeVQ8QdGrBUr+SlQj2h2MjWTiTFXdUhHwuDssK86N9PSVrU1nfYTOyOiC31m0MecwBwWx95K9TyYdl4jKzrnz1KSFw0Yyfk3o4Ac54DXByefme8scU4.djiVMTB0bgkIDsJFmo+9se0ytj0GfchmN7+p5eWFGjlKabLkboL0wLzfCuqKH6WfkrEQZHIY98oH732zW2iK3AMn9BEGWd9IBFFoBabQ9oZytjaRcNRVNztZLmn578vAvX4uLxFyM6NKwy9zXFZFa6PNLjTXSu26VZ4k2FN14nogPcKgN+FDPCYjfev6VyF3xqdYBfLM0JpEYOaVpkz0bLrxHT.r00f3LgqN5iYO8jsa5Hh634SdFDC9Zygh4QK8qM8.8EAFxbjMMGc3CDwgGVVJCTktMF9x.5WK1inUeEle7V.FAdpBa+X0GeGNzapI1JWkpxdfyQoOP6dCZuHqpif5eFyCm4c.WXV6kn6LdQh3ZgNbqZZpQyrv38651cueKkpcQFZsGOHR6H5AsZuws4SQXDKkLD5tOS6UbvueUfA7MGWk08bYT5Tig843aWQBCigHSGebDR8IFrvdOkE29cTGiQorFHAoUbAox0j.lSy5I9lvhnimddcMiaHHef4.aOrnI0iuMO8Arspq2hHhDOoOyZt5P78JIHRg4QJEt3G6Ug5rivUKgj25.XEQBVQtq7gEy0zZ.t6O7xu6sFFOKEYp8jJ8luIqJhyZLDf0VjWg9LD7xUspjPIYg3kw5kL5QPLM1reIbdRwLsKjg7+yyAUjjlve2hKVrCbeu66VO19A0+iE2C4okCaAbogp5BYPjgggFfXA9uVvKbJ9A7d2vplsT27Tt.y5DIg43hdWMyCXnD9ckDWLDHHBKJaNJhdbu.ci1O9l5XzqeaDUcKYpejOf06aP96lXdLpmnT6ERYtm21k7ggIZ2oOyYD.4PRM5AgsulzAKHMwjQgggLeqknTsH4ZBQpJ.CwAgEOdu.Y.VDzrur6s+T71N01Ubfw8+qZE3Wjuw+sUp+2RQmaurMH.wGUzMPzDrvyhKocxgmwl7LqRxAyur2k2PCa85kmYgt.pRJKERviKp2iaxp8UtMkw92FEt4ldnUYjWnGcPHeCTkVh+K.G5Lswa0koHZxwdWPtYl1mGG.pY8yg9wR43RQsOa5AwXjgv8Wid2v1GkgFhc.pPDJDaCZzKoMuli1J0g2sF9VxfqZ1DM.L.15+jXoAxvqSoWQx2QmGYfAr8tJ5ShqfOiVwCLBQjPz.1Mb4CHJYN6XaPHze+t0ftVdsKXQ01SaL8ImfCAqe2h9jH6DpZPXhlXeI0tNpke.pTYk.ZRNC+ikjPS9vIEXoinxbZm7NQpEFZEmAfJB8U.D34INTNzmxfUxrbaW9agbIUU6Rj9C2nqWcvBlLnUtH0mylu9.GQDuVoAhZKp2yoWKJ6JlrV+IM2PDPLUubttkGbqYPtsLQspSgt+4.SDPmWeF2QKqL7m0K75MOFnXOYnQ52qxC2KVfV13wYIfLw5DdXT.V1O5wE0d7LbCUB1tF2Xe16mm4cXvcOucTd5CkGM6b7qZRuq4lEgK1+ms8lNA3mzGgB7uORwseK4AsSpoW4cshWVN8tMUEMz.sCQcg9bnFzrIjyjRM9mf3VJBX6FAEmT+3as9XJDPN60RiK1sVDIB370RMwZvVWoL3re.2mggFb9SxfoxlI11qbhZAaYrANUl2R14Km4AJQ7jz1zUaH.1Qtj.4E8yITuTtI8h+9WTo1EuUGsoUCJgFrqENPNdcQPndvL5qeVu8fzkRUFK5Tvz1AoM.McjHjzrZwlqOj9JselwoomjF+dPCkg8A.qQPsSU2P8I5L9.dlk0sDcIW2IaH0RJaloD085u6nd2hvAa+Ug2THOK5eqMU3Dmk.uc2WDhDa8JFxETOTki+gIenW5NX0W53lrr4OnYLI8ih.9aWVPcE73NxNNoqwpM1HBPcmdckAGTJ.cRa0xE9As1w2xcNTsmE0J872coZS7UjFmY5fQzjyd.5Nd7ja3ihUuQeTWMsIcZF6OItYdQeUF3U+CUPMCyh3XS+xFYbLJNcTekwzumdihuSgvgt.55bWhc3INAxegAKfK7fRYUSAlvbILK+411lY6KpItb4GohhDVB+wRFg4In.wJ7X9bszzHt2ioFvfOIuMXnGbM2qjbdMxU.5tBrkrgRm7cwk9m8dzlQBzbjH05O+03E3yysFuUYBP5f8kgejiNphBUHjxE5+foCp3JUjh+24GbjXQsMy.1qBWrTfYIJMk0JcXtluaVaQBaGTQsMTSeeaeqtB1jCGm9ix3STwt6917SDXIXuOzvA77NHAkGwJt6SQlwDZkv1Ccyhbq7C5hLA.nJN3K60Wdo2vMm+D1bucvXgxjsYHBUzmVkykrQjrrYZoEiBG88s7jHX0srzh+H1sRmCCDDdBP1T1lgv9zZx71SWWRjtpOyryFyN4RlggHguvlRuLznP.tV1D2v2mu+z4t5B1pfeUc1aWT2O2Q+z9zL876Oz1nQo+i5vii.hPLNXJMSwFoppqErz4x1zgheC5R4+inB1SgufQJYIIUJ88m2cZTsG38gfscgkigN7In7R7cuk2Qc2WmlGYNtgd6xE8uYfRF7wDrhAwjX3k+kpG4KGs7joypD.fr5Lra5KgL2Y+7dPEJ1R2Ms+eNJDILmsraH3jK11JLpNptsSC1jAcPpmpzLA6BC+adZUTJT9OHxK50VyYmr8Dqf3eZL6AXLVytvogrkiAARcZHnONFYLVfd0KjoeXtpkuQWiMUgXM3oYRXRY2nSxhjkqDIlFKch3qbsMEt+J2chI4RWpszxXWXRbI5Yl1W62XIBGbQci7IVTVQDLHcwspO5w4fh1+EoNN4jwRk3uraQghlwQgTm3CRuRGdeAkpX3D1QStrC7mDwKC6bF5HgjHwtw.6wDWn1TkMjyL.iL16pqWvS0yb2i3Lr.q.oIzp8fzmBPr9XUomRHljQeZG3JozEtzBmWhf3WiLbZKM.vHPNyNOKuq0WFKcgYGBpBPDe.42EekLyG.gT5U3W7.8lx6INL9CyPg+jWMoqtYCmohP8ORKTVmIN3Nd2yP5rkaKl.VyusUR56xIGl8MgM6BBYBRJiZKoSVFdftZUZsXOR3x1OLlM.t9GS+L3Hcfhd0Tp3cT0RWHZynTyjfX5dylL1xlHwORGS14M2U0gZhGGboyDfINDk88SCRx1ENalq58qTC5wN5OYLtji+xPB6ajl8xV2wXQ9lcC9p85lq7yO7sw8Jn9ZeokNw5mYrRsln5g5mMfqnxM2I2shhNEar1tffscdoPQr9.U6P477MYfV2notxUSneniU6xAlTp4l2cH4uEzJmNQ22cTwRSmwWo0nKzuPgrt1tFhQr.tR+ePUch.B4+mQyGYwFxr17K2A2z+QMZ0p4+SI4S4Ew3SBebLLEFjskLYy1tdC0FJQoj5NaEvrLi82VwMnSh2ixK0GIB9VCRLZWyVhYzEToBP699m2fnzMTML79li.ra93peqPm5aXq6CDLunv.s2888HTJjlDrV+3yzDb+jjADsMqovFXWCc8xPwcm5ZCJeAhDNtXGaCjLCfuYfdbktqHRI4fQND7eo3covtxohZaQ+oA3rMet.m3PNPej3Uw7HnLlUADKhpnTdVjeYvYTOkEdpzaqdw0VCULccRjyjiiifogEcCh4+VGTjzzATMiTPwMvX7tYtWCNt6IivPljSMG+K2RLA6gV61azymQxBdNbBhC7YZMr+nhK.SdiMjhxVGE3vOKQEv92o7sPXJXfLK.qnd1V0SoCZU7UqRFQRUa+FX0UoOp0w0XKjkb.cByXRxqfLtU+nDnpaPoYLsgFvios08J8fRISxpyFe8wbZE6IZdiz1UNIPdYwK9tYpykUmoSf5U3p9NzuUBnKZcwTdpsRs+QDK5AUn2l4vQyOlrA7TAe0A+WxuPlyTHRZEd5ry4Imao6YR8n8I+JfZJVz.cAfyMFq9EGvKiwnwe3drNFPJWpkJBx1oGDOf4oNNRfe1+KJloyIVjhIFzzn3cEX0siySGizFD1AjfVLxEi3ZJAsLlOzRce+snX5fjxWQYqORdN9MsWl3JWMzpdKxyBLSuPSgeha3DGOXS95V5t+YXYvrad7zANEc5lMklKYAVe84aAN55QdRYRWbwMuSyVSBg3uYe34BXA69LVwTHDbm5kJ+J.LxYbbdJ8vktTDEyJ.hd2ouoQktRMs7vCbX3eO5LvdLtaTc9ZadXxZfwZjwVlmGcZ4SXgYJkwBElxD9meheAo3qxUiDXiB6TuiIXbtwanrW7Zu64cm0VyDL5i3w1dwTPojB1GYYHYnvZ1fiePvi3NIO41rO5pG.UnDrW0bs25zhXXoEUsHCd0wBcMCLQVPOaJIjRiiiPvF+5pl3xtmAMtLOlrj0tyzSZhJxLr1KB5NSer2QGJX5rJQdvJBXhPzQxr0Eh9ps4W7tr5g5yirutd.7LNobOac5jPUu7WEARi4fKbonEiwclN8q2jLqk9PHDjTjlo.0i2mUnJ61pTj8bPBULG3bpA5.tgzeHLFUXsNgUOa+KXgCE3R8+ZCJtqbt6B6v4TKkHzMVVx+zJ7ovxbTrCnDKzclVOgk9z21itnb9Clwa7labElEvt4iWU5hj7xZ5kHdjUa0Z2QH3Zr0pF55DSvNJLPQraUVBQtqhQoNROeKWTJN4XBkuviqAq8mNzcT7J1i62FhmHbLsttatDb+UXGwGEFEhx+3I65RMW5rY5lF3VcS8K9qRieoApcNMzADdCoHO7RpZRO0euK5.nO.D86KxTlaUJl5kt.Kg4pF.8IwPsAvGzdHWCowsLp4Srzp0buKEHqduHi2lZWeulfHMf864DsKOhjuRzHdC20pAVAenMLr0.tKVvCaopNTOyVs5GK6Z9l7EvmwJnUuZ8VlXl5qyu099mwPbliZRHRT50bmveJksfpszd95vgiGbUxEl7eaxMoQOEN.eIkB7tzg8XPvHKY5CuzkJ6qzO3jBQTpOXB2nt8VDm3XkDGnlWHPT3a76C168c2nCLIBnBdfaZ4zRLc4vz5kP78687mI9VY.ZgGjl5PsC0rR14gIxUjQpMarm.6+uNRZ4QI3Sa4va4Ku54gEN3ZF5xZtYV3Bn+RyRi8FArBpIm+qLCSyq58GndtvoL4ctZ5kDozoA.g8l7yYZMZsLKCfFuoe3rxmuDAoM0YUwiAzDu6AMdLRHsEH9b7TMMumSbai1uJFgOn6VrzYS9Gx6a.Pd5gw03FEBTk+r8vM+GRhNP+LjtEnavqFKLPhmGNKGDytnA4Tk7CKdwQJCEcwT8wWPQXCsJxWza1+yCFbP3zg2VYMKT0VzNJC5AiC56wIxO3GXG.bGpDqUekGW2IaW2HZ9+ZPaTVPVI3WEP6caWRzXTkITadkgY7wplMn12xFrNU11xWYoYGCmVtEBE5ajMVvv6zJTcgpv96v8GpozoY5blLoXk5p3RNVLd9ilaqfcqpWH9e9J9wd0xda5zrdCYbxMqbqTEsuMC8VFDVMJB9BnxwjmWhsvyFaCqQMp5Ov3kjlkjcic7S4MsK1fPwMKb0UwvzYKj5sqVXd3Y6Xt6.NgJQ7VdGXhGJrm3qmZooxuqMt5v2EiNtuJU15sJkeun2Qf1rcck9cyI1MlWKWLGRAVSU9wH8Ut0ujieG05ZITuJohccaTW+U7DgXLarTb9yPR+9TJ6qcsclnOpXAWZ1DQY9rCimo1O.9wMcr20L7jXQKX+hFc7JyTgjHH3c5cJvFrDqdnGZOJp9Hzp3ufpNgWiAq0abpWGibSMUjXemO6xzv8XdhsIoBQdqDNNVqJo1sz9Y3O8sJQGCB4QntgV2Pt5GfRQ+k1uKy6P8066+s3a5Y3vF.l+5sOBj40BJFLwmjdUM8nNN5qXFu.cW1xdQSbap4n1L2H+PgYyoZO2cxxrnD8oLnLKxiPh9GjUa3E7A6CwcAFl2kMEq5939cx13HsarzA5MLLgQd8xG.KVOHXQfBhk4eWJVhdWwmr2JrtXeiV8oDg9hfPlYPPc3U32pV1lcfV3crqDWiOu9VidiMQm4zF0CbBlGNk9YHm8xlGv5B1uYtT1dCmWbDOCLPMxBEE3zNYplvSBeXM0F45qozoLBesXct7KepHBJTLbSjCjnlreRzNaVQgsN+t670rTrGsYnqGKmGXmAizPEntU3ud147uFSMIAITMm65Zl8zHvoxR4j5sve3yP2H2srPYKIPKrI6wEJu+pLs3mrT9XbtfCC20vhC2H8j9w70efg8o7PDY.Ruf2k1jTs6EMugIivw7ZDwK70y8Ltv0KhnzLXm5XE.Ye7aB4mZECRFGmRCfSPgOydeiS911i+8wxtztvaYJxwOi.BxVToB9hiymRawf34fSCKklBUVMppU12Sr6t3RxIqmpWUtr4bVESG16WBJYUixfkgL0XJoAC3ftV9pPaq6dkEkRCcx2zZZYKiwIWk7LNJ.I0URf8oBI3ZsZzIRsSBdLvydHfTQr9hFvrxDPMEkOeV8waEBY3EpuJSEdR98.n1HrP1BWkLXK5kSzq9Nx7sTAodMNsC4aacbnCEG3oTG.mQyCiY0HjmZ8f2LI47FC519YOhf8gezOc3b85dOVh6ijem4SSR8i4jB+8hTKqmolPb9Dy1Vu7is.2a5GQd8aUl83nhEL9hoT21SmYjX80FpmLUFFcSaL4H3TIMXXiSK4rqz4h+R7urrRpxzqXc9fmYZSOcoA7U3PSbpSanWbGQ.4g.y72lggMuQeJkTLgZ3R9kMD3CvwuaBkQg24aKOMV4XocMv7vfoORq.b2.C9RDCJJa.6dLslY6ML9GVL2YHjcmI1ZYLZJbQYA4vmMastExKBnUhcOf7RnbhiZ8JReK1Zy+yHmxNelDM0a.09.52Qv0SuZwZKhgaonJEVWeqpVk.wmYkMxAp5.RscytyJfQC7hT75opHf5vcRXs30aZyPVmw.g7daAadV1M6PdkKpPwWzl2TBneDFiXJxF6Mk0QPBe4SmWjHrdGzVWa+AmxWyZntHKrHz082uEB0N4fVaVNyVL0.pGOozdO8aC4nlvoEnmjMXrCBz8sxvNJRy9jGFMfTMj40qydp2ZwuhW.QA82DKPNVMSfeth0pDdhj8aAFyzASrFyR+oKIT74PFiCXaWlxBw.ff+26VBkv99DAWVtnha4JVu.CqHfBafdGL155EkJY4fbLszQ.clmN3ZkwvhMHQ62jslEIrpayEmF2KT+ka.dOw+I9Dje5vmCvH9dtasNsKGCNctgpkY3OAOmQWc6VQvQgiznqJGfcYOapJ3KFhwRJIFGZ.Vr0M3eKQuPmNvQKOa5ALXMWu8U9MyDX5Cz.AAwEw5hLtQvEq00MQ7yMG9d3wNZOoVi8LaxlDJqImIWZepx.IWQQP7.2xxJTs6T52p0cbQTEYOPJaCOcmuvwti.OLd4rAM9Yc32JJZ1n4LrwWsfIBhW9WVJevsej3+tr453eE8xyTcs6fJgF8PNUdYWpfiWh9tnKYPoOIZhlTwt1R+hVTLqHwc7d0yMnhOpANO5ApT+VV2l9X+3EPwMCWFWu7vrkxWruKieWKezC15+jIF4qYwogWHVoCMkyBJzf5ZpyTuOX.zRLWpTpiaCVDOE2WgHY4LFQZ7dMG2jknZUN.kKYvfwFiLw4n+48eLD3td3VsBAUfZ73wvsBz..zWptJLZQIpO1dv.a1iZ+O2FrdKk4TMrkTTqbY32uuCsALg.UUKtglnOk8LpxYMlr5dVIZKf8WPlO+d5XhX7I+V2BFFuu9I9sOBkMzRuTRd6.72B7wSDxeeSmudU5jxf5sOTEo+Zz+VkENVez9Q9Fp9Exgz400bBNhDDZHfkQ96G6n0JCmK6RHyceQjiOWjuLZDceNro+deDXXOTNJHHDC9QJBzkDn2RxahjYIvetmvqQh3sQzk0bi1aVvU9CmMV+OiWsg0IlZlWD6psGiDfnTFhoooOMwzNfKRh5ODYi5sg0+SGs44UPQAudrbOlQMD+0mef0fIKBn1tCWr4l7xYi8RXsQqL8pJsi4UYxMW.Dv+MuErAwuOOxs4j3nXL1Npp0WVP5exHSam.E+uMZ.6ogJNYneopsfxaKcUemLNM8fd.evR8gPBZWu.jc46T7TNNfCcInLR71XPQLIYdRDQ5Q1wJFN99eaJD7KjzzW5S5ZwxwWc8hPIVfCJ0CBCBrdFcn5RcstsXYVH1EiPe+y95uqshbnNjUmFSRiq5V5zmvHReV9QDe9DYO+eFzMR8qNpB2IOhFOB0iFMbh6bb3xwP4XCZWi3Z3AhZhRDZGh+OGCYUFKHtcRBvcEVdFLnRlTeHkIfWFP1LxWQ6uj2GUQ1gDILBL9zEN0hh55PstQGrJfsOQgZYwvz4hMUIKi8tyUuxIryqMZKnyWYl7dxiQuedtwa2Ej4N8e1pbUTbKbhYdcpTCq1h5ezjY+lC+UD1CUb3U0ruQGq2VjGdwUinreSx3eJEmTQhIXqEYfLQWXpYq0Vh5su491QxaUB2PRuefIZ3HULfpYYa7+DN9tHJ3JFB153XmIa7DCfK1R232AOsGuqWhAdYPLZR.4xjozF.xs3ftiT3rekFWSdKv832rit2u3gVkXjev6WzR0v2JzGV5pnLrjXqC4bxQU4WVioHJTw7Es+55fVvNHt9icdK8y9e.pLvKaAN0Ird8ZKaRDD.Tyyx8gt3ojgMVgTEEZ832R3Acfo6iUMcz91Se7tSFvt7yaln.NyZRH7Pbn9dDw4pohazGA3U4GWFRowtmARzlXGIWD.bDx+elAHeJmZSgfrDJCocwpecj8mYTuo3QZSp6uSTGuq7jU+5CuB1DVewnLDDT42jSywTP7vivuJFYkP9uW5n0Ssz9+HNJVjEMM18cxImhmv7VTCu9ph1N9dtuK+q+iIBIJ7JhEVkxOciEemoNppWSBHHkCc5sd49I3ufVIHJ7C2BWJNJu5cxl+o.NgtpQS0CGGxCENr4Ix0fA+aUMR2Bg4RDbEeFu9gssBepaHo2+fPC6VmU+KNqUGWV+xgnsMQjAOtsPLxBmuP6M+FOArhsHQGbzytNVIx3KstxQNL4CC3d3of7cn7aR2Fay08dsjCILh63OGuyiTuCip4x9joBAMcx7Z3zWZotEse6g15MM3i4uUG1QYur4bLekjLNWNT4w4FHJ8Lb587ZP1N8.ZqHrdFrQFX.9Zn59nMI4ZQaBUFouHLkhOA1yM+sWyYrntiz0IZG0XJbYLYIUaNGrunaETx4UV+LVvcEUjaBuBFdyW.eOd6nMMypkkVmbkckyDVAwVfzek055TbMxUTxDv+EkUctOV3.M7O74heBL13W91DiHVXOLC8ZBcds1HUJaskXw93f5dXIKi+7dvCU5ziAeSWsoNr+BnGqbCdigerUgz.Ck4QI9yDaAWoZLpi2P4Dp6KJbFZA03TED+Zu5d4qe+ye3H0XnWuFa3f+uT.0spXQlRNM1THHKytSg6Su8Dj5rOBV2dX7GIC8TZ6Cx0eTox6N+DYiWSbgcfYfdX6XLW4Kz7X4g9IDdAyIkTLpz7eqmExMQyMfC8lJHYQ+Hv4C0sdTcygz7CdrE0RJUwv8tdEoKyLELsueDBWLiR+vwv2nafDx+ef5unYkNGRgdQbM14z1jZhNMzZpQzttc3WEyBRfDk0Xsrc1zqX9d0gljhVVZv81hrCfYibBI.Rx.ee.Cqv1LWTveWb4HvQVnGuhB3X40yU+rcUZx4rwjETKNTByWisXkSg7rGd8TQI9sCXCgzwH9TO.nee76vXV471HfzVtH9GPPJDlIMF9zcsyyTLKoUyZxi41JjEVuMS76IfWNYIOMPBY9C6gcbnSGTr1QcYwUyKfZFGJ4YyK1IC6dzx64.QMt0KJQ.EEkga27xfzCZAmVbP8.I9jewCEnX9RbPxFZ2665J8hzpjusdEHWBdK1NhjPUN3X7L.al5RVxC.bp+WHjRJ8PD7BYqPhAhSBqxh6mikNc+pGqkV.RsgbKLnumNqTkLqDHLd3rYUL88l5RSGVMWZ1fD3hNqv0je9ykFr8uKHSQr.jUfX5eJpN.AtAcHHFqAOVvZ.7SvV0McloBBXD3WRpOylzzUVDlOGyxYvHN5XFl+M8kGjWnDISOmxEA2v39LSRpO1O1+UJavP0+SGYsfiYYk6WyN+JXlxUWgJvmZlKZa8UO.jw1Lg34Yau3FAOCiLZPuUjB089sonwjfZGkmwXvFzXLuXSc.AxcRHMQn2kGbpOXKay2MPIwz1XBLfc+0KHBZXtrjEo7g3Le.k.GDQEYjNST49FNDNnUQrA6zGLSImeRdWF2YahSRVqtmIeMYmOFZnHTIu.2Ru9uHq5p.nu59BivMmMfpfDFLanzY4onVoS.A7JEpT43aDnA8d59VaPJCTQ+SPcfTEzrQI58c.D1nfEcUYyDeHp6aiAP8BPy5+HT9rVVsG0sBrKfpqVSqN9zxQCYalQmSL42Cxyc8FTjI2s5pD7t75exYNVJd2yq5w8Ey.gGGI21AAqgOWx.zg4gWElJGiZhycKZndDGfIzO5Yz6wqk5M4HpTUVr9khQVyToxdd1AAlg0nUWfCbPXPv5nEnoSdoX9AZQFLyXJWUFvDrp5icdcO2UgZ13.JNdprKSnGIX4ym1Bj1b0bh6YQoTfyC6rNMIFGkkcsXfFTpj66no6gAWAQBsEijPpYIsp+iXmfjW78qnwXGNvPTAqgASoHIB6r82p9b+3mjiUiSTTK5opPGpQ1nY2ffScXYEojoJTLYhu6Br.qf9TaE3xjXiJNzF5IGJwkjjjwYzMY0AM22Nwi8BIjxHw7JGBPwd94y9L1fvFhMZhuxYT5+X7F+xo8PGTHxgxyLwfxUc.AO6eg2HwWZMnGbXufGBPDMfizuL28LehAwsJ.z.xXNmT9z7BZzq.Layz42wzBoZaJR..9IZjOnjbZ9EmJtZJc8LLigSGUJplp0EYa9+Qhbu4PLxwIAKl8EY9GlK5H.0V.imfdeOfG+vi22itdUqcUd44SjWU2fN5syJElId218C3Nqig118EfB9tyiPP9nxcv2oNLLXWTA09vq2kFmqNu9JE7Pw9NzJhodUlye+kk.bdpgSP2KiDbLg3LACZdTBk4CaiO4a2KIEANRRLCwhirMp5c5va4oLW2Y6wSqYylLs2SS5fKE7KUhpDD+C7m.Z0VOJQCKbITuE1lE2yX7p9E5jTDju6Yrnp91y901iCYrkdDb9M9NKGbSlQ0hrdKBAUiPrq9QONRSb5+Eww4dblGue2RuBYeEaeV7NV5nDMoxdfCYiO+fPoZeQENFvaNnfjvlXnjnnkfFMZyRAB8B.hwnQFHHJcDyP3xHCFmtbyHT0M6Stg1OzjM+4vf4JQTZwvYaRQeTZ8AObOtEgyiDvgaQUPDs.vZWpCv5n+QPSUXdlRZ7R8QTCq1y3LT7i4qC.uaPxDl6XiBPcfSwRBs3oqPLbP3qB0s9KFCe2SPDFPRgHCRXeFufZ9HlgxOssH4V+B6CFtKb+BZs1KYzNk+XLdyiTr17VHqlLWB.E2xu8PP9QCZomP1fDTbLfPxnUSGmCLs9Byfygwr9mKkebStDcAnqcsbYby7sxrshB9r7ZwMu6y0rI6Y63BN.30YsY6FX.xu7W6N5JQkZ7S2bVHjpcc9mBgnGQpxV8NYEGsK5JB+15rnv4oiyCloB3w7XEklAubBbHHjBgYmgsreXadpRDe1qyqAfNDmAVdtctZdkxX9MYwQbwL7ZX8sLK7u4SsGVJJiy8HlOnxXup3yLjKxYo.F9lMkhmnQBUfYGJYcnULmx5zNrsYhXbyMaogLOwo4effVG1A1cvx2.yxLybfEhAEzWbIJ2F00bERsZWdB0LDSvW.M9RIu4VWu+8qKwaQQMPJ7GCCbYMPraXA9Jwl0bBZMsJa5Mt16TOZZ6bjuAq1ajGB1DeVLwVKC76HpGyFxOdgCflb4c0qYAMlYzK7ihBO6aBiGw0eVvTjCx6Ib1fJcoTp5EuIS1yoeVKAtGmE2rBU.gLdZz3lp177Mn+Cbb1Mph..rM81tsBAtDzMP35tH9gVOmjoeFZpAn6dQfYwmfa81ORrV4yIGm8nbqnoSWZlDSWXp081SfgJhounxjF0Lf3t2g008DOuwECHLnxx2zsI.2r5A4mvua2Gk5WhoN1TVgOGARdAYYnlNmcdwDvk7lXIlqxFA2E4dHGbZa2IsplU19DQiu98R.hxLyhbj7G55bUyggPF7+YpUYqmhRJ18CQT+NYr7mZneuSz+WGo5aVy7haFPzx7I9LR1AQdO3ul.qYvZSFLDaLqdljAcZIoTebh0gZcPHWVnoGfThRr.FkTyKTwyb0zUacNd7rWc1QilVhQStXYvRj8136ALTpPQNPPyM22HP0ALI9MtCjnE0W3YEgCbSEhid73UTTLBCKIeg3jqj3uBX6RjsBOTQlH2APzpYgZxHxwIuAZ7O8IXBfRm+4lMJ9f4mML+C5jKan5Az4hZryB6naGquoOgy8Yj.SwFpe49Qd5Q2B1AHzRoJOQ7+mNRdspSg5NFJ2+BAY4do.2zH5rgQ.W.vKJJpPWv..VhN4vHzeHZ.vbG1OekMuVvJP7sZTOzD8DUc9Z8Ak7tDZZgb1Nb.lH0pg3JrJKYR57PI9BQWq4QKSxuuXaqsX90Q2y1AAf.YIS3OBdbWoQP72KdqErp02Xua6dnL.9LjwQY+rdMUKk624ODBK8q2utAO3+5yRTmjyi4CdYegKMpfL5qVbC3KqGY3AAUEjsOuCJPihu3LCujQvujTuODNltdM1ZXg+CIEnQ6vGmcHVPbcswSfEJNHHwDKO7qyXu5jEMQYsyrNPx0UhKKBZfG5NYmXik67usXJtZaAA36n62XIEO6b9XIUUZZIy4bEA1Ps8U1CN6tSikPlKo6DiEn5BMlFBUnQrKb3h0isKPMUUNb0uFawhzHvsb8ecexH9u20ml+l5v+Y.hm2UVfR8sEQT+gFM1RtBHy34dyImjY1qf+ktiUcHhX12OT8pSgiewIvm.QdWwmd2mWw+hNIFC4O3dP+Ysdb4UxP4OWLNbx7.mlOVbN3GahayZK+Pz5FbMXqrPWgIh0yO.W+DAF5cx3ZYrgyyKbd.Q+ygdWXeTwkDxdftA2QPd8kAGEdPmYeGZbhB7xuslpT01CSrAu8TMVmAuAa10prHFP6BOHz0Y6kOMQdjMu6B67uG0IRVzP9D0cHjHChYa07yzgYRZ0kJ4mApHn7j2Eiiw8rB9HMMT0lIo0j1TTtyZz2g7CRnNaMrQMHTCPy2BG0FY+5XSS6wKE8DrbEaBMG96Mna+Aq7zdnxs8yJpEpmcPYj2E4K1ggMms8WSWsBQ02YUVFWml+dx1aKXHVUOHS7F2zdEITyh3b2Xb5XTErUiRCL8kYR6aqVQ5LZIuQVG47VdeeR24BguGt2KhvBtR18RGNscoVtJIj9vhH3i5ojBk0nxqeaUk91d4N1lczyNz0UyCEBaMz4rldaVklhfXxr2E4khxmYFAA4UAfy8LZ8O2J.3MUUZgs1n3WIZ9Vlo1adbzP8NtioACIByUn9RiiCnnqzpxnP54+SjCsrAo1gIlPlKCxEpIHHSzbaeGJ+GSeYQgHn4BZq.x2n65QWHlkaqbW2pWg.4yrylQIoMlzpAihC3IzSKcvSmKbZoepfMmtLZS64jgLlP2gflP8oWs8js.WiaI+h8SVEUYWY5hovQ6t5kiQZ4i3plzwiMhVx6WJ2hqbg.iMcJZjLu6MOZzfJjrDID+c37oVY6N3LVZ23YRo.ksjYv5Glc4cp9psI6fqaYVl68yYwRaQtvJM+LgGtoWo5U85LZJqrGmUvjJMfKuaYIFfENo7UT0cw3vrRJUxcElYInKf0JDuh2zjnJKqABRmm4Jw.fKW9Jrn.l+mZ7RzTXgr23vXEE2UAHumN7ObVXKEO2tPuavioF1FyQiseQcdX1o+NpIR8j1Dxka6..IX58rBr3I+Pa88FkbeCkQkdkbaKXT6al+CmW3OvAZDDyZN1AEotjk2Ft8yiJa6hsIPTv0DOSyV31ATf12tS71L.wetIh8mwCKJoGlXAXhW2+bqCtNEFoZM5spGWX18PMcZQiCJNp5b+D90kLJdlV6boWV2Oz8SyExBJllCNn1vx68hYbBghsKGco4VUW6yVVaqZuWrWWKVoc2xt3bVLNuFE65CJ5t0MzEdMq1NWz2uTqvOwzVKS4CC2UiekEhQ54JBPokWZ8KqAuWAtuS0Zh2hO3u66N1jIee1AhQ4nyX0Lfn+FfZxtRg7nociqIPIxGJTM+HwbdJcxSX7yhHjWv0W.X1XpoXbzG.IJUAUoqU454VgDsTzHOTd0sM6+z6CKUpggA9DnecWNZYtoLLB.x7M+pr8P1xAJPbsP2whqDaalKt7ukob8c+bqSCOwfpSuF4d2Rack7Cxm2mub6rsecCIVXX4RwNKJlxXrftvNZOL1h6dpWmXTVlSbCcvqaE.mYpoujmhFYxbjQMGSFGD0K0wLa8RMeO86EcXrd1wTRRX.8S7lP6CtfMTJg1VndDws2lhAzOASy7iNde192Drdk+E624.zflQcz0clHXTyTHMabD9KnAoc36VdWtGdti+tXmG68SD6n1FKY4E15gs.E92BTsyy600qSGrrJ7h1ecqD0NZ5tE5J0T3Q4gyJHO.SAxaD3wRc4jcTDpMY.rWxEkzQBjCCQnlmeK6FYOaLT+y7O2cz3osoG62J2TLJtWKS4S1H9nEBs2yNENDwvi.NCCTGPXMCUJApYoscy2oxfWgk53vQZa1IyOGdvFsFzvrgjqsh5JMrR0gYoOaeFAy6yJLVX3+mBbGIH8Uus0uRFimBxX0+UhbWfIJzVW222M0U0deG9nkF5Su6W7Nr3gwpcKq6xaKSW2.g9muqeFKWxSFyg5fEDkzwS5P7vau20WSay+3mWtw1TzQMfnLpmJf.ikAiFFSwDfMP07bDTXgH3sMCqXGC2NpcPPkRDpQGGh2fh13Vyw4Qmzqc7A2tY0GDlhfQzWTF5MPHxB2w36Gw9FG7KgBJ1xvVoqXSHi807OvuGWiAKoLF1qB0tHJa6QB6e0lBmR3knKMgWrcHN9q7ntclvqpfTk.vI4LzkQIhd7jVsrwaVlRb3+YvG0C8yprZR2Q24xRH9EATnLYYZQkZV3kwWJX7WdbZbTOvN1MXisCa3rZ.CupyzM67KKAh+8c.KLeU7ijNjwBYtO7CfooX1P+1+UMWvFKrcN4MWsBE5ZWLDp6MgQzK.qOVV7bC.BWH2gYD4GzTDVZv2v73vB92IjKhrzM9gWyiGyhC3dYW7RwD0rV9nWPmgfGmQi4Rec5wfCO3pH.oAYjsdbEQBfyKkM5LZen+HQzNTKkPsd9gCAnCXDhp3xia0crs4b1FyfuB8TEKX1rpsQ.KtwcecqtIZgmgiQPw3U7FiwFeCFyhwnDngLG9SvTmqEe4Pf14ImLMF4iJ+104v2.jvZIAna+0DCqkbj+KWynBtczXsKc0WbbrhUgtnimg8O9F2NJNBTD96FOCnXEQ3TVfnfGJgP9WHJw8eaWq47OFRF5ZWIG0Ix6U9Ample0P40Dn5pwNhNOQDDuTv9iF2MPZ1dNaoQ33ItZrLcj+ktVPv2Nel2ax0HqUL2MqUvYJTvDPvbSC8tGYGhdk1H8vB+0wTR8NRhozBsajBB7BxMTF6jxdLVA.dLm14VtWDI18dvfBvCoB08BEb+9RxyD27riRIuJ6Fi5kKoPzpgSDH3dYuzfc+xco9jZpuu+eHWwo2sS+.7GXPBSSjEHl0URtbdGfBl1ACs+If1ODIWi99wNp+rqg4ChKSW92tmjoaV27vpkZsHW1aHrxBa7489fCDLoFQoAD9c1wqJg2H4wU0WulbBjQ4TVwtgGqMMOz+PJ6JlLwN30OhDZr090LPyNdAgjh.PrfVm38i6A9Cj7h55iztinf9+6vmYlzFIojq5L3qlF3JfplC7mCAqHxglIAVJi099X3Ydbfc.7lyff4+rA3M+WAO7Z3.g8nSgzft3qnUkQ6Oa2qeai4QgPu7NZeiq0qKBuFa.FVlpfDsQ8732qQF4eqQ6IeMWuTB9ZpyC8uG.VLpfnss3mer8Pa9InofFiyJQO9XoT3o8QOvmeJNNFehJz3YqrQxvCGIvuPpyihERav4KIQ144pDp1zGHggnNnzL39AQzdGnDPUWUDs24UTr4fAfMIL6mTaM+.t9u6Zv9AhbBGp+vwzC..cVmp+DvuOnbfeOUyxPa2YmSybz3K3DSS3.6L0.hahta1f9tAOOBjlq4QY62Z1LDDyEVscIt5uFoSGb13v15ME57uL5UrBW4EPHbHSWdPShJO3jUf28kxDhwiiUIggFKb7fzZKxWcIMNONjzPN4NFUY+Hy9iAbiY+R3+mVGeTeM.uf21eQw5lcsrogWA3UFfF4tgu0mo9L8txQEJdHB51DgXbv5sxo3ZKRBidP+CqxwmtSFvD+xkUxCBuX2ylMiVzEvQ+ps99iyxsaesPS1iQDXvzqw9bvgLle2T9L1RkNhVMX0gJobUtwWm3yiDAGgB6E6x6SmwQjPm+3LeQhkXcHsljo7hixJF0JULbdhElcfq7Qvh6VtGQ0Cc993g2n2cYYU8YbV14iThAADS4TU8.wKWYlhEm6qApFjNT4ucXLtXW6qEuSbJBprTqgRBm5f2IJOxuJIqg04EyZdUcDYQywap1mdHZvrtcmKTfvMNHwAdPsk8bF91JD9muTxxv7PXTl1Cmlvo8UBdTvmCA.jWbwcSs6CREkCB9CeVUs5hxV0TVE4CmJJb4st30+mA+pcWW.ENAaoSZoQb6OdiI6GwO8y+EBeOiykxZJAPvj5bWA8w7X5c1gKsZFpzQ3FdeKm3c5NpsYx9MJjSTVxgLfYzv+EX2IAp4jkqg0mO8rBZ8gyiNgpr6DqgwcZ.9vwxu+odqhknqUYCE0ZRNYcyEU8gPiHyCuSq4S4mbO0ecewXJdxQ8n0u.CFRoJDIHpeKr6qveXPmrAsBkoP4a2gKcd5OwzQCsgDorfDvPtRqi3CWVfJesS7UEWKm+hNtRXl.GYvT0iamf7sjoLaTRmDyiLer2I8vysQnnm8+F0Q062y4.kxH88QufxO8Uq5JEhxlnmFYX.re2Ct.2gRQ5pEb5RfPH+I8W2Z2.ylXO5HxyPWNAsEweb.fI43Ls0DK0W1+ElO6NntadP6KwrnkYosKag6LYRP4nE.42OwKwELci1+yZRt.qZHyMQAqcyunKrIg1WKUggNBvRULon+UbMUGwZNTgSSvGggskrHWsfTEWRqtT+NgHrQURLjLmpw90BpwGrb4s++R5.jS+2Nr0kYJZ0a2lYzrR3hvbqJWaJkys5km2shZwilYWnCTUurLvakJM0A77r.A9MbM28uw3nJx77NUy0NBbYHDlKhF87FeNRgfgJKJsQk8fp5NP8KaAzAwBzmXWYEwRzMfRSBrpaceWN7d2lcn5PIaEZGSCf2uJWe5BiKGp8.BhjSBl7DTlfGIhVw.AD3F1jKbIq0FHTd6h.faTY72RnxqJgFKMWoCurvVBQoePep96btqmrRpKXUuRb7D4koClTROemHvhNdPwlhHk5ZHpR3Z8IMWQLqGgwOdmYrR+zUGBZwne8cwFymXHDl8x02ryz7rmV8kqZ9Ds1gLNxsnfMVekAjC0SiqcRjBanKZVlE5YvPcJbi3aCag5gVwZQ5ARsoztGOxBM9tMm0HgRpjK9RaBo9smAvc5kYyOrwBEgvGkSBCzDGNrKprPFVjG6arQ.16.V6BpsYvWCKkpmP+8z2CCUxk+zTzSJDvMS6XfL+X8A2ZydNRGOjQ0.+h4svXDX1nQnjUMbw9HokgAlnXkz5mYgs+G6FDh06RcjDqc1s9odbMwWAC3LLfE+bux5vK8KO1JISsMPfvGRRzLJ9EO48ZDhWQKFwaizjofUWD7m2xs1QXcbvIcka.2LZYy71YVoIQq6pmSziOq+nJR2WpU4QdVpbrduo3nHZY4AxHU9Nasnw7Zu9wDqq46iqSCO+pvVcrbaDDszc2tyfJc7qwG8AQzFNhyd.gCDUYwY14yH8nMF3IddfVtvUzrEP7eZSD0u+3lMXqo4d3ejLfNoYgjgVhpBWvxNIAB4Ez5lOew.0W7dTbgv4.I0QOmuggpZOj5oHzgTijJaA..kEanjY1aKTt6Lx5Qlu.PcGLw8c7S5iwHNmX2VJcI6jLwPtz0iS2GkZt6VuCjMdLfHYmYYbl.p+XdCU0oLHVq1WLotF4Ci9g1f.yM+kwJZ+gN.ug15gslVoLrGcQSGx8JKNxSZnu+OEAKKDRz5azaoI5NnN+rJK.aeQlWovPARMFZ8+PPpvzCRqGiIR7nLGk6Qu+xAmD.RLfxUXo6Zik+WwXho3cyFF2oxt36dI2DUImqjjqDn+Tv6yNmqv0.YH.uyeCRKrS0vBDSkxrtPvIbUWP3C.sUAB2LOBNgc2YEwYWFNrUdjd.OSFekB0pwtzkC0wyqGfuEHogHl5mBHVaMkz5AhwL+OgkpR7kqtBWdy9CG5ZUou+lkxl33sc3lRz4kZK5AwvN7B4LQf2tshU5KACTJ3Ht8dTyJrGjKyyrch6DUuS7s11uQBdpR.6IPPg4sLnSCKcKNgg11icAuSjw497YBHW62rwTRExOAEW9nN4nJg8hjHzqduEArvPYIPqWvY3VRhJZ99PEbJCZZAoKajyZLJdI0vVxo95DnOzuQuB7YTNSwul.G4wiOT8BukeC29M.d8fMduqmG2Pe3IU4JJhZ5c3QpIAbZ4WTn9QZMRwkDdxeKLWuIW3Jy5+9wkHLP4SRNKs4BX2DoONmDcvSMRF1zyGVqPTOUXXXlMAUBGcKIjYus2J3Ly6+NPQO64MhIj2aRf56DWbD1OVnMFRthj2igI0qgm1itIhH1I9IziEufcRiVxoebJ0btumwFK6CwVPHWNkZ27cbDNiTmFtVp6Wkik9Hglf+48Zb7K2P5bMUGE2mDtJkWnxPvcZLkH5cPzMOlMW6JaWlKZqHx0OC4iPe4CGsv3BhOYo6LKXjwHVhQEYiDWB+NHWSdrL2XOyczGaWZB8hiia0pp5yjJzLBt4wieeSga2Hw0pyrYePCsRd3SJtpUNxoT4+zrUzt.vYv50ywvioN7lH8sN60mrPhMmKxcN0I8UffOY0QMxdlQ8Ymb7YBBiU6B5FBGmYP15AMrd7l3+PIhaAcnmYqErvh1NB01OcT8uoXUYt.D2nA8NRrlPqzW6l8EAAOf7kiBsUNXCz6zcP+dCTB350UZPwMDqgcEfbWGBXUdFmuX3CzDZufAMTKo7bYhBbWhodb34dTpRuehUEotJqYX956GkrP8T6.Q7McZwI.RjpsRrsfvaKge1T.ydfGplj1QnAHYeW0yo7Ws3nMbUuYyz9To367vx0nXBgxld5qyUoRFuvy.NWOSpnqvARqUJQ1JxXWNHE478lgrV2y.X75Ib0hZVzu3fS05Fq2abPAzjDWUKuOOgiv7zdLdw8GUP6i9PmOAYTXOycuMF396CqS7pVYD3dKYIXbojXUv6sxbAaahwTkB1C5+eYaQd00P8Ej60tzqLM2H.64eRwVcxDfCaa3DwiS8qvCvCRVZ8fh7DD5BZmeROd.+J83yGjk5x+Z4WKru+SulMcA6zEuQQX3clVto0SNow+.M0GvxD8o5nyKv4z5O5n9B4t+9gG1PbhA0W6zTIE1tUm1fw+Irj0YKY08aYwcEXJ9GzBWEn6O+l5fPCBQYOrh8NOYOmK4OlXacnXJBM6Y0vck8lrP1HPcMBxpu.yAHe0oqpB93W9tIDv2R4qVt2qMtmoFersnoorMxpeQk53rwdQqge4y45AXQQIaQ3NFuVgHqybX.lFwncHjSJbBX1wBZzgVMySv1SmyF0YI+HscuhpkE67FvgPHuOJoq5ebDaRQet5UDhO9.ngiGOkkkjddjYu+Oo9CiIl3bIbptnMhmhR1yU.En19YeK0qBh3BgxpDfxdJECZAqyDbiYq6rGFGFY37Scx0JfcNnBkAkXVaZmHQ69fHUifw6SeIXpPu+Zm0+ZhdElQZrUNYydehXHYTRjQJIEVRabMvDTCBiHK8ALqvlaeL0DTBIWpk2P+8aH4CJPU7cyXb9Pm+Fnmt3E62TZIsk3mzgxyfYac6sbgBWaaK5nd8JaRX0FITV+23msWFCpfDllWBiqdI.MHQaPzQqKh8aZa26OHqxBz32nm.u4Z.eoSReNZbPgYWm3oyGPhPGXALpMf08t8FePbmAsLgXBC6QIFlWIeX8hh0SQNE1W4Zx1Oyb74vJqiSPCXfLm6xwnqUhqHckiZPQXZ+Nm12X6CaAa2737w2pbzeRYZ+nrVt7UoitU5jq8LWcljwkTcaBtn+h4.V4X9h0ETWd9meCxspU86cX+FHe1BemwvqAk0Zn1.3neoaocfsMAR6vMt8aB.0WQIWttsHXlMaxT.nw29ujcDySpjmAha6c+FO+NkcIuK0UAmtKTGxplV0FIvTacqyxAOsPLQ15VCqyCF8CSe1WsyeLGEwVU01IDOXH9HY0R2RA5ZsMIftIG3r+snnVPAHTyE.4odBqOHYh1oK2KQ0+SplV3TIeNvJ3uA9RhAFawQSCqQMgUkGoijOEzWJVCUI9fTsWVNavdSqyQSdAoZTDvMDqLapc0Zog3TbeMmxfiBUiSSlIiT7Rd+L1VZF642h0EeEuai99Q.0EY3EFII0K8LkSr4PbeFe1otYJaZs+wxR4BSeSrag6QoPxBSSuLHU9TTTNl53jZwMgTv0MqRj555pLn8Lt0wbpSHhyaOkrbBma70bBzDUtvOinIbVMnRUkJgcQMrbMTcQMrQ5uWDIdsPliJUzBCY1ZjE3EHiMkzKPHOwGVO4g9EPzOuM90JX5bGpgyyNSetA9gqkB1Ik7kUakLpslHDUVfO.CPvuSB3pHOJcwL16DWrpBLyuyAY9axUylnt5JxWSaqa7bCdN+BNsggI4EBWmaq1WQuOK2HfkkaQGBFjnXL9C157ooUyPaNPQYMi7RNwHCEwOOOnrew7GPBbOxonmVHt7gKijXpG8+2rI3B4lFLFAG3f9Cd.kp7JgvWrGDj3HzHHdWm9DSImkvhZoHpiSTJBe.EB8T8SwQfABpaDYfXmPbMRpgF6QXrKMewMfoRQS6lu.bV3wD.8VVy3wOPBz4Nsl8T.rSQ.+2OtPn9AZUlzrOcXIhcEeRlUcWhpeE8.yuEFc1S6.lCHFxk543TGDqzncPNYUfrJL8I3VBKKSiP99PjO6V0bNLKIKUuZs.5Y9g3785NaXKC6TpK5EpKAIqjDblMix0ifEvFatMIKTL1ePXe6VU5ELTxedipB0DX7MemHXdeQsYy7CHBtFeCc3FvKwoE1AEuXGXNkOC1jl.Bgu.knGYyQ06Kme42q01lhUZ4oIQNnYlG+jynRbi3iOI3LyUzhzhj2zQQHN3iqfwzcouPGg6SeD4gS0aNbiOHOj5m6Db2Ej1aX0da9IxItg2P9+ebEQfqVxiHw5bm8VvEx11Gqo+sVrUSp+NazVIgReRCG5mhTVAUMJPF8hbVUvn1XvAuRpLJN.EKZX2UtImH5LEqdt9+cDnNRrYmYKmG.l2p8hvFKVXaJE9vvfxr1b7MDOEi2OUbNI3IHGQ6Uzn.OASXvz.GTbBxCvpylE2vVUl.6X+y497f3dglJ6kdkIx+7gsLbANTg0MYdbFT2YsLZ4yNMAE9pnr9N494rZAxfIHrHwoOc+FLZsGdg44Nn3R1.s.lJSHe5nUIEoe3GJKhMckpqFLNtKW.Am6CB03NVO1N063LDFmgAzR.A3KGjbFEFY3.ruwlVm3S1.0ob2RM4aFl3B.Ddl7fEWBuq7T2Snwo1WBvjS9YuCCcXqM6kGmZsBKbiTwKZ8uIZmrVqfKMyjbZHI09vPcy7IK5dp0J6m6iGKQAxNJAtYanI9uQh7VrEA3Vr6V3WNaixcC+Y7sKTaZLXoCOyjleej8a0z8QrcPJSub0hUl1cJGRtBNwFbmCl1LsaCr9N4EsJQCuLteiU7xgP3Ae8nU5JvEh67S3JrixFruvOv2AD+bcPnsXHl1n77oBgpFV2WoGuOnfPylVlK4e54rb8784oCarFgolqgpgWb4bkW.qEHZzQtxggeV4nGg3bqVT7QNAGZzBQpg2ITcCjhxD9zQrf8ukfwKUCvhhfOPeDI31z1mU1To3Zt8dXYGa8BI+XBGf.FFfwV0a7Ke4F4PgAFXRFQtClgx5+jWMCAwwUuZRFb4sNs5beDAayPh691cbySdK523YGU2LDhH6B3IBYCDhRpRvY5bMTZYRZ3b9reSVKdWSggRgm4NJtQLxf2WtZjyESVuLJ3NF.WPOLTxLmsVFYOF21ZLfghTC+dSyuMLL0RWhDydmz3ui9lk3m+bOuCD3DpawzJyiN9pqgKiO4jcjQRyA1lR4GSzM9tUFESYfb3qiHj.9OFZKWwOiuybd.AJHBZaAjTsZaSUFzukfT2jUtvOyX.5s+TGF5UgNBimONAq4dDkuxOuxUN.NLl747erNAt3mQOcDZOXsOlwoHu3rvbt4xNl8m3hMdShS5qEaAU1m4cLr9M4KMi6L3sW9RS2dHwDiNI+8RpaywnZOgpvOvQlo7j1r.3PykigsPQknU1v8IQneqcA5kbVHokkutqE0ohG5ZbUwCe1hMxJFu5AtDN3pbzCRzV11VycKEgByyQLG62lo8fsMh9.cRsXrGHmlkcVOmohU3BczAOvkYE3yQvNpyVUTHMZhK+.ADkt47JdWUuO+I9cTfPjkHyqTRSTGILTlu0d6Swg4WdDtCwDA+JZ7uWibwo+Juidjis.WIkyKQFSe9OIe1aqHXmTs5+H5kJhgaCb70BWsKFD.T43LVq1qrt5k8+bU50MkLcOqeLpUUJgG8oAwm.adA7HXeggH83FZKv0b2pzWsG8aSjz072BBWig55MUHPRLOuEwPuN7dHoZ9dlGiQi7HYpd5oyHcxUspDYtJuZrtC17KnbSKnMzD96vgfisz29tViGPMuly2sgwSTiYUZAnEpMFq5oZ+9MgcojiqU4Gnnko7R8YQ78AwwWNNPOEbpr3Y8uNk8iwBZ9DD1A7mbxR.+33UcawbaZbXsQvaqhokE7jQuiQAb1W0++IhEuZphtMkCJ11VFDtuFT.yFe+3BJQC.2lRZx79TDDBqUzTyZCW5XU..GBKGn4EXj24r+owztqbEsCZqGXJd3w9goK.bYIExk7T44PNBEyDh0x0lTw5GkGShU4JbZfpF+zqpDA3.CvSHjLpGTPjRY.fLA+An5rOwxYeh6XDTm5yO1Yzr+fAiYwrVEb9WfIQURrqmj6DAQ3ck50vE4x8kvxkPouZjBeC5Y3rfokCqJ6olzh94l.JUeEg9RSfOz3OTBMsmg.GLM1LK48GY9IDxHRFhThiKH3jYd9LcZt.CFNam6JtVQDuY0pggz++iSYY+g+6UYdpnIs3KUEJeBZSal7YusS4EGyFoCyxcBrys7RFMVZj.VK79Jf4VODMqosXblg6gFT89WS7.OHLkO2J5L1Prf5M.kQqEOiuNT5zO3aLj9pB92gBou7wJAYg9cBWTQYT6S10YAtR58VQz4j7oyZaz4jGwFvUfyY34ZbWgcp8Z8RkL811Gu2N+rWiDhAoa+U8TXShdEtKr386W1V.KJVT6adkJME7JOA8CQIguUewRPV80k0ys40RJqlKowrSZ5uA6xfV71MTzplXUpaasR.PnPnqhjJ2U5KSxNbBk5mnIcKdivF9PVVzL0TpQMUHef8w8sXc6S6xg+4C94VCY06kvtlwMYuzMawFHWs7e6yRGIrYIQXSAJjiZzE3EHGC26cOTqKkbaeY7XWI+p+MiitpJcTMQqUPbiPPe4H9qS6kJDgFcPKCD+EBOiYd1fVoSElqIZozJfCjF+41CIAwfiueIazakTfHsEkehXpirR3x9QkDa2Kld5kzHnQsPCpq0C8ST5e2AfaMomLZSceDcHYH56q7QalDr4ltg085dCSpCypAxjIMPm1TafS8092AhD+CkO.0pdGwtQ94MBJjosJzkK.8iUXmSKRS4B7QR3hfkZ52eCtfiNJiRR68gy0t9M3ceuhu2uN0h0ohRX6eKV9eT6LobB.VeqSxGggvTLZXM8aQzJwcsOfdzlb+ApOOhBFEFgXgoRzj3MULbEjKMPbt6WV95mvTVVJ8wjnQv0Xe9lu58yuZS.lJi7s0uGlVO0gmsK3JUTXPlgXflBtDQ8EEP5x4PITC4VMQAvLi3Bbl3an3mcWRfOENDnSE8rbRdDDntmVyMXn+Jv6t6HqULzOvXILuCNIbx67b9AH8SewhJkJIkmlV5Dlfa6L+Fev75b9k9oDz9tndfnsUCS0TP9u5IDiVh2NRfBIDXFrrE76snsZA50KpUaP5PGgUoJfw3Bogspu8wAIJv8q.oqUhyqYOd9wncmzSyqM3dIPtzenH0dvIiAOS2UBEfz1zksQSyhfFHMbo.ESqSsdeZv5WRiLJRiX9An.gIdm.U08lpv8ER9yUbx7SFS5GKuYzlJPbXvIRe08+pZDW8yBLfAGDWlHEsI+MoUsi6iiOuzrzFrj0q3cXvCKgaZZWLzwxR4kte+0RRSsJavQhmaBJdAvMu9fkvIt3vct6f3qpPzkvrrmzEoD.fFHNg9Y3EiW4xt2+d4Wah14rW+ySRA3mYxVVk1p+4Nyb4Gt50gEvpYQGRa7lPsNb2h6lgPIJ1La2F6De5Gn+cyKI2U2HPZRb9WsEJ+LIejvJZJRlflVl07NZmixMY1na9MY+v5Z3cNwwPgP39IxmGrgMVa.ZyWPLw5r1t5cCbQ0JMnc.vUIAcF5ATaJpcXDZrIs49B891HZMEFVhaL8HNW2EvDbZkUgZilnuuXmFQVrBb2CLivWMemDZocTU3PalSrkVVqOEdIBEEG2.FFKRNl0IOuCCaonULgrMWcaOGIs9JXRMWEXo4zYEKNYLSCjKsxaj+ED7oFyIGa5xioXhIXisFHzcPzxwdaI4VFFV+qLAQ5Os1kNihMRxsIcGlUlHykOY6GxY+WXu4wB1BS8moJbR9WO27OV7kpg8JdyyEe9VuYjEhi9TQXr0a34kd+M.Whwrl+BmhFulMyu7lzvE+O6UjVrw1U+T9I8pcuPw9vSQpcwroM0qA1DebzGWGihLNENUrk6W9CEGmzzC9KqDlwlLKoqaTna8hZ5Axe+UhenCONECPHTjBGZ4DG2xjv1Eygj.akwMIpWJ1aHeGYmG43UG3rmStXppyYgVFpOBA3qSzzdqSRqYR9SLMcO5DcLO8cTQTMephBTYxm4DxH62J+T4e4HDdJ60v6Urtdx.2qZ04K4L.JV8midW55W0WsBdyAl1vC.U4pKCJ5LLW8Gd0.b9HKgS5rdQGez0Bo8qPODWkCrZv0aPs0VmxVxzVw5Jm1SVLoJZt3wphLu4BA4GGVOVU7gXf1X8CGKoiiIvppIM593qHXyhOBiibocgpLUrVuIssPsERLvtxrTsuqV7R85ydY+Rpnp72FYELzUABcodpi5rTnEKuHQpjrOe14WwZ9cNC+8IIYy125SRjmw.au3lM4hzbNn5FhhV5v97J+aCB3gkt1ML6HXyQJmwbWZWqHbqHpL+aQ9dKho27jl8aCPe5G.twFDA5uvKnCVZZqxKj16jR6aI+CbGY0zJ3xTFnqk348qHafqcLPLYION6TCDSKiGtHsFrWg8kLwnXWGHSgDBPpZ.lP6yXVgPNRJ2rv8jl26IJ5M5CY+o1KyiaELPBNdr49LPhi4Tx7R1BcCUfb6x65FDKy2QTL1oOS+QlBwny0YgsZJTswhYxqOvLH9qGEZCaoHpdq0HuurtNwdMUJQy2GAi+KgXASQj4LvLk4PMXBC8VycaoF0SU1X+7VVL1lhL5AQ+HOG7+YV16tQYsO4v2FQF2cJbLhVqsh.uk0geZhKwMii3U5kaPT19CA31EbmPut75UcrAx66vFX7KpcRjOXb2Ba0Q7o7QybxYYvyzWTDzBFNWmwSnkHtMuR5pGumiN9U2Bn48GSuF.JnTGElBYkyRUZ3XMQlv+ABTYxFQAIKRE0QMF9xqxiyyb2cGgwZwXG7b1kMf4YbEu7eoDW5qn2xdxAZkQMdvnFl3AwF8T7jmbyvsiuK56mX0spEATJmo3uX9DKmWRPFMc8zbFAKu6uwu9pNfnWWUt9Wxq8dC.XiCUTbRNxDIsn6qqCDQVaEExkX5hTJ4B+Yj2WUO9lS3xDfOt79QUr3Ry4hEz+uxxOIkmND8S0aDB4jcFmL7HBATL429zQkRER.5jtUu6Dw9QdC8RBFNfCH5zQ9+dRMmOwqY01CU8X7i+I.If1uqwDH7EX+dxXVcmO71..NJXaeaeenH7xSoo9JQYuomDzHPs7HxlzTgPzo9prDF0T0Fh9N0H2RHZinNnZ4Sa27IQ7B+CZq2qLN1UbYsaaaL4qrHbhnZ1+ywpGWOLK0C00yr4h.2fn3rZLc3OrsKuM4sZeSTSMtQ1l3h9Q9z31ADy.jJmtUhO8xp397NbPFLWkS.3MhQQs1646wo6VKYwUGVChTwObbVjDyKSTGRLvGemJpaXMtQ75Vsj24SdSTLxQzLtwEMlQglygk4WjnzUmS9Bw3scQmqDH1B5e8ho69QK3WenO8BMNJkenePyxkjKQm+uYmGZLiG.k.mcg+IBBKcSUoNVcbKJb1x8JsMyAYYyq7wY8KmXsGbUwgcYfCxbjSD4mQOm2G4n+UbBFhAJMfFqMZAbwqFDXshOl4Xi7UxioSQ3vpPg0xrTeDFHXSJIf6.auH7MwGGcPcsMltARKlUMmYv8LtcBPFzwlsrDQmsTIiNqhzp3cFNYpqjOASNTU8nbqB23VxuvJp5e1HWi1R6yZSk3Rxz7uTOCQ1GeEWsplTtfJOqC8YAk9lP9OM8Q0xqP1xe0P3CInJONEOSmaR6AZ271s8HV+PffCyFkoi00Fntix1Q9Q2uIVXz4Tx4C2Ys9qu6+PAtyNtKgBQwnWeVPQxPtJHE9lCB0.nNPDR7EJL8mSi9.5JDiBdeygtLtwC8XCP.eXJTojFcOMJXjiCNMro+Ar9cKPo16bet0tZe.MphRixSKfnWVUiF0AtPRLoiVU26CZIjFzp7FOb2c.+NwVtdAcUF1WbVAuoCrLwi00MrxHUMQW37NwBSuj1qVyhSEVuYsT4ipem2lWNz+nbhVG5Bvk7wQk6aSXJCs48UihufzCN5yaENwsJg8lbQm6ZzJBGh0BtgeZnT9LDSHdA3XeSSy.KVBKG1ENd8FpxlidURxP4qVn9ZgOy6Sldz9Mdej.RyQp8Upi4+Mqcqo4UZNt0dJeGvJS+c4H7Pqo7L0GdUfruM2bVT9cj+XSM23YI2H+hbXIrtSSGktdBKqU4q9Njk.jzGIeO09vnvtszCOX6UYbAXaXpHjf8c8yXMgJmEI2DNgGiSNtznf78CMPsFZwWFN1pGrKQMob8haq.FAM4f18ANz.gumzw+8TwEYcW+60GIOFw48IxG6UJ82UmmgbCmHDmy0zzVzgAuT30cW54UEKrckyZ7QAa5rvsoL1sQfqW30TNzxvXNYot8LeGp7mnGPet3TyvNwO42ILEZ4CsBuQSSSUydPn4WzPkGfIz4ca.hlchZF1jIAMpaBMK9dV9NF+Lb3.iszpQcy0p9S4YxHKQCmDZSQs6resQOMLUhOzpAF1GVZhEoj2OMO51VSZ0D4wFUM1ZX0b4jwg13IG5n+tuapZwmkTMPvfGemb2IeWMcfJ2vMEWhIxq29qv2LUbraUEPJjhfDuZ2MDEYZ45fV3qgJh4MRiGZH.nJ3KuvoCgI3OpuwsznGDXMwHIPZY2KvknXfvFAw2snQqpp82FKSQoql4PAwOMha6crBn7PQ9n5Qne.y5jdgIHDH9ih2bLloKHMrve+6gaACzIjDrTCB.ymNgk6kVNMgpzxBUkEKUjtxr1.u++5AlEehAl30aML24amFYsCeCzEJvHmx4DOSIMWjPbCImG+9lsCwSWT3z+yVa6h70L1TSSrKIlJaIyf6WTKLoNBchFsK59KnfS6HE3On3qg4.05Y066Fo4E+6Hf7lA6rg4+iL8hHoNBujtIGTCxmrNN7VrzKBJjfwPC.FWZbaH7o3h.K69xh+JNTctq6TIuptJO8id3K2LGTynxUoQlSD2IAdct.dI.bRYOatbcySxmn54VkgR5z3LxLsv+qUrYhGAK7p3DV7u+jXFLyANuS0mLSV0fotRHil+EcUg8Q328qlHUze0.3gMO.PpRAzii.q7avL0WIjSyowx.vkUM+R7tGGuv2GI9HFaNmW3JpMTdkk.W4zWW+wduyIRpIeHnO5h2ASFBTowsgjuz+cd1JCukJHgA4xw9061TmcADjltoQ1MmgMFLmldhwVoIG71Gi7MqZa23Y4oBPAfu0.Lp16BTbMEEl1WV8GhqUfhPvv4j+YIgPXHG0FYEFIHWy78OY+Eni5R9Ur7V5P8dWSUXxSQSykfkaFfDhShzdmv1SLKralkiPsCoSlXMl4FOzFknuf2FJxdl01Fq58wbqVl5e2KCKDdLwpMgVHDm0OYl33ZtoRBAC41VxbId0ZISlNXK7681BWlx0.eRbk3CgFkpnRWBB8pz+.TQZul8.Q0exuJGvCDg9cPGOTAQHo2YPM3lJfws7qyQ0hEU1GaiU6gz.gx5Igg+kRgR6mGB2JUdbLYPiD.MgJvJ.QUKNVhVOFuchUVTVG0qW5AjDsa7L9cnC7fKGYm8jRlBWj5g.eUSwLZ9dX3rQO+yP2cAF4I.ObVO7YhVheSEJ0+7hztVnDcfXOzabQQEfZG6fvghqWj2ur3xDEKlk+tB.lQbgNuiA2Ea4SdsYZwW.Wh9+pXK4scoZoLIAJM0zPcLd0cDzBERfIZD8cMn0evJ9wKUgxrI8DTxUxWnJz+WqOgIRBNbFyiFQIlsR.XfHhQUGbbCqq6DEqZ7jIvbeOx8OKPTsKoNrQ1SSX4E6n+5Pz0UkdESf0KX.xSCUF0uyESreQbuO+GGM51NlxbYa97vfvFjfSdpBQvPlE16SiseEfmd9KWzhlNdk2g2W9urWoV2gi+JZ4WXPpz6L+0LXPB29WdAnLVtYjxdgr6vVMeVARt184D3+JnJ+9vUIpkQS5T3oqMkGlNykbuH9obv8+3ZinpRcMpMdPwqXA97KSUsVIGm6sbnyorRfyMSxrE67ju7ijLevqJnQSPqSBKIstT7OqfEq6HIq14tPwTwyYxSeXO7JXBtea9y2n53ieHFjvS1E4PW3mcHi0alM0rHSgLNrPL4XxGa+lj7ufGcIsEH8po+eDKvUXAtapD5mLYcAmyny450w1kTs.T02qJa+ZK5Mg1L30HOn8oyCzdsR2rXvMhSqEiMi3W6aNT7GjGha4zasTi.wH37nYO0H1nYOU77kQeTms9W6Hl6FZU2FTe9QfQx3kby77.umRaetzMD0Iy9ikBLsSNQs7OGRFXXLN3EnQbFg2towKg4IvFKWeCn68h3rR8HdoWCw6ZwvzYFRmkKpgSgiAfRuGC0XF6lLMGnjr+HkSMezxlAyxbFP7H2+PeSOcT+bj.Bd9yzdk9lcV2kIlgfu6JabxrfCXDwOayWx+mwE7oDnFmxE1eHV305Tryuh5fQfYWYOoOZ3A9NlnHDKYdpXRoLCheiu415znsFw6MvjOIpWshbJMnR0ALTUjv9G1FBKwOLj.23ThO3xrlkYmysJNYoDj9vuxGb5NyAJiLXzDRfWbzto5dAn4uqIZhrdXdnl4zv7DkA19NsTiyULw1rD4kClJLRGnEPVoeEgcUEDK.Ax46IR6tp9tFwU7vsTFPXZHmZO6O3T3kVPsF0IYXyv7+wT566edbMRJN0IKVgrMMmIRr.0dUv3A7F+6SbHqB983dv8lnYABdbKcpK6N529pxm0uQBtifKJrtSq.xTT9FihAxSqwvY84ncyH5WFloCk0P4j9swUtYZnxLxwbfbhRdpVfHkYiMyRWFb0tTYI3xjSICUi7wHfkMUWiXS2236BMKhe+pl7axiGeOTuoCK.acpaMSvxBjNlw4RGHdjGLta3xqySvcrmeebRPsjhbMF0q4tmz2WJfY3lZDoK.wg4zHyNwRwzvmlPRx0xNagtFbvj66zX8JUo+1xjuFODuHjSUnt0BQkP2Bk6MQLfzNrK3WLR+zlQ6xVyMchxK1zcxsQ1FBqzhGMgzMcyjR9WuV0eO3I0URPj7SFUHeENr4LhtGDSJ.KvcCxL6yNUUbHkKSSJQzBnL7X2lLnUlagCmB8uEG5+wqmjGY6agQXbx9Mn+JKYJv3sHYrk5HD997Jc8HCpTvIX8hHY7P3FpICGtv+Ic2jO9FlDCQpokpQzca6yKv0KkOjff5iG2lI4IFEiYOImEMdEUm3QKNgantUpOdhG6cQPUO2j.VYFsIyR98w8uQAoLutRypaVEkbmQUl7en+6nV8Q6Ni1LLD37QYNo.HP60rn4ui25AGrRpNqF9TrztrOjIUkwWccGJN+F5Kf5dcqVrEeQnORZzPsApVZgLPMBM8ikArzQFwGqRAL8qvDZU7lHYB89novHjDh7Wgmk5wMwNozh6JxHIomryVEWekhjSxU8LbMuY+5K5wiQeVb9W5.41eZgG9x48PXMdgeO806icgMkWnESu4cXL2r5wutPiQpA7sbklKy6fHJS9mad6Bq6hGijDnp.1yCQd43TWRdhqke39WD41oNj35BNAi6Wwh12zlNm2vof07AIZUnEc+ezfeDhhnSoiuTLC1ksSotD5pmwFKmbtkt3OGrsVYcAqFHWzXbgU63bKn8POktEnQsmGr+kN9Vwb7zYBFQXYbLDMgPzTf0XTazRlGrOWDFv5g3WQjc.fpK4PQtHpFHpL0g704meFE5Z.WBrWm78ylJx2eu8vWnOVvXJMQJg3mza7F2oc5nILIXohqch.lC4Sn8FRRwy0ciXORPuslJOkNqHSv7dFqjygtBw+n47pHlHZaO04SIWYrVvWNwsX2V9bhRTJVulAQfQ6de6LdFfgMv+A5UwIjEhREjx2eyjazF0Ez8gLXjqA+WPAefnzwmIwh23OeJLvFv1CvBOvdcb7JJJxYBee7WOPA0Wuc+vHwNyUhetKSU8gufzFJpOMXzTprNggzF+WNXvIQOHe5KqR34LWkpgJJ2eLsVgT1g2tjjXQ2whXCk9JTs+FNBgjvnKX49L8cmiNx6p9ml9YmN4fWdi+sgNAjF+FVC4QX39bjNnfRtgXMEPRSpW4W1eobOFnRNIJ0p.BKAof0kYzKHMopK8K8BqEx+xnhc.M+XS4FpXqnWDzq7ZJO6rs4jxYvJbOX0C5ejS0VMZIp9eg94V2.WCu2IeZZnCSWMVNDzrRWnzI5asiqV5eesyLPBHheSqQoeHFVHT0tKFe35S6lflkXgz4L9mTFXybsjAqdyttPg9.inqB2fufffEiCMzJLb+HhZmhqFa1VGG8KPnYuIibS9Oc.JC3oCl+UYljNZM8qe7yKvOrmZVnSaRe1fyZarFF9KR+UvcVxRzjk.5Y+ZlsOdzzgeRvws0w0uXvSjqA8+KTxd1JnkQq9z1fwmStbASghfUWnCUIg7ZWopxkFfTG+wZBjynxtmaoVRSGcc6H5JY4BfSAnaAagpggIoba+IqJAXBYjt+71ycwdUeVatWco.iMSzrimHB8m0f3xHo.K1xvnbsGquJxykNjw26w1a800ukikIjyT8Q+AbfQSq0fWervOcluUF0KyhMrGPwkgmUlXBGYiWIJ3BLS8wdZZ2s.SBgP1Y1Hm4L2mGXvlyc+mfs0n.Ue04Th4YtiwTjwJnJ1953LVg+YqFE7zyBjtZLnebEn7ukAv6HOEnX5wStmwwKFwYWYNPlizCmVViVrNo0fTD2.qLJ+8m3tGQ4nh1uEjojUXptijVV5oldSGL6sJo2xMgnDTNugUDBNpTe2byt.nJhs2cU4o2m1c.LhfNLcj9lBeZx+olRmuvVZJoMHbKLePSbuiD1MBgAoXgKPW77L.mTc9lpikesH4fTF4cOVG1MnnPDI502f+1AL3FuFKRhIurQSjfDnSjKOZK+HTp3LuCMY1RVdPp6HHCb91H3v+R9TilMZsTn796Wwul6jsAKoQtbh.Fjd5076m81BOG7lzi4kaGxsh9gaj5K3wNcujTbXC1P6cL7AT2MR2r9RwO7IgEKh1aBqb+rPhADZMogUU2fxhU.tRC+dUNR89gWtugBx9iE5Sn1xsKLrnpBd+bgFYBc088F6mgoxCX1CxNGji42vSXNs0kGWFrC.Z4nlVXu.bhMn71hccEIS+kUMBBO5sgLxn4CgnTTu37mVuYy3L3rlX9YDncwUfZwCNlT3SCJoSBBUGPj3nzmMfbO7jg3mpaj.ZgRMTcBSa2aAexEKinSHWwdciLJFqI0p4ixveoPvCuHVn.kK3ScxD0oYdRm4BBPoSdZPQr8j3BIj3ucb.vz3AyixHo1LFLmZs9cWXy0OmnT9UWwP85XILKFsFU1i8DG6VJybSZUPGo.f6HAyNIWCbfX3h6zrfl3TaPV5I19opsQHzzSmL0pDBmTdGkl4Sa4pJxJ.46bigPRgxI8xk1NLOpkyjfG1Pi.Wsaop+V67T0wtiknzUJ8mvSJ2m87oeeH9pv83WyoMvS+admbFh5QicXsuLqcfGfIvBmQVfED1ZRhejR1cEJKLmcUIXGk5znfQQoikRJFNzfngSX4bLGN95dZfXHfOEcMAUztTgfBGiSV1vlwn1OEZzAiyDfHbcCfMEgCQwRsvgLxnO+lJ2Y1oCNpBHE0.JHIMGtsKUvNf9ccSz6zgy+g+f.I7b8LRHthzjKdI3C1mVVe4XnjncpVUpARk+nwSXdAWkQjofwN1uTINLazn.tr1uycoD48cuAe+ijiq0VtRPHmF++ox2wBKDeFI5U3HSI9CPu34mly8bANjjJi6TjwgaO+i6UWtH5ryv7iL2RzqVpKoEn3IcK1GXPrRIi1WPnnChj9toxs2rsz07B9WoNOnTz4b1CxenYWXRF782wkUXUPAIwFcVGrUHtrMgWDBZtTicLs3IXkwTtBXiloSPevyi7XCWStG1bBy+I0+ZAiGzz04VF68d2Zm0ILitrVOVgM6imfK1vmDx9UWzWyWaqMXGg1cK6p7kVagNEQLMi0IQQFD8GJYnBlByTloUunUwDyRcN32snCNslYJ3FlAlLnPE0chX2MPq6OJ.CIuQb2hoBoPxvrBfULKiHVHM2UKwWquJnqWIhOhaohSiuA6N9MM0fnkJuEUO7bmBxGojsaX1tppbeGmk.P.y3zwz.bNk.osbebvzPxwCURPqn01kvQIuZKUB51C+hbKLugK8Cd7pRbNERE8TApDUuY8IlEIrsppvpUM0o.eAr1E+Qr8O9iliybbCnJa0Cc5DY8oM0fSQ1cVP4uZmr.Vqsv0BvgQ1apGA50cKEluYEgeGsYuE+WaKctbehkk+j4ZOBtdxcqY5QZ+4VopzSg3yTQPr9ldbodtyESLJ412XWmwqBI88F.3t3Vfh0EiCQomluNj.bs0YIwsd63tBKtsI6x7e1I39e9cufjJO864GjX1PVXkEEfO2MktjB71peJkpU8vdmzFfrcEZ8tel5lFy4tp43wa3OqKSfpvr.18X9ZmFNgO0snFtCEG.4hgm0FEPUskFU00BOIGxyeDyhse0NNh6Ox4cdfkNNF7PGRmexnySSfK31R1meXZhB4Q6XDUNsOf2720o87EtLknsGIR0PhebT5cZbs5GIi3gYlgBwdBoPY+Bg1rZR3BlJLXbjbz2T7koMwm5+wW8YC1d6DRcSzz6sHrH+noJgGM9.fXRHDkAfbuDl9MaHNXaGHbpoDrJXQwBBQjNRy1XOSauTFcCkHGzXmqDb+xNaiey8yLJsIhvExSwxKsUzdk8iPi52jZYDHxoeQD.yHr5uLpterk2BOJAKH.JfDzAuP2dfSIBp.1ZzTwec1ILhL.ey1EKrv+mS8kbI5rh0gubHjoVDathuiTtZYKXzVOv3rQXWaSOHB46dLcTf.RcP9dFurRV0Xkn1dQukDt5VmIH1o23PdCxgi87x9sT8rTMzuKmchjx3HlCrzTVMSVEpDwrOpYlV0NRF5m8OLWHcDBHLGgIkR6shKErR+.VF3CuT3goPf.mfzAMexTv+elvWfNRaiy97lo4sbVDEewBQKYck14+wPUfEU7g7JYDPxlnDcpAwg8jbR7vZwGqF4sGKKZNIrsM0D+I6fcISUyNbXSx.qL4sZzuRqgENosOYZlUJLNJb9e1NVbDWuMj1KV4IQlvO5vAUoIiXZjhpHL78QS79uePVNq5Be98qFmTg0M9QEk.fMM6estIHhbqW1mCel9wzVge3hnSobCLabxhpTsA2Y9a.bieiFR1vF.RtUN0ivKP2UnBNmO0R3M3mBlEL2T+zJeuA8StsYEwt5XMoZZSfnth6zdKYqR8qaQEDK4Mz8kHOYRN79o++zu53Ff7s7JHfiF51Qkih4iqdrY9hISpmTHFJsYkhl5KRrRst4Cmuwyo0MM0Ve85M2kqmlnp0Mrm7GBnfT5AVcMaAhHYYAVTpjx7zl+yQBTQf5ugM7RLvPZFi1M7fTX9yJDMU4NZm14QZA3zvjrZBDOW+RwV0R6ccwEC.8U56pxGu9vnXnIPUi..4La5s7Xs2NMatsUmVZ6rannHLOErg.s+AEMhyjUOU5gLWyUxApIagloqC35vOz3RgHrxOKr5QO+A0WMFUsgzaH.e1ru7Aewc0dn4CytCKJB8F9XoDoPqikZzIHpqpYrck7rFSADG7VQ4oP.dK4P81GW8IplRNvb6+uWhxgZBbp0FwlwNwNBx4izIV4ouqJi+hfQrvyBzPUldhJE7vdW+cRJmkRZgLlAZxHIzUoMszBWmRA1EPfEj5Oos5eik7CqJCrUOAgtF0d6hfaPtqRkEmm5Uny3pQD9yEonhuXYmna5pewHc.G3.buhn67.KXO1JlS0hzp2sZfbxLp863a9M0RyzXmes8geSB3l1GrRN1GhUzS8dGd+UNzNUVJk5MmpMpuenRat40OJFXHSg0DapiMrs1P4.4QkWQgaZbTGBVygu9UotiPWIqnpsM5L3ECZnkj7B0fWRygs3Mce5YbzZlu0KtxvP4pfA0XZXu21strTZu.omLqEqkbCgyg519Q6N9ZhrUOU3JPcS7D0h1S32uEtRwHeZJgH..vDigyZ.aD96u7dQoX43f7dD2k7CB+gKSY5Tw8GKQFw4BEo+GWrZDyqAKD3gdiyUGJHW91fV9oPAg2FBH+uIYBQtVt3Ic6KmttG6JHOyYaRs4qLBUGsRUF2yw2lJ9Pm1fNXBzzvNODcmy0LBQcRS.whb9ZyWP6o0mI0FH+UjZ9ALdxU02FwOL7IXFCODra.89TZPLMbR1xq.vTUPM53qcOV2RdStS8TPRratEefMVM813NLt476xfNxO3bYiRigVtbpqwUJkZ3t.F6+Lhg9Osy7igS1C6gPiJk7uCriFRgx0I1rEQGdsyIc9f6Uy2Wwu.ZxrrzSCsxeJK7lr8w94wcLqXHMTDTVqpLx6K7TveX2v8X5rlKHjZht9hVB53m.i6KDSx371MzwE.w9DJiLnVLLXzWRy2mE3WGtNbRJJt1.9n1ZqJWTtFYKvpr6aBGieVqC0fxxSdyK2sfkAVORKFHG3y0d4j5SahCs.HR6.ETEJ9fereewAsE+ycIfwHZtTfPHZ7nCsQE5Tu35SEL4pl8UofqSImjBVtKXOrK+3UV8WxjdLj5qWYVgYo2QZrC2dshoNK2GBRqK84Zajd6P52VRwWeghpX5FLFEEVvrtIrj80fHQPftLTy.K9tyV12cmV3WHNq4cBtf.JrokFTXeNEngmbTd3Vij4AsSoanQX6HFDdnFUQzXczA5CyppIYcPlV87vodXWxN+GttW+jxHAD+BBrclk5U0hUhQHduy4stcZdSAVcA5ANSF88L717mM+skROPicThb3JFNiB2sv+gBQJVHDpDULNUiLH.fBilxJAO5IB9oD7dCs9naJBWagWd.3bsGzhVbFsr7KUr0y2A6Hcgf9Dyr2akK+EL1YSdZxaC59nvW9Qi1ow2nuekYR1.mTu8oh+.T1d4jcbXSUwzgyTY3cCWVLLhdkmXpplAQ3d4smRoKaOL+H78uhxa8TTZa59qCyye652vUwsvBNui5ggEM9wZkpKyPuAFkbqZvcZUM9eM4m7R6fCBT77kywa6DCnO6nHlUqZF8NyY58G04VgZMvg1yYP439JC3s+nP9X9vthzBLOi3k.TQu6SnO.X+pSjtvZT8V7Z2PJSIhGMlAGAJGJ2taGP+54Qo04Vjl4jWARvqULhIuWftesXM3XxX4.7L1o6N3hleX+G4rEXkUUwcIe6iojTy.D0wg5VtIh69Sf1uCItCNdP72pbD+6ztYEsTQYhR0gfdKto7VNUPKFB9IDBHAGxOhyBWqe7BfVY+Jz3YdPOdHl+NABpqgN.QHRS50zA+quUxlyOpTTwIDPnLwHTcrkjqnhXdmCUqyypi4gPtNm88Rd1afYOdi47Ta2MqW.eBwDQiMXkW9izJsQdw5YC3X.L1sj3hqwlBQgV36t6ZvRbogt01QP9bGDjpWBCS88t.epj2958XLLTqi.NK5BGm416WWGfj7aR2KIubE1GBuDjkbB74fnxAVYC03XuQQPi+9PwWstmg7uWAChZPYGfdpQyZ2+n8J1hCTtwcq2ok3QV8y5+d1RzyCCxpz0HcfvRmg5uORsYdJkIBfYtdldHqjwvsXflE615.aQVHQC4cn7DHqKR4bbNp7+xwsuRuFglVDUUi+6CQpDG6WU5g8KLxQuGsPoiyCIY2kMNVG8j3teX7E9tMB1cJi1WYjFbyCecnp5tEcPUvhjpIebUIM7oxa8Zk9.36ol61OwMxXx.O28zDXTAlwPNYN1Hth5sT7hpmHsnIGvnM1ypMXe90ucJ+WvlKZGREGbUpNz.rJupuEgR6uhNVeNpnNN8T3YES35yNbtQLFRgycU4XwwUyc7Hc87ERwkVvg4HnFsDeLhGmeG+.mzQPxo0mfIooBq84a3mklh42uyeq9sLRKmQkdoivRV31fYAnud7HpJMS660ygiKOLmEvDIHVMGnIeVZOX8qeSH4TIiM7WGMFoxtqW290rQNNCW9Zg3v9a3c.aAwfiF1v.KSNRisM3p5vnaLL9pR1H7mDcEA5B8FG27b.vVmRGu7Yia8R2vNudEFz21OmLFxb170ogLv87cftMia5LqO0cpfnQYkbqgiGOQ63fKTQrmBIzsCls1oQ45frpNVn7TYNjvVd5leHodfYFFe9Gw79pwOQiOWXWrxD4SMTTBaBdjLuiIequpdzNCTC6GG5n70WBS0FlrrQAoxJv0ODGohJo1xZNeVjoujBMwhCkwEpcBhfXYVj8hAFe.BJYi2BBZdgphjxrX2Ffv9mh9jL8ELUDtbvyDKm3xCgNYU3Zlwx+jNkur5f3LENN10PNHmIPmLwGWMLlNTiRRu4zSkbVVWkT+XFXkU5M8UC2vwUocIHjLptLig4Fc5lVM89yy5k9I97Z1YzBRfiP082lvwUV4DbTL+049aWDjPzDZRtj9.G9taI2zVwh6GyBr6y.xRju5IQS0JvJ7oifCb9Q3T7CYIpPyHHsmDZE4pQ21aU3Zb+zapSpPM4eFFOP8PVcRjuP.eSj.quLH49.rIHWWwkfjoJB+fWb9QBCi8eaopblob1fuy+o2vDlKbueRnP2ZlM9+Cvb5.P3dzQ3aZdQOH2wyUTAEYqfvnoKlQhkJfWunCn2Il8fFKxvZtFEe1KsJA6KxtkWPAQobcL1kVbTjaVwDfW8EiaNgR5SAD8xyqyqhutLFqPBW+0M+JXLltngUNvYTAN6QI7ySE9ScVQ7Q+84fYvSTc9VYZ.zBO2C.jFbcIrSgSUIVIdzzBzpfxRDJ226UhNnin8M3HYPQ+OfNOrDWbtSqIM4nyBfY7bCbPB3Xu6e8H.ptcF8qcpYMQtOQKbEl9HwUiYTfMqRE24uKoXfaDY10eTWqqVLC9iy24Jz3P7fQ9zlqYlVPITb2F4gMfRxRMShv.kWMSBrVLgccN8xMzhqs8PyQdiY4gpZvIovFoDGS9MkK7o3Xi836644BHUnTAb..Voddgpjb7rfeuWVQVLCjq8fh7CdfKJELYF10ROwvZIVhpaCUjLHdunGaa40ZwDyPJd5WLrrH5bqiICuw5WYjo08kGYxqwa94uOS1avg9mwUumrIjZ8FrLoAFv7HeTEDgVpIDPOohl4gUSWcJAU+oUyh8tk4ORj.AECze1pEG+IkJnQo7AapdOnZ7qiXuzRYLinwmV8NuEC1aac7aeKSHUyMnCRh7iyczk3xeG3DXgM.3P6CMIYDi64RuoKCDlGvvQRW0w2Ts3KASfVNRmCIj3xMA+wD+nbhjNr0zFvPM5LsWpF0b4b2wmpjDnZBwn7rU.ZIFxidqiAi5tAJtsraX77sfZDabB075YyEsz6RzcxT+h1g744eJ21QpxDRVNd+clpQZaogXKr911OLy2LlBeNWPPqLJdKtojloJC9aRgovmGbIceelTm4V1GTGojiGA04JgfJAmfcHwPDQSY3wcNBYBmKqdEXftmcpJ1J8B0Lhyg5Emt8aopnT0.VH1QMfSApeplZfEklhz7WhlckPo28j9sNTz20z1HPYEk45jjKpvF+md6vSIA5WBxiyUJsjZirfPxKn3.Ymp8eq+mkGJOcWHA2GKmfHsgWu52TTNwfx2dnIj0OaFmjmMrlHPZFwJz8Evf6fKcCNjB9FNiagQMv3vpg4Wig+Q6+ymzMxKUJD5msUrYVpxDY2Qnqu1v0C32HWbmy2AakGiviohsbXhlI+eOAsrUeeunRiIuYBC.pbbFcsZz7jga0522ogZFGLPW4zTNUS5GlSX2WnPEVZsPkZkH5J8THy+kyXnTYtN0kKawnd7iO++T9j6GLGbjtli.tfJ3K5ERH2ui+3N0a1MwbiSshMzP52.yrp9eZZNh2sC8QEzgxwCR6TFzkRA3JzUere8Btp1JKTgdcVhIeuD7Pp44dzDa2AgdmEkBnz.7u2WcKq5F6nJ5JJb88Bw0ovPqWcKhg+hmYqxdZ5RStLg5lKKvyL4ucMIWGEw87GCKlhkZKXBvJxbsIn5tF1qQbNkxnOMAe7pk5+HOyQY3tbkyLZyBhrdwxmSG1cHmIQ1ubAsNBOkpoY1G2u9VeDDkJj96gifYE2TnOP8UzhNBLAz0QNS81R8bSfNg+9p0B7dvKv3xKUxOy.YEyz.IzzN27WUz2aBlRmdX+WCI3IEFq4tQez1ztVtf8lQ8aoCdGEtewPVE2bmXl+qIjoi91JNrYWjYg52uo156oiQ+RCs8+WsHEtOEpmjWVujCq9juD3iQiexYRmuKoWJUjAlKhuPXcQv1fmxA3k4ype4rSxOPjny5z89adj+aRDHUnywL27h+Ot3UdpL3RG4I9Xs.VMU1Z+DvEMPDTMWfN.mINFIO3nZaWj9s6.DadmzAAgnweRgzxe95EyhK9JvEyYoGPJSlMhsQMrRG41HJReS4+I9GrFS6o099n5rWNPyiS6zV9Gf6blRidnVhYj9w1.WCnTvwezyI70VCoSQgigZtbIrzH1fZTEL6ER4pRHiUiA0uHvktZ4GHlYgu0jtiyDcJ3Og7XwMUKIlX794IjvTYAo2yQUf1cS8WHkbICjIPM1ZccDnIMQRQ7S6w+VsJlEuGdvoHTNKiOJMh2RnpejdXIUPQMfQnEPilG15XqFSt5n39Y6CfgK87Y8OYSH8Q4XiJP+9XyXGBEWOHmBM4dVpTUXRGv2qIrfz2fgw0eVplRf7safsAxgKFezXBsqrxNBY0Dea1KhsDG+75Wwbl1+2I5kB6y5SFbGjqW4DEsy.0PMy+31mLA02ElAntRd+9r2oh3gLFrquEmWevTL9lUrJhzI.CabGQ5SIBdIosbZu6zaNA+VJCGOYB9zOPIaUBuhf5sMHcAi4tEQPKq1m0MTu3.9W6zVnEYR.DGfknJmhRYSoNo1ls+XbT5xlcBoubQRptLwRJpt0BoMYfsSR4J6g7t59WDnqb8Ytch9CV9KvGdmIVs1JJ+ZbSIZfA2IXVZVZ3Bq64geYpKE+GrCpkF6+o0ct4xDd2W5pesfm2lljToDAKBHaatYhIhIxklSE+G8GHrpu3wk9YCVlHZpbgsujf2w7kCLR8N5w.sky8Fz1Z5.AzBnyJsO.DxgUCkJt8wckfAPDFm7WyEne4V2Ee6jNA8HmGK062SCzrOqAQYmxjFpzUrW7o0gtaQBi4oPRPhxBBGMf2Iaz8jjcLCBLXp7NTZrtNI0nGGtzycT71Zda.d0kbZvQ3nJ8N6kBbA7YCZRQ8rR7trPRy7r3sOmBBfFk0fDHs+jEiTP8KZg7py3zRNN1eLQ0Ifpdqk73DVWL868JvC9YO9ewVeMCmjFI+ABPr6rywGLZvG86gtn8oE5dIg8.Sage.BPhjCM6gWLnLpCX28yDQh4BrMjyV7kEvFzp8sE.H1dmTz.zu+V4NKnQnQbk4dyZensvxjBKkCeFc8vQaDkGImX0buvR6KifNAEYzV8kzJBDEDj+D3YIJHz5bm4VHVy00GR3Vli4mqhzCa0Jf.J3AkznB2v3Q83JD+zggOn5RO+iXWe8MCQBFOCdF8M3FMxdlGLn.Of7ZDKs80X79VZJTFgvCDi6EUHk76xsjuQIJ0PujEuRtK49v9vQB.hC7wi41cqSkfDTYZWR5K3k+GOOchxrrtacwpcdYvBNiBUKcP13Ipye8krQBNw8DT2Qmg8WWMKYl1SPOsMtIHodqUxQK7bxGRWqypeiwd1qz3hADcML18DmAKAKXOpnfuIpEQ8oiZUefQXuPhhpPyFp2cPUEebjbUycK6UOquiZhlhLNXVfcEZ.aoO7WOBY5uHIk5SIQ58nA4.oEBK.Xla5K7IDLoyR50spWZU610Ai0sf2m4AvCGFvBW+1bYCvHsB3VhGrqwaf.t3.lJUMayx8SyDsZWuKtgJ6kQixvIrNSAe4YORAqWQC4baxZeaA7v0HfBykvzT5RB1sTjOFVHy2k6LmvmhSHDWVkKed5Mn4DoFUOgdDCPhJWhP2VRKAkS+0tpw2KBTl+tbUVRGZiu055Gxiz5FqsS1I2204KO253r2j3zM2ZF7iWfmwH6Eb8nuFjUhFp3L0vWcPh8.YTonkjuKJgcPqDc1sIZYRij+rGJqf6eYpj2phNH+IO+74BFF1hnS2HTfNg3tNuvnep3WyOGKfWjG3hHCH85DysutK+6J6NVw.H1d9.Mg2XtRR+gHKOODJmIfWYz0j2uvVKK8GdS3V4G0JfQIwXPgYO5dD.sMZTsEzv3w5yNeKo97DjBQmy+cqKGtNHu9HQAfg.k1uabwBUAZ2meoXg5+TARVY+.O+1jyRVeN2+R6V4pO+5FREXEXcI60HBxq1TvL6lIL84M1R+yG3qrH0asaJh93p9tJE8CLfZia+t7atOI8KiMU6XyNhGpZMQ52Idnk+37ilhXcvY4LGxMqk0Y1d9oBBG7FCqmDJLLtGKjXSNI.KWy5Sn04JOlBU6qToSVWYZ0.rV248Fhbh5xMW1hPfPObDE8r6UDHfcmaoj0uSpBejzgeJoAK7K2Id21COHJ9OJeIb0dAq2MGsvQ6OTTqXwqkIL3b5a+k24kJkqdd2txJhxv9CdVgKtsVHynL8jLldQU9f3.s+j97jIjKk1i31Y2hl7xwAvDHw3Ssof2C03SB27q6i7c+nmsp9noABFD1KeKm4WQCgpwMkqSzX3Ltts7L+H9pk4I5o06uBcCmPqcfAGbMzjksGsyO6ApacE0T8+iopmnrv41UVPUyPxz6HJZiZBEjkQKktA99.Rgrb4b3G+keXq6OcIEF1RB4G0L2d8ja+V7vYfUOKOSPS+IP9hRPipRaMniXGa9vxIqmRVlNiWXCDNNpSN7aEAZSg7sflz5L882Isrn0LoY8on6YXgzAJrcGQVEtdNGrgnxX6jYr5jtTg+jVLkirt4B9.ul0kzMRTBb9qvOClNJ3lqtJ4SOrojhjAesDeRLW5eits2kgoNzgBJ5BbArEtcRcJDCxp742lcnVDl4zlx9quLI8cIzYaSxK1Q0zRpnJMaanAVe.yYzYD749bvtCKTo5PIkM8MMw4lNWBfWt7vNkhWUYNX4R+wVQG9UBOVRpzcbe72PihwMTQnGh7Sd3uplh3YDux+Zzj3++maY0hMxe1p5BRDjvwHAV0cW88NWJUswxhOYGBZAm+wkvRTDMg+zWCalGzTP4gnHtGiG44bbBKSy3S0C2q24qX2+P3yVYk0ZTpXuK.nFqSgvcw+1aY.dOZcJCPrZWyHGV.s.ydUZhkFgU28ILJ6o..mPmINrC2HDvWjz6LFPrgIwtwyWRYBQaFnf3wWKnEPcBRjehy6fZYul2sMR7wNmOoFN+nOudmhpfsE45FSmY1kR9gkxE8tdwWSQ9t1A.yVKY.3DjOLnATsTvuvX0MsHGtRGHjzbPTR3gga9nWfoafwGsJhNKaXl6IkoeF0l5HCIHdA35Qo9eXDiz62brXVXvpJMNZrxIwFo+CVyzfOiAuTV6FSc5qrJg6qFXm0JblbygLbw+epEFJHSkf9DGu4irADFotF.NPypbmkQOD4FM55wffQ31xS88QRUvdROVgNdFXr++ZpbvA8FB+GuQY1eyTPNX9N0i40UHlJNm0pGg8WrhQclyOpTzM+LkYu5wSmnuUR6V1fRRf8o9H1EL4IjLsgZ1rVcbXcZ+9FT3FzkN9CZs.Qf2iSHzRaud4GpYpMt8ogfH5ZEiGNu5.qWoeTGbTOjW8jsRRd7vAbVu2Sk8jkPwbGu1DqjbGonBL1dCgv9uUargpTcr4O6yLe3UY1HNQYqGORfQxqYJKvu4Iw8nVzS1+D3CVkcEcEgJOr5i2lm+8DsUPh2S+ndESft+SxRpsuhf7VcT5sX.o2DXbSPKsNBQK+LtJAyWg6FeZRVWKzbHF.jhCoagiijvaBQNlwFqZUCvj3VpZZYRozI6LB0rjbUpLOVARWGMkcIN2pqXuedMqlTgfvMTUUXLBC3zRiG.q4qJ2O1RseOInbIQEbi.GY33.HHKk9eiQCaEeBDKFQ7bsPtG9bPjYnEu091EZIjmhwrVdt5RgFRdejRtkL0hrbSgYze66uAouKzc0FwPCHye.vFglcG+NQkhXrBYg+K5yuOWwVUMLZrMnvqNurh.Ti77KlG46LvRQgpnduQXF2uu5X+CHc+Le+NXfqpjId03HNok0GcofdrJG993045DzR8p95zbV.wKu+.yNwOCVu.J1h8sP1IBOx+r0w7pkg1ecrLWOiGc8+4oDQdupsMFR8ZA0U5ADokXjpfVOnx+qQq5hNE8HLnOzsdYWmw3k166QCEog0RM5zapRjswohWYJ67XttwqL4+YkfYCJOblZL9MNKocsaphBW2BfeIeWPks0nWdnb1g.l08bcOzJ+puDgcNobShY4l.cruggU6GwsmNhJVgWmiWibBF1k++H.LR5h0nNQ5xAsCC2VNVXMlBCCEDrrjlYVcvUwJiSmyA7qCxiV5cYzzi5UBacW5su6A2Ufk1MPTFCzrPhYetbFYJCMDTEHPDTWG.Pn0OClPN.ItgnB1xyTU7O1ct9mfQ7aF3axjkDWxSJgnWb9wS+5Fj3ZxW3WHunJNgM4+nxbvSKlOb5tncDtrmc6obpBKqQB5fDaS3qiWNHdvwKOkFgFkX34C9MgjXB+jwgxthDIaPuvFZCVH1+mrzNONgiXDk87FTNhSPIWV2VAmhXtClfq22GkZ617W5PbQf760XCEBdHnFpvkQtOIdDKtXCDJksIuFhnZNvJP7vTJSt14.m0UprkNZwljpRSanehJDJyTpNS5ilCjGG59uNCMBua6L7BDSvuZxdqWs4NCc0YaYfkNId3QmNGJeznlRNbH2UcUDlx5tiH.I+y+JN7zyg.1YzomBtwXeGYVDlPIh59j5YmsCLGAxhlLo9EW6IQjBQQOz78+UaBebXMpPwejEwbqUbk.V+W2USY1VDpQ61dBuJTzk2GgUXUU1m2Gq8skL+rN.Ped5M1.kBo3AXixYzG6aJo7r5RaYf1SPIUlpuyNCgOTmqO4gCtjrpJfY1G0mR0m.Id8qAmm6Iup6fj+wtLUCrWvqxajvpMZWYzY5xSz1VwpnjBC0LcKJ.irVEtKUl6J0oxOhsYwTsoffrQwSNpPVbLy8WHb8kuCNECzc6pogVUyS0NrlJMNLieWGea5ydvhJBrsj.sQ969RMi6pz0kXT0JiEsnAj6Fyi0FoOuUN+F7xuKtDhuFmqHixpbNwD4JKI4YIItoN00Z5C8edSADHAWe7uMSO9Q9ytaYHfiBUGLplc6P5sGQ+Iw7afDuay3+ZUAu7v7Z9VH9qZ1Rj15tSHrZlPnk.bG.4IkL0+P.qq40zIMZsfNiH2Gc5NO5Al2AvNhgaRSKWdfQWx96GC2KQHqaH3bztLJ9OQhj5KGo4i5oesjJUB+gP27gUogDYMNsIULNeOyFqNtjmln9u99jJk1g1EL4kpJUOBbRxY7u5fCYzgj19E0wQTP8.HtiO1PPKJ13e47v.XVQdqdxNyFhZR29JGHnrLN8FjgozMibSBnXZ+0JjwYbVYLDshnerDbw2yf6wD5uNimz+agKwiTOr9C1PSll8vJNLJddV6p.aOpOliwZCVgbQxkxAn7Ues+36nEolZm4jvx8UAh3Bcr8XIo8kCASEOjgHGzFsMJYkXMPWhedvsftzETcv5Lwcev4+naSJRJyA7gxES2EyYtUZ7beedWP21mJ88ijgVAWURwvvNBqrMKFv+gO90dqKHgiyULPQOEwIVTEK0WteheEY+95lqxb.8apUKIcLQyYfA4O+bFN0zDz5Qhz7MbDALkoQU2IqPps5ZURzUD9AcAcEtvIX0uxJTqVpoCC6No1H2B7tuPNmMj7YTZSmyd2kFF6BepNAOrAJI4pVvxMk6oSAQTzp60ltAiQeFi0IrEOU8496BzAOQeUj4C7pgLjd2+G9HdvjMrp0FxlFcXFpSULfyA5huQsN.Z..6Y69YR8DmXXhuOvOLMiB6vyUkq+ObRs0gIq4V1CgYiTBc2P349Q9.c7Oqw1JE54GvA5rG0Z5C.ZIs91+NcWlYMBGJe65YPSxb3ga2nTKORUnvYRHfyqIH+YyyvL53n2kl6h6dPgXy8Xf+MobxnnQIbmYg8sC0+N+28qtClEBD1utZqI7tFhuz5iJ0d7pIxuYCoOV4O89fiVGSypdSn5w9McG.1tnTU+CZAXpBRvfOKQqerJjtHVi94Mum1xmuk9sIoDNbqJBNH6.v7lYWglOa.tz9VIR3va5VBYy3fCAH6r6qZt3L7JFIvFWlR7fSNaEMlAYYbxrlizJjyeDBoLmkEUHvTbUpzCVZJltZaoN8vDTztWV4zMR448dHCVLrPfa6vnYaYbRFUCb3FovaVYfDnXzyHG3iWGUqYa2O3YbGSV2D9CElZcjRvdNDosSvi5UjTcVxqkEBqx+XC42bmDW7N6b2djySpxAd8kgTKUSh9YPwXMXElaS3xa+Ltz.ZoZR2sUMjVU0PTHyodnD42mcugUNdDACuBQBs8Nx.vWA8VeIkZanxRkRrQiSBylk8YOBPhuCrvOqCv.0aZJmzsdjOGuZfl.ZM6mhFcKwvNFVWUWg7w9NSDrzpPK61uUdQVqWaIyxKkWM7NMXeoJEpVW4A5TAh5xCK8TZOMV3jITk9pWCfcO8pFMkE+jEuivHLy68c33xNdNCZa3x.61DbzfK9zqT3tf5h3i1T1eAMMIZu3+YIL2yH4XP8A+mIsPAvMGT8.d7M+nyX7zrBep4liZ1vVm2D9e1qxbxoBVD6OywdruM4HJXJnAtGJlrKWvqcFHhXei82SIBH+0RtVZHrgX318+RSWNXmg.0UG+GPZkr1ku3BOIaYj0zt.f21QZEKrOTlEFyc2Sf2S+ukFETYRfkuFHyH0JU88ASqyTyLzNyqweCqSkd+yqSHQjuXngR.OyMyqC7xRyK3APdkK6a9O6kdiU0iGw0khe+ZpWqad4qOkd42LU3z+1j9eV+LxXj.gk+jwR2Qqc72PH1Bl2rV9mJd9UlPYdrYvkRw.mEUQluCo3UCCLxKB7pe7xDX.XbU+zKIT0c5LRGFNHRCZ1EDTUhNMqx2yTvXd7lDakOcsAYg0EYwfgZaissIWAJp0elsNhshSPUFIfr+KXHcduiOBKg5UiVBZgp2oLeNmz+6fx2CFbE.ybcwzweyr29OB.BBmGVpr8Egka1cZvzWNRsJVYsLTCjXPCq+2yTv.YHi7ZELYJkUcGjDC6EJEVou8rMVGYY6qaXwYz.4ORIb8tfHJlKmD8sJt46X.47BmX6CGrl5CgTGm4M6lrsdZYTsltgFwn9kAeTqRksEomwIkdM6NxRgijqUlwSLLJVGn.bOjpWUJAggj4BfeBYZTZyh.UpkCKFVpBUZySCL2BISLibU8vKGe5VYOywGYlu0JLqz8dKZOPVkKJHvjVuvnAixM3sHWJUgPMve78Olu2lWfODhmVrogRiE75P+jJHJhaDDqWeVjhLJpybMUZ8hsxSELyUimQsLCKfLQzEwxAWZvSgZRxuJG9fDOna3N0pjw6ZLfAVxMVk7P3IlkXZUbK9srbx6jskKvTFHt6FnWHyc5fARadgiiHnOkrcIogN9XB6uRa5R+WK1PTUryk8DZl8yBp5+wMVMBDWJAVgGD29DG7562u2uEXtTN7c4kOjL9WgQIeaYmMmqKhuNR1HGVbVi9iZtxXfA1ZHDSOIht+5e.igwojkPK8P5SqsxKkUbuSumabia4heZ.0vepinuU6LyiAxd.R2ov8MXYua1VHQGwI3zt3qCDoFrr7VieQa9e67U47rVE2Mu0XoNH+nBw.xxYn3Rta3UVIHnhTlgEZI3kE13O98T4z84j0eedX4cL33MkELr3BgFZrno4Y6nPMwjXjQsU4d.YZmLoOjvIn3uHzpbN5Q4u2XKkeVLJpLiz+XrETlgynij.GLLv1o5a1PIDXTmy0L4CmYptFKvn97CrtpshWlL+JY7cdb2yWQsvngV2Dk5qhNfdLPsfV4v7Z5Ebz8whJ8WC.HnaNiaGQ6SGOkALnu0hfouzcmSDAswFWjiSEnNXnco7Lcl75ZcTsElRrhENFw3P.DOrfQ5bfpXxv6k9nYfxF29VM+44R.TK20gyjqozwhA+XlRv++ZmuPhanD6usocKZMaE6787tIDXfKpBAjv92cPGFTWqGqV5STA9B9NJA.4kXWWv5U.GfEIBrEMYTYo2W0UYbf9UOuYj5E2QQrMKTNIB3rmeG0z7s+4vSO6B3qI6OkgihSxjNAhfYP3pyUWYxUkmT9sKYrbxfkqDTRPFk4Pq6FuZXtvaou4AJf5omnpjB1ZZujl6jj8z7SW8Ss49IQI+J+nYbdVpVVolrjVQZ07dmjSZIAR9mLcpCI0uiCGJzGN4wliwQSNLvVN7mV0fsLp942bDXWKtm1msBJQQMoje+2iX8ZwnCd1CUoEUPPhC41.I55zgzCnqfCmsMym6VzL69ew0xxOem14MV37+8KuYa.Uladwr.VqCch3QaFoK8cwF.yVectr7NnYImf7e3G9X7a8aIloYzeMBuTZ9B09GdFWeARVgUcZmOIREM+wqUgMX5hnUSjCdzxx1GRQgE1I83kBUzbb89QGQDLi5jVY1xDCZCTTLHPIl58uIqORzI1qyA10A6nM9uFEnGoKooOHXxNdXMS6O2hYv4pfb1EIABWyrYNTCUCnEAAd1cdf+F5accKUeqMfWGMArklJSHBlP23zZOojKUR61ZmxqCHurDx3ZPW10WN6vhRzhCKFJYEad02JFdIgOqQ+P2hA2DCM2YQWAS50rHKyZhMcquDYmQzERLq5KCDswUmZpb8Zz8pdqptHiNOJGtC4UK.KLmXRsZSc.BcllEW9G30yhNfBCPEiQ7C9Gh.i.BglmhnXdA3zAfcNeXbgnUwrIBcg9aYRVwgrw.q1pXO6UL7nvbpD3WpQbHrK4Lhk87VeUVJIC+sT.5SMHQz7YpBXOXT39QrjdXQJ.rHOoZeVpb5uM3Mf1JWozzSpo14Hc1rAg+2EF49YZaQX2IqDWePARO4FLkWcvrctapnckkxMI5KveXmhs+qh7oay3a1f6rqQQFkM8UrcanIA9mrkvG1aZJgUMYMDRl0Gskb5.Gcd0u+Woas0pkyIhSPh3V7DWCjejqFoMLf09rchl1+r7Dsz0knOSAZrVQDRrOaeLvufMgYYNzXUIHLCS+uyKyMMw0v6BZGej5LsUDitcfWIyy3DF9d8TnoY8mG.YgjokJtfcwKigM2dXUHWD0FkwQWvGmd2fuuPybR5jtPGXGiItYtaGEkRaiIrenBvfoEFDUlhBkLoxjBQMJ6U8snB0VDeca22zLR48tyIZpAMEC93+6C9gzFbF8iK.byaPSh7goPvLpfrm+LNYbhlo2nBreIr63vPKgp3gUerZTm4iZkdrCEvD.vNNV.Xv0sogco8+mTvDzGToRy+5e9Yli+mlpSqS5h2TAf3ZPAnXHVIhX4nhSO1qC5S7epeukVJONMKYfsk+nldsz4Gt2KUZGZQdUnt18S6azbsU7zf31U6MmKTmWvBVH5uLxOwblyRUeR9fN0zG4C9Frq5UUGAonuil08nOzRDx2oT1lgGLBCAHx+57QoQzKEdwIKpeDoBhTV.Xwzt6xsaIxnbMetMT1Mo45lOU8s1uiUBBeicM+lSS4bPx6LdxBtWf3MhoV6afv0Uo0d1pwpLfnMuIL7Q..PE+f2iFY0f1RfNmTql.8jRfsgk5.5BW5Qwi.lqFCusHkeuABW1UAkzP8IseB2yGV4pzv.4gdpLAAkzzhca72mGyo.OdxUfkSo+eOt+e.jL61w8DKAx42LuKtWEtRaNqkRJPQFCa8B4jOH.g87DpUdcqwUKVgoArIdwJlMfeNYb6IBonn5i0udu.yOaGvS6MJEl+8I2VuM0wAnFOc9zmKgXZQMPYcsUnGsn0kCpAqSryvPtgEFtxs08VQzaK3C0CdL1tBdGOLnO7.IXC2VfgXL1QX4aXlOJdD6X58dnBBNjn28eUejezE0zoMTZsGjaPoN4ur7TkuEqMA6EwmlghIS.gqBN5GKk2CPJ9js5eHHxyYprhBrHTopprBkGc0aOu94nyTmS2xuV7jYNxlhNxRD0iQ7Mxq9Er8bfG6u9Bf5AeJ4Gm5eOk+6UXnY1H4BNcfPGw1l7VHtKqmxQjVIfF9YH3SsNs1L3GKrwaH9sBRtQ.llwA.R4JNbX7Py8hmB9soamHR7Hx0A60BXXTuplZAc9xNMrulNezkirIxXGnSpyu2DdfxzrQ6OMee22uiVzg9EzpLRGKVc6dlWspUbsD8JM8PyRh6GC9.Lm2b2k6NtQa2N8MeVMyo.Ru9q5SZTuDAO3ykmd7z56ebKOclbAqugfLzLGhb0AhWql+UF.jvXiwf7JvQckurPb1wczOgmAM7EvISX2vGwm4jlY5I1GXtZLenetBOo0678ZkvmnxF7k3S8d6TzIW+z68NCGz4ghLwqwgYXajofoICkBsGSkBRE87prY0ZPMzcbKyFcOPiPrDmu048NzV3QF7ZpyQwSJVf8IlaXcVEXU8.jtZc.K0SEnitRbDPxzQf5Sa2nZJ3oPFYdlgk5yHNba0zb09.xO5guA5u6ZZH0pf28qu3yw+44t7nbKw8..oHonKOerj1Ka6IFutu9WrVKnDq0WzVcsnY0I0lPPRfNXnZUChxpfy4dMmYKIOEn7Jwv2MWooNS4QDbv.U6Nyg.j.WK3QYQ93zrsRlBBxZGgUuUxA9R4a9FNcjYuJbAWu7gwV3y6Q8Uz2XJXBx4kGgrOwIXO740KevX5e1d8n6M7B+jrH59rhuHqIWY+UITa4dEg30chTAJeh1h3OyqD0VqE7suRtCjRkIvO2y56+buql5QSBWLeV9UwEEoCDYJ9ZGbdYZxYKyFjMvXS4OBhftWGl6BU2J3HoO62G7n24RZYZ7QvSclPMg4WMoqYAcym+QstbUku3ZbJL9gIQTaZOIN8jslZ77J89dR9+Ow4hE+wa+UN7aBPuGtkU8Fqmo2uiz4d5oApsck3xPC5hOqJrtSL8cDoIW.PzwhSKmMMoJZgqVqOoEJsZlLloDBQIbH+wK+EwazN+yjs.GiY2vbLjlyPEKc0iynOfWywMM6WM3wTXFauYaUq8jEswniMurzTSRlaoZGlbgbndc.SfyfZyOpXr04T0VopEQJqDF+KGHpc66Xh3YiRcUyQy+SUtVGBxTS1II6wjfa9ONqloi2dLlddZaP2TOWYrA.yzF8.zh71NtE8plgGqP0F3wp0gs5z1uka3p3lc99eKhC5OhUDvCWPj6ZY4KwWSrxwg42zL2705S+pdMq4hXHHHFbGXsp5ywc7s1vND0Ko0QWKpmJSTgoxr6J6LbqZMlaZCmw5.zEtXeiSqGwov3cnDEfbj9RD.w6dADAO97dXojOY8gtwpGfzJdehVd3zKjnHs+bM1FAX.BxbqsXGPYiteKo3asvm9k2ayDLTFZllcVCmsUagkAlbarONrwUYGjyfDn1ytOwqv3XsK71Yvk3UI4.RUhLKuPhvfp4cpnSv0tfMd2+CR2yNiBS1I0YLDKJUwOU7LGfi6BKArn.zzeWLaaLzAKlfyc3S.uw+Dedjz+hkAXJYkijTxe6FihAymd7LJYe+oGxQSN+wFzx0eCusU4LN7lmXJ1SAvYaSeChtG5kedUDtFupptcQc3UsQpDoL0+q6AH7lR1vqtbqt7.8uaqmH5UDyGqBXke2qRRuhwVkGDiZdoWYJdbRCJuT3PtjO7.CevFDM+OsfBOkwZ9Qal5iaJfX9+t1cL5gkE3CWQvlD4hhHoK5nGgZepEVKc3u9R9r9HX0nQMBjEQnVTJPP01xdIsFjwEHUJWfmH6bg5QpFelx1JfhKDzPVyFO6ZlK698Z9G09X0yCPtjHPbCDND7haH91tksZut0CX1iMMt5+3m7P4R3dJfwYoXmaEjJpPllp0VSoJTEPsXAPpmMNrMbrHHU4YoFBANhEE6ZymxQEmj+uprjipDce+sk+BjawnQu5DPEOHlwq7nVRut.8S1.tpfTC+ZpCc+pu33SM5US3dfRQ+jqIV3q71Yix5IyjF23TT2Fl1FsnZxlvaRpJkm81yzOTYLLi8FDy8O814BFgk0ot8rMoTe7ZO7R9kxgizN8KNsQhULbikevHkcJLcfhgOeRUGyz.3ZmHqydpMkfaWZ5fm1ems6WCeS2Vl2peqK7iItJN7NTzsKTcdyfmo890iQ5CIi07M7Juw7m1X3uQ3mpJDKHaYkPfv+OWo99VgS3bNhPJ+M1qdt1PA3FRwL1gWvxFlrIEX05YeJ9ntiWVCqqgG3cJof3UcYv8FqQpGcmmlw3xBUfZ9G1opqTCTNT4exhEBXImCXizX3CsprCW88bNeKgGhBosZjl.9bGZinBc4nZx29P7qlCtcyfbBJ.Xrz02UOhB0y+s4FwJ4raLdCh2YN2bhzpvTstAAXeQ4Hsn2zuN0kTBzFFYhBmfgFzFsBqxC4wd0ziSoG0REgS5.L+hIcSIfMgLL+A5.ZB0b1mErp30VcnPXsPrrJidvKuBnVcDvBbtTH6DNzOSELcjtcNv2xfNFEpLc2z4AQ+hVgzIW1cCHOO5PZ1e7c5.I1N7XQtUggrVfbBht0jKQ0wM.bWEzHtxv+n.UMvfcD25jg9+b+rTXAtM3pivn4MOyElGAojcYgZ2zMPM4SvbGbVVbxMMWoXdIqUlCAMx70o8Lz4OwteWb6tWM8XG5pm9UmHi.k.g2mF1NHzLzPLT6hkRQKqTQ8yI7K6xTzSTvg5LYKOnzFrUxm435aFM2DAYJXeJmobnKN8zdM2ZXL1whNt+hIaTBhVzDxEPm8qqS2HcOJ69i0XJiv0MUw0nTBhZRThPGblTtlomrM5PRG.khQ.J7YXq5zjlyGZLYbQXT2SbLxG78eqD6fbhd3vrA5OJ08ohuF8l2F2W1o1paeM+5q18+8.nAkUWpNPX0tHbw8cpZiZA07mFtOK6GrIRo4ixTeW0ai+VsXBIxT0pxGDgCV7YrCxpVu6g5iExPv9gwpfsZQ6Rh7Bx5H1s5A20LIvwycVuQkCajEpGiz+qYpvuDuXVnU1E8PyHxYneBbp47OFPhpzmR7XxqtF1Wj.6peCuNJmgatj6NDixtw3N37pH95okCvgEYYxuttqLAQ8SV9.eiMCDVmDhpkUKRNDYw9a5iZgwlDM8FO23bW0DTnLbYZQLcqzH9ljIkZHNJgf9LOdVx6.Up8cSXvGDbNIpNK+ELHnC+fIrfvANRHpn4ZayFnyLXoxmmu9T6qHn1U10710uWEYgyGzyUdaG5WJaVW5TJXhXUf.XW4wTrFrQlNLI6DU27.54VJSwSQsfZRfI6SClkKL4n1LC2aldRC.dP5Ryor8hPXG2.3DROlYIUHEq4ZcP+CovZ9q6RyLhFaVAPuUIzq6DifJCOtXsUTcGdNPOhBfsIBzfITQ2lIUsVrnSn3+Yv5KpOrbPniKdjSrWUk.Yjs0vS2+HW1kSdbbQpdGuxlstXk7oui4lPCTY0MIVUS7tDrsMn2CTzUPIS8XSQSE2iq8iA3qIOYvuPBsocgvFv5ciLw6bfFTsYXc7+NB4mP6bPfwonfk4URCeDFdgKQgcaye40htkS+L51acxpu3Ktxo0rxpOS1j8mYJKxFfwV6QKALBWoQJrQ7VEgGLIv9FcHsQj+DZUREjGz+XNwJCLV0uzv8InjT3Pndmo.hgN7.iPiyVXdWey84v6pKe7niZAbcwAPnL+RnHKUU1+Ry7Y+VWmWFMtZYOcretHYSKoDfPwj4JoT+vHLTc0zPcvksuMg+vMB3Ai7NqJCpr2w3asdrzWxY9lsXyNFi+5mtx4G9S9stWVz1ZULGNazmmPrFCqSeHFQkM8jU5+qd0nIajkI2vw+kWNZEgSoPHAJ6kDyRYZNkG5Kg60ldKP8466AxGO0tgCLDTzEdoFX+WF3R6SIjEQPZrCmjtokO6+GHQ+eg91mh+9w9lD.w65cLBpZjSYmsfzXn32uOb8mjMOw0qPGKWlS3wfqdUYjqsyqPn.gNGOmcQ3vEkYl8sLpeSUugDCGoWiG4ZwlZmIXX2qKbUQYw5OdPEyt.JNmESVHAMD7dXRGhzfjzd49FnGK17m7UZHdV+OEQhFGgq5zjPfvul2JzGuM8uzyr658zqimNkMpre3o1Au3zDd5hhq5PhODQpOKr2fIeg7RKt5J.wDkh3okrSJLa+wGiBIJNPc5dYHn8aQ53p1+UioTTLUr.r+JJwL2y2YTNfuiwpOmp9zjDUhn.tJHx58f8cRVRfZcG4oFg6UBG3INr4MT37NL+2Vunswi0tQhcsB14boQAXTnbb9Ije6k5i8G62qcrOOeR6DualzGKRUX7BnvmWirDe9Op8UJlxvuoBZ8vA23GxSV.xyVXTIUMe4k2n0J5m0nlGDN+u78YEN4looWEZ949CqXxbFrl5psuocP42ktfPV3eDMuPbVjX2BACnMmn7LU0h8O6DHc2P1o7qlfrHeRK25bsVcD5sWZsKRULo8L+iOXI5up+LiE6gzp+Qzzqw3WJIWje4hXG1G5QKDG6qjQrPlr6vnxriiEoWSqFAmL4zpD8HhXpg5rte9oF24tAzdpXQDOzLbE4SuC.yFNuwwowYMj3DrbbSX+pjAZtVz6hY0DH7mUf0EHgUq+aJnA1sMhtKt3+cSc3UXZPVwRFn+jdazy89CfvYfpGgbEp1mjkqMIS3uYK6+Mb6j5XDU.fgmdL5zh+gB8V8iFP9X1+lKM1Tn7LIzpdK6tuNvqw17zjP+VuZy4rz4PMmY6s.Z1gUs+MxVsEPxJwjVDxZYTfOzvDciNAQye8jSizqGIM.8Cc+T3CrNJ3yTfXmXHbJsRintTX0Dp3QRtrZ+HEYGl5++8zIP1y4diEiWlZxrRuag2.o5IAQHKmmqx6GNtILToQDZUajveI+Ctye4njmLTjUeIrU1leG8HmFphScTi3tb0NcoQw3GbEyoDeuWDPSsqOy6t4B3YLKwmIt1Ye7lV0RaTy90aKaTmI5SbT13C3Gm6USpFNMnbRLFze.VmO5BcArzyJLs++oOCGjkdGfnio3cry93vVMlg4m8ijjxKGTD5HXCGE91Z8qAKDo5QsoSZNm3QrC1S69DLjLbu6J51dC1I8Q+.PXsHPnSUqLXXvXJtrhbb1dL0hHgTtWtnKlsxYOER33YUIUtpQYo2wwYmB2FCE7inYFV12py9WrZ8oGEOXoX.RBb12wubtOCj7Z6YpgokcicIblpMj0A1hQtkyam8kc9vTDq.x0ZDlCZCDzLAzKq3gni67ob1Y9EkpW1gfcAEHKoJEHrW6nrfeHlG2UMBbTVlYprO0z5TTGZuyoWBjM.n1sQW0kiB5ljNQROWWjBb6JEN3DBmoJPpSSPtY.yaGBGn3MpbwM1fsEwkLbubnjjvLxfyqEXJ21QyutfDxehvaZOGqf0hGT5l..ujLmDTh1caRnH2n6B2USHvtxHBP4Ch1.XisDFkT8gD2em05HSoFwTTYJViXEpC2b6OLQIuqfIIhNCNlEnKO1FOdLiKHW6+9r8BWDomG6gAIybNNtsXW9JoeW1zAxtk4UwyowcIwMuDpx.wMDrPSkIvL0pHuIrkuDXIfuqH.MdauWE4jePE39aipfzsj2DURiFVFVPHY9kaVmnQbR51AF9QbTKz4ZC3N8rqbu7eAaL9iNVnrq+GW96Yc+RlSedXLpZM1BwMgkYpaAPAhTWC7kcTeamVR5U70Kh7TLcjKjglKHvpDuuJ4qtfWqfzIoIHtTocRpuTe5lI13uJgg1zE4Y0Q0vnza0Ig7qTEJE4N6I3I+6LRRDxPH2M51B8CbJEXR52JFFlIiBweycf8YGNP1oH44Fe2sF36oHHTZDkekXz0Y5JHZcsLUsUXgamX02yON0xtqJSbBpOmV+gjyWoazwZ7eGdA1UDuNuzJ.sBlczt2bBr5baqk8EgvxAzVDKrmugaPScYDLGqIwCB.bsv3wuYULFvHMmNQYwue6Fq67qFwkkiKI95UhQv2ynKNBDoJ0QIXXq6PdWiRk0qTYehOahvqMsW6fGht+Z.NDg95JSpXa23q46+VxAXi9QZFcITmSGU66l+EQVnvxkPjrLEdH.Rq9.VzZ3rCmg8V4ZVWuqY+7BNEV95B6DEUAf.kY5U3OoJAjHhmAv16T+JankG0u4OLM++3DmaHm9TCYcR4yM+MOUa1H27sM5teIHMNkEz+zOmBUeK4GjYcYgkK4kixELrdyQhNWdvxP3p2WV8gRwkxiKgy0vsMYXsWVfuQaR+I5q+Gfk1TcZ.VKpFeDQUBiVIihuXIe9ossbZbD5ejzvcJas6Rgk9YTWovzg8YUCzS88b9N+YkDpWDjpeSdm8SZc25CJ90jKbUK8R59Gxig67YahmsGNvXdzt8rY3T8wVTcdGgjC6nGv961NTZFmOX+QJswiCkypYWU8bh1hFj6TOOH4ri0SKzHksSGdbeq5fgyOBT1582nwDXwiR9P3ZpZq.oN5PtOTDMi1XUd7guMA1IH1zlsaZ57YS6r.U9JsPArgVuM0bMrY6GQAx04VaN8YtVKmjty8P4BBmCwwZqcLJofcPOaUZcjMhymY6J1FiibND6b6WpjcrZs7EtVqq90Cx6dEevb.Gsu94OsDeH1EepbM0Rgu1g.EP8z5YHyzHDNQJq17FtJFpjTtCenJZ.oBHP.089.bjsZyx2wVC3gVdC.2gu93oudQyUXcZ5GdsJOSs82O2VCCmIuEJBW0hh.FegmsxAIMy85dD713dwIwGhYbf.mGs0W2etAPD04ZyGjRLvXEqKemz6mxYLUCcyUkR2D8f9CYdqXMYDr0CfrXCMeOoDFPpZlxC0CLSVejoLSC.AfhLwgDQPT5TvpjJUDNL3pQ7MbFIN3F80SwzaVW8xZwAXLNtXm4.JuxG0Kt9lusZQMlONQIvGTOAUdSdcC6bHOnl9YymYOrLT8dyvRLaRfm0wb4l1Nv8QSe+HPRBP5bZ+j2BbPrB.AQxQ083EYJvVPmZ8lr8soZJgSs8LwIskHiSpMcmW7EL5rHq9HH5BBHFD6fpcPXsl9uJPlSgevX6vupujgH+3SuZeCQptGA1dc1vu6n7gAN.U.DJxasV5nC2tSZtIRW9br07q9RtqS4tQ8Lj8LYNtAFsioqGkbLusOsXkZtkYWEvFdFXsO6LIjDUjYaax3KJIrbBEFz+JChbF8Q9IAve3HvMCUKKaMgGfut2I9YogsM.c2spLmE6t1nEWebNWX7slCKqMAQgPrnfIUbwtK2tH284WnLkobHiQKRSZ9feCWgkAPJOo4HB38BhuvgoIyY9ACw2Y17absmcrizbjts3zQSzwHup9CCXa6Ezlp8LutdZ1I.sRLgbBCKj+FvhYUUa0BojCyTHKboFBpcQ9y7Z2bfjeHV5+TVNLOTLo9FPTPfONjDXhzYJdgXbbdh2.ZldirQDWq+88lkeOAnRmJMv2oPBgRXPN3e785om78AYHG14RcpZpFFsKjq8iZl9sHGufS1.yytRT7XEEPr14RlpxB+2MuVmHL4kX1wH+DQzJs5iQfIDpPoCNbneDhuEs5h8mlEer+mxvXbudaCDbvBSXrDKscjQF9N0RBPu4x48pcNqncr5mxuIDGnbezz2D5AjtCF6DmYhLFKmcl7JFAO8GR8WbbqqCDCnqhIQTQBe8y5mFx0yRm2DdzHWAc2+6sDkTiG.kZx5pZGe7qtidKp6UWuqPyJMXJZ46kiGDbELtFLt98wcGS1kKVZG.X5nx6WTrmjpVR60f80eNv1ep6ASQBaTzYntBrBauzUAGehujIi5LakGfTXC.WeDAFmJ1Dk2lRqTp.rk7oXqynIjW5H.I5IN7DDX9woIHMwdRITGaTP+Eb4b4naw1HeiK209frgNwZQBSx5.ggAra.8Njn4thiuD2bxDe5THJIx9Fl3C2YEr8+dPNEu2E91ndSKejIslHj2230XKfGfbJ+laqpldcHD.VG+ILO9xWA.9z3tw8U6GYwLVC1fTXIkf9him1bzf+5dCcxD2Tv5wAHp9k2Saw3xDXiKNKlCx.oOtEhfhL7nNPlz7LqZzbWD+BAg4chskXJkHSguMg9DEfXA+4ErThrFPRbomQSirFEEdLD1rDiw3AJ5MwVsGEyTUBNVoW9yq5G5azIw.isx+Ybyds3DmnSZsWaajQAb2rt9pYkFFmSRJWLe+HE7BUhDq02WgauE2gf7AmqKbB.J4.5UGOaB2dcvhGjEG.dhkvTNk683KUg3YRIsx4u6vfYF9cWKNrbEtjig4aPFGioHmF8+syiN0G1ukUiZ4n0lV0yJEIHwXQoaefm1OkGmf61oyw7H4mtwEGUxrK4yFziIduUIcSM3KLhR1BFen5dE6h4Yjt9EPK9R8abJDW1D2R0nzl4xnp3KhH93+l0zLrKE5ToQxldqh4+Q9Nz9Ewn3GyTnKn3Arb9IQ6YtZuffJ2uNyfac95zIfjAM0B2i4yrjxcMJVB14ylyshfC4HgTTSC9s6GOp4iaPG1vyAJvkJ3hSZ4Hx0oyPUctX+tiSUtKTbGllAv1zbhC7wkIzTjPx83re5IGJZSU7eITMD0CyTaHJ1LrCnl.32JExTi0GUHPyTBXCa0cb.819VLfv8O9zW9z64pMrvNTmlQjWHZzR+DT.NsH4T8iezrnlA9qDX0aGqq8LH2hVF5EKL+3.U0ALyOevAeLly1zMd1ANVjKGWpR3hRIM3jFlfiYhbvgGYMu.vCZIIlJHnIh9pXaC6ltVGaCByqEmXMfEZgwg9yO6OWbFZDTRz2laGCpqKEtzItPwX1vLSKtQhnNl+Jn9R47S2KPCPzHQABW0aPi8jrq+Igg5M7alPYJq8xXIFjlW5JXCU+ad18dnGJ+i1owIqr3OV0EKtZzNM4zltc4Y8JqySu5ECLchgZyJ3uh92GZlg73GS6FvCmd3dSdaKDcEBuVSzxOlnTCgppWmarPGm01+rNHSMF52sAJWQRTBviWzcj6b25b01aBrO40dylRoRx0d0kcHhpOhCA2h0APgVvmSPH2SKy7W+hH5sdS5jtR5+gFbNMI116IUGpRP61OgzEFH.wta5sIa+u3U7fUbBupcOBAbMWVFmRrCj1LGKUpMun2KiTpCFTmLz71X3q8EZ28F7RPm6uz6qzYkLXFweTAQ23wruG+tm7JFJiKPthoM1KIRmfqyz62ObnJav55QPqXkU3ZrwhV4m59rcHdrsWtBDx8j+2dGbC1mlHw1C.B8w2ZtVZaUYMBHDfL0Cp7qRY0DQRv6a.6luC5297Ho+KZH+0mhpz78z1HP2g2Vh6v2O96YmyMj6MRd12QonH9tOF2dTTSO7+V1+gJ29eDHSVadiU6MPJWhZZHDIbiy7JQGk48gpJaLNO5uuCEDmeEK7wnr10Mc8AqZnSoEC.5NYmo.PRV5.7Gmn6ZsWr0qEIAVuBZcHfNe276dv8y3XRznL0MHWA9Vs3l1EdRjNPvtNQ+0KVEyh1ji98Rl8+zvJae5mIAf6JLJQ3tLvREGEYzf5msB6ydPNshNzVHlkzwFs4tjvvHWNTn1LGszBkmWcfhi0Mt71blcM6SD676Fq37qD8FmrV.YTrmEJnLOYc6X.srElIrQmvMo1i.8QVlD5BWRQhMt4xg3gqZeBgYah80hE7yKl6.2TbQN7sfFnTSkBhF3ksuCHTK3o97HKXGcugs8q.i0i91Q7574v9CHG7Abfgxo6J3kIqMtuVK6CGeq6CeITm0JIJbIlfnYgEgrBZTGq3AVBxK6TOOHIe7VRE6pSToot9a.RvqOQg4m4vFAuycwxvspr2xr5PZKmGF+u+nfyNhxIYFGrCYZ4Spp07MLD4I59ztiIcCfRNxPHAXQWxkMRwaa+Yp9RRqSUTodpKZ7eLGYjkeAfeavFu8vOOBsK+sNN2ocxOanZrmhcBkk2qMwkHTSLIgn0BMno0s8tCr+PAxxJTlg8.jWbnRI8BzbJUAX8Yh2hYT1ua7Y4RQNIOeZLOQQUh+DA7iTQFnEaZ5fNKMu1uK40sFfbu6.MfDDxvLtZSRpjxkFUzT87l85WO7.4EKzLRk9.1dZas9bXZ5lFhNzHP4S4a5ScdhQ9TNxtOjWGZqApOYk8uTQY89RLmPTPzvJXVp6x6gJQVhgJGAUlnWEHb1BtTR7lUiCrF15Jo0LvagvmvlIGJ+xohPhhWloWzU2Whh41ZZJaDYZNOvmbdV6cyV4Bbn16GJIyYYKUsX9.1gzk4GRDUWXyrxrRV1N8WTsd0MUOyRCfB4gCwTy4AH0Fmi4CJuWo3sp3jKnpOrI2RqRlfSdGACCF520Os39WaMzXJXpLp4qc6n29uPu8jIlRgwlw0HCBkRjJdFm+vgxr80ex.mc1HuK2SkIhPS2VmFzW.KPUSGm619gDWD3EmzwKhWyFvS.YVotJwpg2JVEFShCeVl1ui.5p6ca59KP0YXtzrdteqQ0SfFGqpa5PGWRjq+faB2OzoL75yFc3r9KdywyZR1sHIe7pm1ISsbqWrCA2x4PskxgiRYy0ChenODE5iQoqxk4dDbHDZAPC8sxvqLBxgRcv9nVT.1Fo3j18TO8AEICBHtOjP2xNgjnDRehQMJJuBYzU6zYRx3Cr2WhtTtGGi7R8SHdgMnggWvPUsHsMCA8dHk7YiOD9aG95I0epVdieioMjMW1Fek9zvOZFsy4jhiWw+fZuCZSdQkb5TkWCh6t4s2XWWYoanghKiFDQTHlGciS8nE6G2zjfo+V7zCrGku9MAlGskZ5hnuS02VSM.7nJNU5eCNVBNn3hWHUzagLRvpcq3VV2BOV8DxCcfoKy2XdGUJW6d3qruNW9CXOliuAHONjaDNTLP5oZbyaOBbpf.U0s2WA0sQZkc7g6SkuWRr9R0VZHmLT3.BJ.oL6bGZxb9YHOl5AlXIdkmsP2mUtWbq5uJSdVbBwOIbv+ssXArQOH+iemEtL+Oa9Dbl+gRREe6P2pfmx2sAUxn6yT+xekkYq1amOkDx0nvtK9siei1jpuzqHp8yI7lyMB2YqR0bW3x1w9UC0QZOIwMxwAV9lFTK4I7OMvxuQ7DhPdSv0Dvp4QBJRZyr.sqNhw0CjiWI9XyPOuua+dtVsMCnXqovItjoUrPP8pbMx9bjUFUwyi82wqlnNDSMKAq.DhToOvgmMJbshQ1U4pr.go7x67.g7WbDEMxmnApkaSnzDnkiiPaXdj89RQcfzhyYJu.vd1IOQqBFE19Xtp48C4tIH6mOkGW.vP6spcRKzSo9GzXB+x6GcykJfevT9s3vMFDB8nTWCWTeFY8quuZfJLaL5hNyr7JtutWOqU94pN9ahGBHgPtk0lG1SyJJ2apNEWXgkgj+oB1SEP9QwZO5k1Muns16RP1gxGF2aInoBSH6AOyPZaNTyVWECRAuNx7tkIufBIZI6nOtQ20+hY0qFSwnW56s18j6smBxM.7Sk.n1+YC2h9C1ho5UofPcqly5zhT2.JCDi7uqKXyEEKXM1EhQHZQdeW8Oj2ifFJDmq2UWJ6..nFXX5onIIkAZqpl9l05OwG5rkioK9gP3kHggYrIxjbvQbttgSNwYEg1QONuR37MHofGW5N3IQEto8aRQuX+gHE1vOjFL7GvMDIsSk01mUxwDU1WTWJ0TugKqhZK4Xv+ADoTxt7r+zkjQjgrjnvFG4xBJaprgeQHA7HSQzQwVGVi0laAKmxxdkU4QTxOacvt+zySqZvsGSbKFNQ8v4+5aEDT88SX0C918DbjPw1I+gRTpVWn2.Cgj1fYg45OqSqOkTAHJzhWfayaxK.T+mEaakVvf6UzK77tTvi+aEupwQ+VzebwKQQAvOXjchObg1YG.kF04nznGTdro04iA3Fq1VLB7Xy6an3USe+sBDJR5MP+XpvthZDeY8HWcy4MqUr3FZaVjCTXUvEGO6.2Bvw6jiVvjc3atVUHQsE4PNoU+VJPZyirSGNZ9WlMeQCE2.Mur.TDzoe+Hd2tuFxKT3f.Xw5eM+VublXrrjTzevr0K58D18IUrXZDdW8zjqLb5mW+BnfSvVB4B27xuvRO1GaBO+2X+CyTzMUllS.pvMge8ytKUue09Nuv.xDgo215WzP3Fyogv9VCNhGrrVRlU.SZU0Grd1.g7vIaJ4BzjD2o1PpU6R1PArvadbwayGaOj1PK5VZl5zOMt9DbOjTaCU8DEdjMZMzY8.J.VWsDdPUkerk0ARxZaN9XmBXfEkON.CDU1uFHbinX4aAwPRLe+CYYR9mKzboobKou2QiRflT1gkqvSX.fLhWq6ukg8RGsVepVamXK60UdcGQ+7S6NStw7AeZouO9hNq.Q14FZDvnlPaRxAaZad1zSZG8i09nksbRjtuFCVFBTUSFPshGJaneXSOraUCCN5r8NGl3y9r2oMVkYxtYC7Ys9MLqN.e1IBjUwQ6Ry6irKFC0G0DQbPv50Y3Naare42rCOdZN+yJ4fWMR36dZXh7UP2Zyj7GH3mIhtIuud94uhX0mVo153rc559ZN2VRiGoTOLufd7fOS4J3S4Y.auMcqi+uqT8yQHQMT5Y2xqTwDa2Ih+UcmkrpUqQZ6nDmO+MCbormTMf7bSQRka1LZM0XsBF4744I9rMk0z4RWJ.QEcQtW8FXMqVBjUTQSDMBW6RUmGGVZMExLK1Mqlj1+1CizpZcz5dNZLs8VUsIDSNqKFxDh3h8sSpOn3wkxSqYjWA6Pjxs6jSFRiur9jOcTN7krJd7makWOlDqx7kSyj9BA3BDoFjAXs8txLTD0BS9GTlqf6WJa8iVFeaSmCj0wxMB4ysE61jOCZQAXeyvUA61vPr+sKz7eWOxy5nrP36MKnuR+riY57mszy6HOu41XhOLXMx7BFVUTXV0sYpmKJLSBaB33RUtkOS3ZwaD6AH75C3vY2M1frRev5t4eJW1yRDp1OY3XsZcrbmuD68LzlvABXZEoxpcNfSG1ZdwC+Lq6Kw8aAeGymgT6hx4wtArJpaRxTeJxQCHpvkdLYykCDZkRpPmfBwBhXRqVh0Z1VunYTOmCg7WXj.hUEISi.ehkknj7Bn30KiTlWys0kCy4I93iS.duRN8DhkIj3GUfJHARlMBZP1ZpapSvFoa25a+1wZKFkwnwBKDK5BCCgTKWdaA1HoOGLi6tmYCRAQCgYgf7cgrItlpnqFhxCC4DS2kkdHlFsS0J+SK9H2X2KxQwzbPo3QQFbolmrAQAn.EdYhv0w+u2PNbJXI2F.frVdDfH5K1ICyXmTWeaMiI.An1EVyupiv8MO0OWebhQhXibpJ++EsGkZrO+MD+vWeNbSRt2kYnTBa.yu4zxR..YKHCSCdvyjGymicecBWBIiCBHM1JjlofnwhSQmdnwV5mHccS+wirE41cyOiXvSjYmVXFucU1ZjgdHIuaftIxRzlxfVEPnrJuO1sbxwsbX7pRPq2XnMOsIPHEHz4pvh783g0hUHW8j53WmBYknRJp6jldYvt0dBqqPKK2wtTn+KH+J0tkues3s3fnCdOztinMCli7V2gWULUIcQiUy2qQMlAWAvu8+1uuZN5HeFhutHrJS6Ebu7o+PVdICsMxbqxXNCoYUMMXix7V+GVEzR7nO3x8Q7jNiNJCcpBMWiGIJyZy0PDznXvMP30UJA9ZaZJ.FdNTVjuwpuBFqK0c80hOfbevN9t20HLfJ0m2cc0tiRNrsgZuCqSyjdaM8uaE+wXpwaPdT0Vy.cMGJmgSkIUwKRr+x07EhsTM4SRA.8CnMjoGXnX5EBhHgw2X7JSZDa42PUEgNCju2VqIAgMYT8UIJVfMcZxBA3dAcXwAioLixzlL.EDbTgdcX.kG4qqzVZurZNH3GLZ8S581kjNPDIEIXEq+Q7rcv9gm8m.dmahv3ZObWy9d+ef7vt1D5rzyonxPxUaHjBfkK0L3QnOcY8myqR4BVHgEix5Eu9LaZQm4e3SwduIESpVSeMpE05ssqMjp5cgHxU8q1uEN+xqHUBBe8foDP5iVGCg9KaYRFf3BtFlbXviyguOJk8AJjsT9TCvqw8QYZ6kPZnmZv6yuYHjGlcwJoI0pTDsY8wCowCTH8QJx+LFU4S41OIYwGkE.cHiO6rgl3LXDtl51ENOdpNlSSAGXRelnruJ+8+hBzQ6.zN5r5zBd059xg.3NFR77vF7Ixgdm.0IR5gKuaHpBYlXXAmozMi0sCHJIVuNjUml.W8qp15KHwmzlmXkbR+UG0f2zRUTNJ91h9FjI1rS1Ibd6lTP2OeBEcSHl5Hes92yuF+nOsDk9qwtDM85F6LX2Ait6tLjQhmYbgq0IGRZhMPTdflI4J0xtIDiXtdcyH3KX2O4I99YwWEW5XJky4TDJkRCikG3fYSoMEqC5P0YA6ySaqIIpoB1AqwiBggdELb5tFDcdBROreHD3c5BBMnUmgOQd3v0+SVpELeJzmkZRftoIYSvBO4g5bk2IKU+DXBAx6phlt8.7KZWZYv1WVkiBPvDuv93MWVIWrw11Ao0x8K1rLHJgak+f79jz5lrWF4BG8vsIamBJBhHjBR2cPJcG.Tuw1GpOmVyZ5rC7iCdoB2LsdruqgDtssq9rEmr..amkr3nPAHJq6J3SjhUmSWfP9+Zi+AeJVSO690PawHup3Quat.J3JT.VnPOCvX3qCs8JS59lHRfD+NPVGHA+3ySka9tTrtw+4qlOl0RtYQSOSNtvoTlb4D3AcjZgSZno85rn.7h2LSsAJFbfgx2lfkrp8VR3+pvT9ynUPv8rCn2LrtzG7KQlCKRun7XZC4kBwuEVKSi01Eh245fH49IOnyhswCU0OAX9WhvDFjgAExt45D8OT1SW0tEHIarTflIrw3A.UelGoNccDi38U.EeOYnktkdh2n9MUdyvoNbcQyWzdojpjZAYEAqeGOWsdA2u+PhTeE5MTQrZYX.GWShh5N0IlEhfxWb9J6wUwhhmn6vexJ1MDGaaZx6FCU7dqFIB4H1Cyb0trui3kkdvvRyHk8QPB21J8PYC2WsJtSPJ3rOTMJok7p3YVj+UnaEspWlSBK9CNZyisXl2jIhJ.Xe8GllFVIBjhrFE6OnoZk3uZlsmtvmHMm88FuwftH2QvMX5vy2FdRbHMnoBB1BGqZuaFTQo6hq9vkt3qVqHqsVqBYoipXCqTUca9HiG0wPTlN+8XkjYXS14KN0.8hFyUZJ7dRtftIAkuKuOO40hthDFrofe5VOH16KcLAnWY7gxJgVa3GjLXq9niU7IJnbqJEikCHUOYraTrOVSn9CzlAhDPILuMG2lNVw3Ngpvzw65IfLAPbrwve20iTbpcYQT8g9pBuzXSk1+8s44cC6YfxGELMV7IjJPYNmZEIv1zaesriH89PzMxooxiF25jJL2yajS29Ecxy7CKq5GDEDPaa6YmWn5d16.GVNXbubbzIOrVSH68HfCpitRr+4nGfw6hsy30z9TucW3YL8.YUGhFBbtmzfYVGaHV23SQwl+YZCTZB67c2pqTeq.09ExAAULkjBkCwcyEnqwLoffk.Y+Y7VOOPEk1XrrVQx2mv2c2t23I49bOlKxjGlmonaHXN5aFzIf62bgAIxVCJEELLgajL3lcNjPa3JRw0QNN1GhQQYC3dG6zeXZtkQax5BafU7KBiObs2t9tNhGlcDRA13EZ2VCOcEsttbQdI7h3QTXDiZ9ax6M6xr35PzBpbShE9fxB7YKYz61WId4lLnhpjUaQeYsl7fjAd0xNnjmVppdBDg6UbxG4w1bLEFNsFvGtCLmxwV8P.PkfTLHTyzi9tbr.tysDuW82IBYwIQBP2MyYgo5S3lj0CP.r.ShcclDeu0riTW3WYwZgjU0n9AWxEKq2nfa2HyHm8qVhSaFWCd9haNOsvSLmVq7FwM9tLLV3ArYNk0J2rai5trEDMlmIBpDQmpAkVkI.HIW4YA920DyutGEsxM6rb+uWh0yFOK+i86Ma.xPMSD1zNeTUd4qbAe7ZYueJV.upH45mgc+yf57AAvnXO4QKh5NRcI0eKWzhgn5KeWOEALcqanQGtt9p7wv.6pSzIAleMs8DArxxeERZDC2RLMqfazpS84R1a47osrHScFg5dbAZ90G9peMsrQORh2QSUcKs1C5ecZsQpca40M7E889dItQvFME5puopySbIY6HQSezfW6I.ARJwa1QMTGS7TpTN789FD0.3eXdc.tPvUsVsaSRmmGejlTpyt6B73+ow9pta2YEjJn3frZCs5eTHipm1SfWe+vALXU24Psqc.s7gc5TWq8DUU.c+O8nLA.TZr0hr9T93yohxw2DE2fkExuEl7w90r1dXQEh4XKLhx.U8G4zx2FthcemaUwqnBJrH05DdM.jxmE.juUR15Tjt36dul8u19lODtrhx1k0WSsiKSWyTtmjDY3GmL83YgD9wnT28pGK9eZkYdnvrcPU1mihXoA8.DLa05KUw+jtiTeWhP299phIIOaogQ2J6gfwxPSXQOC+Vc3OkBuIxdF+dFEFFoAXgB4.+rViTWd1D13bqCtyEWPik0h1o.msx1BRCICy+w4+HVS9qyu8SFVchDStWt5852YiX6dh6HUt++ZFIOQIpIa62a2FrhhrHjVcXc.+4Ag1efSmH0001t+91S.BIZRbYYIY.mpqEvUWtnnFq.3klENrzRKTTEOLuEpQuQ2O9jDo0Shv5bP95hGZzLmQ7gtCBj3H1ycCAmJWOEHgGqYWFqIoVKo9XTNJ6dPMtAm6RiAQUhiJS5vBsIlcHx1ae7cD4FirpgEJo.woraM94hw5.h9cqhEpL4gPNHaK2wnIBA.UnSxtYnC.uTe9O9yd7lWeKurFHIlUpJzW3JAH22Lbql2I..v3NzK8fk5QTS6ZnR7grB9N1phygSbUf2mS2MWr8rPt9k36bqZkPmeVa7wOso0DuxU3ZZ.2F6CjF2vhgxdwloB99UTzL9n8CzQKGrV9MPY7kejtJueyZvpZe+c7aWE9O.fpq.mCSqIpHjy5V0Fswcf94sif9G4msu39pyonMFnqDjgPO8X2KJ7+DGGgDHEpyZXb0gPAkF.kuKkg3KDIGcXxky8pfRhPL.LQNJyuxYR6WOXIALy0T0kQJDXYxaEj+xS6+voxmRP9G8KGKMidzeZ5uR1XcwtKk0IZw6G0qGNpnIJ79uLMx6oa2OKOlH0WvmXmTzksUahtHyaCyb01ID7TsAgxRWpObJxAwXHvLTn0MTGRbJbnMOcffIobh6VOYimN0PyR8Yvdu0Mxq1F6a0MoejZQ3z0RzrOd6FV3Ls9ybHpO34ZbrMROaEmU7RinwntB8wGi74lH+C6xijl84j0+tQI9iAROOvWqpahkqeEymsykaetyOZhUAsCvJRtFPEwD+hc5hjErZhFphWhjC5TQ+xGU8TFApPTzi0gPGPshsLUapOj2f+6yb7ifFqcDkLBmWK0Di1mkf7hJQyQcPSQB8pRRhfPkJI0h30n9NivLFtvmybuWxzXBw1Ou0F0QXLKfmgO3ULOWn3ScJHrvXcQWhNC0HjmcBmXJmlB.SC.AwKhZFYODs63pQsgKtVlqljVcyIk410bgAyAFFKssQ8Qa5UdmwV1Qgu8c8GjDYPQ0+qBAarmNRv9dxormEVdaMZgBK7Q1ZcHlxkfNqAcM5R8axnKXHKBp5X9vDK4GqAlpZuPg1UvVrxsB15GrVlDUAub8KZPEGGm5TeKEbHTJlj0Oj4n.AzFFJT+v4EDkI.7r5h.vRgNUGR2vTBskBFMZ4vpV1ynBkfQXsHGEiD7xjcPB3GPZc86N+IMZDww39w1mBsXOOuKaqU8Ye6rA5BxoBEOSpHD462MlLLZJugrfOu17Ycj3VbP0eeZfy7hb1nDCSXwvQ1H.c0iEKxXU8LT0mQ7YUyGZD208M6zzM3qjlaKL9ors.VBBQTFi4LrLf5elJZQ.Ka8j2+2z0MgSnpex6U40.KAvVXQWr+nGay63rS23G.1yQjzpiG2ENx80n4gCre5.DohNiShFvUeoPl1TngYsJ+5pClmynK21XfNcSkNqMMUDZcrh3iijRm.o+xR.B1ZzFyHrNi03detdrG+B1WIakG3WGXKYsPZiczGh8d.1smh6JNL9SPegcd6MqWh0rGqJ6yw1d90BMf2yN7UOf14+zsQcS203H3gA7vku0vMzcQMs9N77S7BdrekFEej2KtIdGcLe9pMttMsK+xCqpjU87lqOrHUqF.ExzUM53kI2RUoAgaGVjkyVLo5.ET.HY0lbQf5GRib4CbsWwZJAaMB8B6RvN1.afhQTRfM7rO3kooUM31KateTz5FjKUQt0FdLYMiLp.+wJzpaQqVWvGnN65SKA3c4w93jhC7g5LGHiYNCNIorU6b9ZfqBh3cFoV4QLTu7d46nDxlP+FlhWJ7Ohc9MPs0bCrxlq.DG8wuuzr5.AJuYWehXGk0CTEb0YjIfsMn7PH7cDhzd1NP8xG1egqe8Xkm6xMtAApGSZQrmnY29U5Rctk4hHX271kdsa9Hndx0nbi74drTatuIIE9dWT75EKLJktz68r3AW10fDeoooQWaSwkT.iOA42vXdgyJ2NEI3xr1dwa.rhpQtsDSy3o513cXMxNSvC1boMcl0cAZjJ9EIaVDAvL0NOueqOaUoh+P+ig0SAO8T95Oop6MgSSq2+tB.YjErk5DcvH.EmXetG6f20qPT7hiy.iFlswqQvtgpxZmAYyCpSqcy58z2lrsO7IolD8DXreMkuwRO+tYqj0hud+TpAqhkjN.qqPACNjGdsj6QHdl4MV1k+EQFsZbtBQXi6HtolXrnw5VICQ6DdNxebsIxkEsOSIrscGOZ6P5mY83Ffc9+Guq9uhNCHFzoHgG7pnQC+Pa+.7v2ie2rLo0EbTJzUKuSMDP+6svaZXAnUsnWEaYC.8+HCbLGeVvCgTsOQIgk6EWGeAIHUVSrIdazSz3+QqrHPYMazkWZanyTVyNfMSNkOtnzaJZZwsJblMd62gk4BBw4LcsDg4uh1ToIrPrW2skYjg21Sm2+BqzAi.cZDGVmgN3reH62kjVPtYqkmjGI285LNaw4kiVYSoRAuoReTMOzjxhKM.xO1wUInPl.VhJVFtkp1Nu99HEz.SeNn5x5K6I5ZgVBXWcrB0bR4F1GBXt6q+YAKxAd2XUyYeWNZM0YOIsRcv2dJjghGCgZlCvQ2vZbeas73x3OvXLkHywrHDSkCBGHmOrOtmrFvctT.Yt7gxYvnrPmlLQ9k+TzdMZpwN8Izk6D3O6uBIDbhmzqFNA6XrbeGq3F6A7sDEuIzsJn9jLyq0dBFiz6ZeIyDTVH25BhNRq98F9AFE7NwE8AAJRDNp7l5.WfXK72Ufz5JS53H8mLyLfHMz+5G7Oa0HkqSUfwrxaWZ5FAeye9HnCG0CmpRIMIV5K6KlfZMxBZHAvRlmC4lpGoGf8eMkfcLOS5Oti8Ibwemw852KGwhgzGs042uAELcWpIi1hVgkmD3+Oxl+SnuYUS4n0DxuuuKFkf9AjLroTW9lQlOHGNZsxQa8Y9QiWdXzGUN.0vecdmHVtK8PGGv0Y5mouV4U0MHqtw8u6xU.ZD9UQih0l3gxYXwykD4095W6oP8FMSHWueHlKV.eMpskXX7wOxL3iFfEkUPurhXRa2ESC8b94LczkUHzrX21HjXlWKX9.JPCxYLyabDWDVnYNhjYCKfUSgOR9+Wn96WriUP7ju6tKLEjzCWNMdBB5L5Pgl2bCc4OgWHfoOmSBGSVpZWGTzwzLkTgc2sHRefAs60ANoVmCoVJJE.rZppVX0pINlGcTkGzLdoDKQFhxzCIBspeO2cFJD0u2hyMk7iKgfA6r4lSCYzECN.eJX8jz+SJDWZfxjWE.0QNHmuPtRRS6TGOBp7gJJTihWEiutssSxjIU7p.iwzlntx6919VB.kE5ldAuLwkDIeWWDaapCWVtWJgTOeDcWsZY7XQDCeTCkVmJHMyJBJs8eVPBzAus32H7yY4ORejfvtW.t6G1QKKRMs5fN5GR+jdmVlzObwakxc4maE6ld9wvyu0m1QeozCdBUJuLr9.Z+UR3UYpsg2hYvLMmj1VsBFB2KWJ3f2utcgQg7VYeiZZd.5Loo7IGk.73JoWo12DBuyLbUGer+9H87yrnupqVVm1JBtkPnm5OA+L8xaYkUgN36AdoLG.zD59DQKeVnfJwMHHRf9R7Tlmp0y4rG4liGHhIK9C45Fgan+pQZxqpI43PSaizfApSuumFfjoWHO+LEjYyULPCRxfArFTKJNXZ1u13Cs7lEToO17vpg1WkUHiXJL.SRVgI2pYeeUZO0m0bjQ0AoxqfgRcU5sgBiOugFxN21lwKb+frUZAUZ4a3PK850IEDRg2OzfdeeTyoQEojn0j6fxM3OOjBCCPkOGFIQSSzwQ.2sAIrLSjV4vmLmlCEvGdj6TCKya7SyL8zVLOC6ADlOJaTK5I4RpjL.FMk.X25958nymQhf4NtXc1GAYHA3JSTHYAKzMsZ.QYdL1gtAZv2PZP4+jxJLxr+v23uR4XzHQVe47jUR3meuCCyKQIZvM+FdAreAlj34WSDvKezZjhokyqmFfFrnT3jgx7YxUUisI5EKKMjU1qhMoqVZJg9B9RmdNqixg6GzXFZBzv4N7qmbPHAVEHaGRIHEj5gBPz8.JkBTBpSDOeNVK1vbViK+njSvJYL+M5Z7em4PsJQOTDEgFn4t3fiIepAqT6UD43FBtQ5v19HUUnZ9nfcgLKQNl2+aDGKCxxYh0b25E8vMmfz6pACFAEiOOA4Y4CwCfdC+xe0EmF0Q1D7INMrrxiwmjJ7UKaMBhMG+gaLG4D9WKtYIVcEKNiGg5IfTpkbKxI9TkTIcmCB2fUK9VXgC1A.nnjlDp6z50WZm2MIxc6UZMzRGj4eynwse9PICQbG4wxuq9Z8mfsVlE6go.zkva9kBuPT3VIAwyf1ghXDsSQyzA+BN55Bao27UifwgF4uMkuF5afsFSpfoV0dptHf+C7OkV2cRPVCgkU+z5kwOvKmFBToMAXlFAA0HUZ4ZVurCmtqMmgporc2SPYSWpSDXO5UgtgWzL6BAzroDaGHyiB+xK7d40ULqe0w6IXuX5U1DUGKj45xSriq.kqoxIIiEToY.nqm8ke3lK2acf9FPkKXBmq5bItNS+QwORM4+8P8jOK0.gFB2Q2UkQxkPoFQf21TaUZJ6l0ItQJR9FVO3Ab35g1dl7ayNI9ky1bw3c5NBblhwB4qGRLjqL+.z.MoBOQ1ogkivTvWMp.sYKlg4bA3Jmn6FebB3LoSIrYJ0VpsCv31R7ZB2IiVORhhfvvIxXlOtbars1n4y1YeJUtPQtv5RzV1bYRqFy+lRfJtMBeaBkFfRHu41VcgvCQghFfABujjsutoRaoeSkkTfjAExvqHqMv4RZX6L2NT9uGltDPYIlJd.gG4eGJYw9R256oOdWosN38zMQapKNy7N.acdf6tOWbPdKYou7CzhEYdkws5ubPp99c.0n+1TskviQFk3g+tnMaSSdOVYnsDGQZCK3b3AcNdvgkto9JyHbKgkeBiPA2eK30ORdvr0iJ35uuBHSh6.GpKZguhvexFGMZRmfGA7nxYzrOTbB30AHuhHui4A1JT7UIOyp18GTPk8pP6+Pp57Gng7+vkZ3AxByMScHvnvCJkd1Cmh9Fc2rpQHakOujx68czPMDZkFCN8AHndE.qAhoKXjragWWI05ubXptI+ccjYArttuRGw8wCdF+E89CVr4kJgERuq+V6K417d9UrRiJKFsQQg2+Yd5IJWjmopy8zPjChamL2iRgitC4eOMeXpRjpI61iAaPcxlD5C1TkqTADDe96RyO5VCA.6iknr5FIsxd9pLwvRyMQXk11f855t5JnAlCHl63aFXyR1hrgzeyu2NnMHxu5lAo5sOe3ACw1g3Z9kj35r7n8JRW0UDzGjHvrJDL8m8bWVAsry38HkdByhUPU.yt9MKYg8kki1UArRZyVL6KNKy7JS.nNa5B5rJNqiORhS5fupsbUod9N1as59eprqHz1.zK1P+IIdiOhiu29Xv0CGphv6eX8KrDMcCZz.PEe1NqBgZNfUaJkxZ2XVZ7mGtaXFRDqATxZPy9Ly183EOJzrr4N7qaWDvtNsKxCwqClOvCXIc6VpBop8Yob9O0qTSfVL0dGXBN30XQYm0N65CijYm3g5bbDmrfA3reysCdh7On8A3UXnU+Cbp3CnMjk2AmDeaUE7Vaw4CLhzD1slPHSrsRxzTSQOtrRhCzWxy4yfdvpwgLxKXeWJac206oFBTSAHtUsxHFH.Dlbz+Ro2QyWOnNEaLHdmjBmPf+IUZHeO3RxI4ogVC1BA4L1SYVxBeRjQfBEU1AUmWTphmRbEUj+8JhkFAP8DC11ImvTgfUzx7usV6V2JE+QCbrFnCqEo5PqnCibzDvKeaneVWY8dybBbzEn9r7jvypnyH4s3Gfc71eNL8x854wH.3jHc5faUMOuSuWck4siw6aetWnywP41KDBuWw9muCnJTDqF1qBve.k2wwQYLUrH+k90.l42prmYIbQWlLECXbvcy.f8xgkH9EVKpRdct4HxxsnHK8Q9ik5eCnp0pwGKiCCIYkB55INre3p0vLxBv60YBO7E2J1ZI86SL8StSWyiOHB4tkAY8yR0yQRtl8m117.dIxmYKRw9.Deqr5.cZDaEMAHnzwuPMqBzuNo1xhGPQJKSGaBsdknBktSaKNbwA4hr30v1NBXHzqCyXz+g7VsRP3xDmlk1gdBbmyc4pdsV7sMDofL6Mvb18l9HJqswZMIhvFrOt.Z4rR7B.cGA3fiZlR5DZqhlOZHC6Kb5mfEHLUNSQtVz5fMvlNOyc3+KowWbzeSgb3byniLk9+HBRsGFKgkvMFKiQbygWIVUvaWlLR23V0QVT8y4qtaZhe+Rx65g30S6G3LfaieLzRtcr6Xiayl+mG0SnTveIG2FR.hcEEHxnZv7grP8c9SilYe+Hr7hZjVWHsx6Nj9lqVNqbd7BQImQcv83V.tTDzkdUWvQzn+az0UJ4HOLXZURsb25j3mIMty4lzWoQgK4Bd+lgD2T6M.d1NZKzjZeG3eY98HwzCr19sz01qE7AtwYeRDnfKjtSBYcLKzQdiD6bfmnH1UaRy81lCs4gMXa8VNbVXr8SWP0g1PJDylKXVnZja8G0BuWV4rPlHLXwf.xJkmUiHiTLnTJkkHlxT9gW7zkegUQu1tACBi73kiObUTGtI9ge5u+iux7Tkj2vcwVEX+2FVad+hbEw8m9KfJ5ANPSCDVT9yXcuTNrQIgFv4iwm5+Z0ufmID7AjtaKh7Iu+EViIUELz+8zikqJNc9NfnAVtMxZQMCr0nSauhvxSUEB.YVx5LqIr+BXHIvhjbe+FUEObkX2NjUHj+KX3qGJk2roIZuGRVljfmxo0UvfGEg3KEXlbzLbLOHyhY20BFeef1NgFO6EmHVQLnxWYyuXMrJ0eg1pNVvXITAflV6wxW6HuSs7FnyDUPbbiqkpZ76I.Ror8YrTKLiqQzge.9YkksrSQSYzC+ynCGP+172+DGFGHZtNI3K.RNCrIcOtOchHt04ifPTe9YcZW1.+uuHDmfSnw97AE+egLcHaIyNHdfU0Pn0FFkuQXQtImlZiEsgRJb7i5BPa.L4.XYUBgkXhQip8eAoPdQIYpLj91T5Rq42p5sd3Xmh2NGRrqhvw6ze+NxEBuIMjNpVaLi9pz99o54NJjUZR33ZlQRJWOvhzGimgIu+HIeHb+4O4zXxz.DmIIouq50s2G9uEsZzZMX8PcE17OXNuD3DfyGazbkRtrYrJsApmhYAFiursXScjFr82Ce4ORZgyZyjlCFU.atG9FvqC8VvpH9XYLtvP7JRBFd3BrX8nQYk4yqTkTyQcuR6YIhsJJ2MMDzVVRICYLGXCxvEvT2Uu+8AzSgd.8XJM24bUHkGCVy.rDN84y5G9EndyARzP3R1pSa8JRrpZgRxUI433yLROQTsvmAeGnL1NHfb8HyjMbtszqG22SFA1stv3CtV4V1NSTXAIJ4nnXn7yP4Wgt+YAEIAZQJrkvh4cg4midclqYe7mx3NGhegaujBHBxZ1AVBPwVGLghwVUgYIjU5rVyOBLhdS+.uj7EnJDRgvx54cHLUvhzy1NnH20O8.wthPSS2P2AjhSrv.mpJTF7UcP5qI1ZLNuBhh6LvqK56zJYsoTB5tVFBbXIESVH8fAwfZl91ifu7oRkjiihiVZlJVVeWfIxNosKuSgCXUB9VqSTynXVPLbjCis7BgfTH.r09.34fvIeD436cnOtloltpbxUYPLjjk+.g8r2OAap5g.U+mmp.gD0o5eny0hyRt3e15WGNAYs5IC0rvLHKRv1eEFR3y1tbzeOPfpCwSlVLDIxJoLpG2wZv1.sExcE0VXRL95WTTDmp6GgZXfbSM0Rnhe8iER1S9wAgKvYwW0HtYgxZE8rfIzaaqH4WVFsWEcI5p.iywjC69KP1455.4AQfyjt8vPyPfSbBsJAR2VNdGKT59.aOBBNrEE5zgtI7UPUo9a9qXJxjJG86jo+c9hlJDkXgwTBk3eJk.u38laXRo2b1gKDnNZ8OnBL0LzhblBczALlGTYMVzty1uo29EDyLSFrWNP7d9Lw0070JKsHBarPtmKt0ouIuhE....P.A.........P5C...zrTRNQ....fNA........D.....ZyklaA..........65Op+EHVPwRJlmff0naN4JD.........MKkjSD....D.....F.........PzTI4T.....A....D....fDPh5e......Q.ZL1MpC..+ifAETiausjkRasV..........P..............bfAE...........................................................................................................................................jdXIDPB...f54feYE8cqgj8OdBu58cxaY.........................................................P..........D....f.....H....TC.t.fM.3B.3.fK.HC.0.P..........."
						}
,
						"snapshotlist" : 						{
							"current_snapshot" : 0,
							"entries" : [ 								{
									"filetype" : "C74Snapshot",
									"version" : 2,
									"minorversion" : 0,
									"name" : "Kontakt 5",
									"origin" : "Kontakt 5.vst",
									"type" : "VST",
									"subtype" : "Instrument",
									"embed" : 0,
									"snapshot" : 									{
										"pluginname" : "Kontakt 5.vst",
										"plugindisplayname" : "Kontakt 5",
										"pluginsavedname" : "Kontakt 5",
										"pluginsaveduniqueid" : 0,
										"version" : 1,
										"isbank" : 0,
										"isbase64" : 1,
										"blob" : "94798.CMlaKA....fQPMDZ....A3TZOUC...P.....Afza0MWYf7jYfPEZkAhToMWZtcFHSUma........AHmDRHW.......P.....nMWZtE..........rkhtzgTY.UjmraDRKI4X2ZI.........DMURNYG...P.....HA.........QSkjSpA...D.....F.........PzTI4T.....A....D....P.....A....D....................PChUVgA....3.bP.......A....D....................v.....v..L..C......................D....P..........PzTI4Tc.....EW.......P.....nMWZtE..........Pvo9pkd3M4sf++oPSt2gvAQbA.......DMURNUG...P.....fCW........QSkjSyA...D.....F.........PzTI4T.....A....D....P......7JbA.......A....f1bo4V..........zZnVgat+MTIalCBPOks1CFF.........PzTI4T.....A....D....P.....A..........MKkjSC....rEbA.......A....f1bo4V..........jUt0xYy69DGflFhJwTO76Rm.........PyRI4z.....A....bH.........DMURNUF...P.....RA.........QSkjSpA...D.....F.........PzTI4T.....A....D....P.....A....D....P.....C....PC.x.PM............i2mFCD......B....D.....B....0.fK.XC.t..N.3B.x.PM....A....P..........DMURNwF...fuA........D.....ZyklaA.........fiOZ.p0zwSuhodDR2btnicNF.........QSkjSrA...D.....F.........PzTI4T.....A....D....P.....B....D..........M....3D.kAvc..B.n..Y.TF.lAPX.TG.rA.c.jB......................7++++++++++.....................D....P.....A....3....fU.jF.tA.c.DF.mAPY..B.OAfb.bF.gAfa.LG...........vA....G....vE..AvX.7F.rAva.HG.A.....C.Q....vE..A.Y.TF.1APZ.LF.kA.c.jG.vAPY.XF.rAPX.bF.yAP.....w.vB....bA.P.LG.uAPc.3F.jA.c.jG.vAPY.D.....L.b.....W..D.zAPY.zF.vAva.D.....L.X.....W..D.1APY.HG.rAfA....w.fK.bC.t.PL.PC.F....vE..Afc.TF.xAPa.X....PL.3B.2.fK.DC.z.vA....bA.P.XG.oAvb.jF.hAP.....v.P..........H.....QSkjS4A...fF.........A....f1bo4V..........HRn1wO1mdTinNZTcFG9n5HN.........PzTI4Td....A....fA.........DMURNE....P.....A....D....P..........D..........A....PzTI4Dc....9uV.......P.....nMWZtE..........aHRAY3cVKAeqCw2bYUOOa47ZA.......DMURNQG...P.....0tV........QSkjSyA...D.....F.........PzTI4T.....A....D....P.....AjfuJ..eqE..j1pS0VkqoK8J1CwRSAZsZxs3id+4o6gp0AXSIkUnQiy7VK7lA3i8yXke5GZqVQbt9Es+VnJNTDonDV3VOi.BtPIQU.h7sr2P84jKzgFQIFwsxfb61gLpradfbRO1H5fwZPpNARi9dz0kZYais+Z8T20uVCYyVcWrxi9H36xN+6sfbe3wCRf132IKA0WkVBs2l7mHKwm5w8I5K1Wby5VuUrHmyci3iEODxu82IZQ3TJphR.MbdbMonv9RqrJUck6OUfa9X14FwRzGYN..E4wn+CUJdS+7BtZ.Toy9meqIn1ijiw4z8kEjlsMU6sZquny.gDB1V00FB7VZQH2NiG24n+ryVV2BSQGLn5LftzfAA2WSqoDSZSDqQSMMENn1RVYaoOLHYEj7yaGPM+SoxluHsgW8k9QVX35Tlt3u0mlqJFcp+3ar7pOFnPFwPJNq1ez9yCxqgih6jO9+h0sQrsrIs+GOlVTyfKqjaT.tfkymuQ9ZPFe4wdvStlbqm04UeHSssoVlgJ3pbI7WUumeE.8cqfIPSMI2RfdD7m.JjXhx7hANJyYkPm7hsHgjmYAArLwUTKqmrV2ixg7X4G9trGKvyUd0HU3a3PqFZtyl7oVTmyCGot8Dn8X+6YF7.IlyJAMhR6eo1JzZzoOOupC+pRpxnKPq.3ARNjdj6RBC.I12OOA+ICNTOPC2lGV5r4JNYUEhk0n6CE.lz7iSG+4F8fX3mFy1xNdy0HnvzkpY.6y.kacM68G8k1CuDaeBYL5d0XRZASRoitajfsN3LHzhZ5ScP6CcwLGmllTHRLgL1kwnx8XnmApGndks35Hgvz.3rdi1UvY9J.p.Fu7o1ydMOSgXbOEV7eyBHSYzQjjteMaUSQz4eiMT348UT84jPfwPZDVmOWMiymtJM+8t6DtYfhoQmFl67OdzFU2Jzdc.BsB8W07l+jDgrqKZaa73vtyINfIpF4G8dd3+E.Kf42HHOOd7DKUWpWsctw5.K+D3z9TDQHpf7O1ppl1cN4bFKO3totnF1vqumT8v3pddhACynmxKRF6gjtJ21aPibryfc81zzfxntJNjvnGjT+1GMePGaEqDrbgYsRvFp6GBpOtICU9QxdzlEUIE+F+dupdQB1nHabCfpmZnQMK+QzG5ZWzervqoCKJlFBHrZIBJuyoLyeZpY9GMN3VXVo4KAsYdBc11we0hjpLC43RGl6Xmszd4CTWa67RSrgacJ2DCxKB6F8VMn10PEAxRiaYyXHNzCKZBtskmwbBByiqgG0nt8wgmbxBQJ3VRXhcV11L0MA6jf0Afpc90lH8oNPxypVImIHyxT51.aejQr+D3Q7Le3rvlyUI03tNbpQ2aWFOLHFQ6CJNSpy6chYKqqQEgPHVties4HcZn+KiQloZ6mv.eEYmD1x7QaW3e3sDUcOnRaghlX74H+PlgoMypJSSy9Ps6MJ0W1zGVa6jD6+W4unbZfiaHKyFoeKpNV1zmGgbK7GCPmKgXHSJZECuHVqajli46gtbJ0E8P4+.WhQY8lwcPJ67UQkKXfgPWfgDZBUJU9YqcGZoDNU5EggM.tHBMgs8FpOY1X9TUiWiVCjBrU90RfBlDOhlmdOPYxVX0EdJd9R16CrRLJqsywcpR7YQmcW4PapSH3eED5Rm3wynyqsf3h9eHoC1tH3sAH.qmrk2BmsrkPuqtPSsc2PPRzVJgQd4r4zSepVRnp3m7hJz3g0jFATEtrbU1tW.QcZxHihHHpKwcjUtLY8e8wEnbNmXmkRJmMZ+Ztpz1aMKvqgLPRU1zXDX8Ifj2rZ9hW1p+zfO7sq62QKwPKrqoqOBUQSBPiy26rx9SbX6xxOqAAuLZ6GN+NWU9XItmwi2H9KjJvIFnk2qSF+n6IPRSocoUyoj8tu6UHQxAc.EUI1J39veXq0iEM0jE3MHaCF2anuhVhwg47QL2.xCG0Q76oVv3DCB5PFowOy6EarAPnLkjhd6qvMGqAafMqw5U2YdaV+FlRZqtJ9gnsB+XI62eT.c3P8pYtMPEdUPWJBK66mKliVR4AZrf.GqSymIaDap8XAwFa33OAM4MfFv668aL0oBkKe7cBpIsdVWa6+H1aYLYqbqkAZVcAAQq4PnVx9SvQTnUWW3enEIuC0XJL6IJP8ycL2KuTFYz08p.Ar3MDocDDwZT7Jyztn2p0o11kzT+oMoW0yVqiyyelw2wVYEs8Q2VMPx7wcytVZfvHYqVDj1bdcQAgPY0s60QR1vWDjjtx.gMQA5i2TS0ZA0YvQHavXArnMS7bcWJ0DGMOwyEEx43XhO3setWX.1nUbLFmcc8d.gEJ8FMd0mpCnrL.dsrMAInR7OnvqXMDm5Fbft1SJ8AgIpLvsn2FG4bgTRKH.o4QSv4is+ZP2aQ7Ivn+b.tmR6oHMOwtXl+miHP9rt9Ev1BCNAzqwLOxIv6jZtEK3C5TOd14buKXR.WBfVxZ598lbkKTW3Dw+g8WEsvkvQ9cIxxfytwvp8.bbXJWS8i2rEW8kK5iCHvSCeTjdthRl7I9jAFdCPh7Uqms.Q+FQZ0iFOFqFap7t2B4fMuiE6ML1QQgv8zN9JbsOHBa.xGnhwpAgw8p+aD7sKSo62tvO9z.tUpGMmqjqrboT5i1DhAATVRhrNBRKxsVFsOkW14v+C1XHNJi25auTsdiw.TEyJ5G7tGGaBet4KORmHW6..gYWQVzLG2TPwSEFy8Ze45WTvodYVT+bNwR6YameCussJXjRHP+GJCrwduabJTNT+VT6twyZ+EgT0Si+mqQ3MV99QH.AKudP47q+fxFmiNDDNSSXybNH6w56rJMtRKvZHyqBK3kvi4bA5KzSgWQQUajy7kulV7PqBO+g+Tgqq9x6ITzjLAGbyE0uK3BCTY4ICwKkfoN9K2A04WzbKFthe1MOWczLvy5E2WoSbUd2EkH6aQPTXCRTQBj1.BSw53W.PFl3B.oyzoBeAShw8v3PM6ML0eu0OjfZHvI5BNvo1G.86S55QVkLRdNKOzLAxk4nx4r8pz9qB0367BatfJ0tAEcqc7iRh6Qz44Kub3LgL.VlEeDCA0tIeOzgmkkY1KIL3Yac5uVLxRbH.8Zb5dEUG4Px570ZV.55c1RTb8PX5441bWJLhSDALnNfhj1q55mh511SKVeCIOmbr8j3McjNuu6BHU9w3Ev0QSDN4LnO32CLWjI7Xpd4ZHE.Gm7hsBKjWNFWd1s8RioLYbGmYAIMdA5CpI7XxnTEmdVjyx1DFL0VpFN4RaCh0OpBl.YyaAt4BEhLK3f6J.E66WMxWs9zV0HUfwj2KwjcZbOLys.BwUyDM7thSlAs2w0k3w0U.UoeOTe0H1AUyUaYUPYf+SlWIBpjHX4EZsaQg4hf1gYcYimnAa+1EfxllmoEn+VWk7mct.tUGtkqbws.YHGfy8b5WBZUXU1EVky0TKfiAzfcVe952BhLz1Ezwy+81Awv0vsiVwQXtrxErj5K+B8Ip758GKda72AyMN7KVa21lj5kX146sOFPVm5X3z.XPA7OX8qBBM3xKLIpuJghgZCZm2qZdeGWbgnJEoXj9GbJJcMjixM4oZRs8F4n3C4VW8.F2DBAWgGsatPpBJDgNq02aId2BORAFlpZ6UCVoL1hZrsBU.LJQh2BB88tbQuxHu9ezma7Pz5jJUO1e3wgsAQ8kC772EFdtbMATrkSQLXTJCHr1HH9iVRYOI8EEosL5Cj+UmSIwBJLgxS366SOPdDVzqE3xer6gfWL31DCep3XswcSHaiVlcv6pbhTj3uNUL+fTwhhml6bEfoZc5+OeX1tHe4CrwrcgMrcIomvttFLAtCGm8hjf0TAdctMdYr3qpErOQdAoab0Ig99mjl5JI7UDMAvtIwD9AqTU7dw7jrH+8C3X+Us3U3VwaHaD4dYfH5IcNb9gJpjV5L9Yn.M+F5EAaQMUD9Vw1h6kxrxEBlHjRUE+d3JntbJ20mNc1aw06h8kBYnHojRBTyzSVzTphlwkc57jh7QIHL9EXMoy1Pcr7QdoYRhN+nJNdTj2GL.vDxPRwNkyvpraXW6kdZ9Ieq6Rsmil81UsMTh9ZB1X3r.lwN3ZjvzO0xGSoqf2XH0PCYKnmWPiHhDPLz67mp7Uvlegna2Ce2kdqHvaRtIFl5ofkp8tjk0DBuQilfav4nVuHG6m7zus8nd1IK+A9J5mg+9TvCLtJNsSbQOnX4cFx3+AeUxSjmHOXwXgZYIyfQurgh3sHiiUD.x2gKRq0.cLpgtVhvJm88EJ90khphzixdhSI01vLsTHLnwdUOOKojxl+NN3GT.b5ugp0Ix5gorifxKarnZpSPNOtCoH2lmY02EQGk+0SC2T7xyYwH2sBCtaIM.HL.v779.0z0BgdvtwWTTANfKxpnoiwHHRJIXxnoQn7WhdMQZ+uyaAHJJL37l9X1TM3nlXDa+7WFK2JQukYUVyWbl8JUARpO9yPaaTbhgI8XAlZVTN85ufGaVBuugYKQ+VVmrQwHtpppBmd3JGUh0yAwpUYjs4PUqx+6YsbPZY0W5+u7afbsxjhDQfaw9CN+9yNMyn2VCMfUVl2f5Z8y0GRFhYu2uStDSuozcCksmXoZE99lepVm+NX4+Vi2cBKFjd0wxmEM5WmzMVeu2X11HS5YRbyrJzcNvMnBDS1reyUibOnlIWRxbfFtvlLkCgzs1W1z1B5as7ehz+vXq3rAzHAT8.pJhVwDQm.hzdnrVTCJ6m+IiWs5SI5IeVJqOablLe.KVwvm0wmvixIDztl.DS61iZrhuSixFu4gQPMp0zyTmH1Hu1Nn1YWTMjKGydB+wcjh5eMm6Eegij1UJiL2dtgEanCO7mWZspVV08Gfw9HA6zVaOkbHUMkcehKY.N.XFf4NXsXuK9jEkcOS1OA3wN214q5fUeB6FeMFRac.cq.nU457cfacY+DQtOFYu+BXCJL+U.4V8kRVJYL82AauCM5BMinZ.PfnTleqNodMwA1ANKUzErRmbT.zMFq6HJBnXsZ4FID4kxFrsN1W0MYv73XLZhQjmKFsZTXcwgOPPYh4QkjWdJBn92QJR2k5oWikgxeaRmpB4R8tDURqap68n9Ud6g26UZSzq2E1XNWmo2J05lcwVpI35brQSZRwK8kCHeaCst0KNJ5+4BfG5xwl5HkaCp2j+BpIIlgRH7mWw45ZEL1J7SfwR.tUmCtY3hnAFdlYuhFQJhw6qgE8QjeF6irAYrTEhkdX2zxmOPDeGo8xXJmzpccRahxmgJLZqulbJKKhqryht.SSZ8483sNPL8yZuh1wmTJ4Ou895miTyIxb2rTfkAlSpA3swfQvFi0FGoJi9vribYcG0++npfTQKOGZjXydL8KF3kO7ksq+0cOh3gsTqBfH7iIg0CRQPdUtglTzhEx8KfWiQlibhFITx.xsa.v1D.11g8Y1AIKCsCLhhF6TxQaAy3GNHZP2+c4HCe83636uLwx9RziqKBUDJU4F1PAhbxFV6q+.qC3gKbNvYSeu0O6R8Cy.eH7Irkmnuakymu.mhbvR8lNnSSBZDVrmFtOLITG7j5pFgSuwyNOxi0nx3Mm0TU9Hrbvw7PqMwkA1SQZrkbfDAUahIlghPz+ftEwydJeRjYY3c24kzq7NFPq9u.yC9AxuPjI4Cm6rCF9TA9beHheA1RQXh4zQgRd7XnMbTjIHYPXh8YihJSP6jJSLoXRebVksCNgwn886TCfEZtSxXR4HcJbSF7jPHv8HMVGp9cBIASBpVJfsimRGHWKAAjSJm2275+J9H+kyi4WZABf1jaVfui4f9MCbddgGw.jX5ntA43NstBfVibJ5UTxKIXpO8wtCpEaM7pU.OGC8qhpOKX2Jd9XDVwHOc7FclQ0YJDMA+Onk.So2Wfyfe00W..smnhPe9eVo4onBPEjlNkbdnw2OE5sKopvEpDusOJAffI4FRqPaU67W6zbX3u+bA1uG84KWsOc4muuPUqnkOmNqTHK9UIHqW6OiquWQfthejrJMMUMPoTOV5wFy8helpk5s3FEZPleQRtTxJuMEE.V.6lmOkZbUMsqXCt3T4OVCPtL1usmRIiFSwZK45iY6Kvcv5RJC8.2z2G3ilxdPFsBx8whTeP5hIc0elzfiCJJ5RCB6Ta0GQcX.quEUwRXEZsJVkWfEdpli6dmocNL+GE4nTc93NnDvklfvq6j37L6yxaVHgJd7hhZNUMQuM+vxAekwiXfBkEeWuGxk7xyESj5U62yGb14O+JOHQtJYUPr6xD6biIEo8mLRc1tN9Zmc9fBVp9thlqnMMHF+nnEp2Xn6t08M3l8A4hFwZaj9sNzX0im7HCEwZtlwgKcgf7jeoij.FmbUS1qbuxiUUEC6S.DTBLkwk+qmyWfRh25VAhl3ISz0bmrZ1oCpCUM72LjUPzE5ibBy+4l082vpKDSYNYezv3LFMCn22UNU8CWAcuPaMPXeCIqiisUwQxoY78BSuUa6OuIsPsVxuS6JC7rblvfk3P3cxNJrAVvrkivgo8XimsfJYYF.ASKk3xFYwaZxKA5VqU4jDb5yOfLgj9nuyeqNjU6rj2yRMP6FSSOZ.wJGJZ+XDld7R54CbCiOgXd7uAZo095VzjjE2SACfTZoGank8w7pCkRtruQe5JTmDPAgHoE2o6Sy1.Rf6Cg86gGrEo2EVL5QXfCKIeSAYd8SWKhtD+K7awe7juOAysyekuM6VgZ3+AxlpLEm+r.emvKw4HfwVEWMWoqCLrZsqoWj573rHeLlciP+rvft0rfhohw94d9mXpzTAyv1Eg5bDt69yQOA0sRUgZwVx9w8N8sUHwc7IuLLeut2YCKGMXQZUI4r3vPAPjjELIJSm7qu5p9bKJfRU9XSMAr9v5xK4RmfuPxuOh2vmTnlGqVDEKRF4v54yxcoSIRROnCBhFkx6bfCn4msQ03daI1MZfK26VpMIpznRW5T+vGMEGPKFJ3L1bA2O82YmYdq65HjwSnBplyiT6xQGIaWNNfhd7IlnzPqPHCeTyOhrqbdesGHzjNcg.CAeA0CUlRw5XRdZwachXSztxLrfD4O4745lDkBY5jr7GqstFDZ9rtk1SPp6znvhe8CoWu50arYCDCQvTtVjiL5bpDa6ViOcP8tId0v8m657cs8MRoV4RS.DWC5nc6qrLBrG9qZGy3ImnVxL..eEAfJM5gO.mfSnCFjFVrz1hvmVb6bfcdiLaH+8VUpdtm9zC5cdbext2RyMBooTCN5CRMeq62qmG.vdZXk.PP+YGnHFfb6Y9lzwYX2G67SpI1KWPm5wtaueVzrlqfAGD3w8xeFPNn1Dt5uXhMKoTgS9YMKtq+koSLbOXKS9NOi9aShjY9KAUT1akJfTaRQJ.PHlYdlcRekwTfA1UkvGSB9oEbE8zfOdLudKCgmHeCSquVn0yjcKEOH16+cjgVqVeo5w3Twlroz3AMViLd7CTmwcj3EJVyJkZu5AZpkffJ44B25FGo9QseGMtmYAF.ACReyAq6zBbdsW6mEuwDrwTmftzyAkMbaarwRNnNBqFfK4Y76mf2Oz.TZ2A0C8M3IiPZLYtHlBJFpB8KPPIXpcFjk6Al5Rax+uyLnf7Wkpubds6DYT9pTz1H43nga6kkW2sqLC9iFX4Z4eEg8gjNzYOUfsJYDuWeEIxCU0OdRw8HIOxUnERZHr6Kw6OtOtOJJD49t.msXxCCa+ETlpHXpqCV26aZa8gzUTGlNicdiUZ47UzCTekA7UXXBeCI3iWNhoEzxKphkfr2FU0JyamrkAYEYT+4jZhsUtwd5nXjBSEka5ILBSpb37jnNappGheK8t3Yy1LIOERYYU690svRMcn7aShZS3goEFxRDM6ZqVcaAWlew5L7QXky+b3wgAp9cqD5j0m1mQw3f9krGj0Q4sFRAaICREUvQK1SPh+DGaYBalQL2ls0vcMyC.g+jvVTsiTM3XszVNUODWQ.NGKbWs9FSWarvjzKia7fhfKgFcBSmVNMfPUtxC9.zTvTKBqcwy+LKDanCMe4PqVrOVhoOblnCThFiD0DQbC+Fy4a8X+GMrlG7lWIEnEl0E+OshieXIsJUD7NN4D0cjeo1OlC7tcmOdK383SF5AIavLYlKJ6Appi2.qAqHndA1yqrbVGCC9t.EnaKpr7MxwVeRmG2y.iq1OIwNw4H5rjNYGW7KVGW9C8IlGkpm+LBwJuddi3j..BEzVJ80YVye3AdWH9qhWvRxnd1GxCHff5rzuYycsFEmBDSmdBKXInWJMoe8QWCuqSMyTCC8GZSNeckEh5ChqD3e9adBG9pno18RWpJOJByxOLn5f+QxqzjF.SYXWqZEeZYFCSHbRTEDbnkF7Zl.17VICd810ibgPatz7AvEHgA+7KypyaEH7YdJA2sF5R3j9.ffNuDAxCCwnb7CKpoBmu9haToi+1ClVGMw53r3bX3.3OgcrsRdZWCG0D7tLni6h451EM1OjJm+ZV5To7crdMjZWTLTAqDOOo1Hdu+P21UXZcY7p+lgMvAhhcQmlJagYOEMuT48vFZ6+2d367wgO1FnANC4TZEXT2lKZWgqs9dVyXw08ssn6SsP+Z8zRInofFAruL1SeOnOnjvRvfuh4PNRQ7BV7eTy6sSdtnWnIgrzDZU0676k+UbmuOHvQuP.SNNN92Tp2whiXylqnz5ekXq2SC..PTLLVVLBGnpYMcMojnDX5d898GIkpXJ7vchvGb7KWWJrHjKUlmuDVooYnBwPpNncqpieLa6RuVx9Pf3TCWykMaVk.vDohlw86Y+Y4yKHrC2OdD2QcAr7utAuMuEdIrCw7USP8KsdAvT7LmHsUj3g7KInN68mEOTE4zPdZpXtsOlbfomhi4oeFuvqcWR4Ihab3jouLvXvaYpwPrJAdU0unl43JI+7ce05McLhVBmfjNkvcCMTcaN8v7WNK3pa5DSyFsL5wtkBOFdwizzH2jX7bd1YD+b7LM6b.gHzPoQTpZYo2WqlXINAmxRHIAsOP0FsG3OsLyluSLHEI1+ZMbVQ2dxn+fyR4Omigr8KFvznIXLJvr3xZYAoR+5SM9B.3eJJMYTNb2Gr4hmss5JgxhoLhDkax0MQzN3Y8pxa6A68Y6fvUrQx3ZA9K2eXs83SMVpfPi.PaWu3aK6DAbjLKtt1.svFCyw3+9SwdsjrzoF97.BRHbL02G8DOsOkCLY9KIW5v+5nu0EhhJIcZms082iqVunyIbdpBOfA.6CnD6mqLl0y.rIe9KhTU38dBwFwbpQKhDPq5ATuV5C02MZKfoSkkK6he0H.QiVJza+hT8IVPWSzu90Gl6dfbRodDaq37PTUbwSoe3oR4mkaAWcnm9q.+PqvD0USmda8oJ8M46E9Xu0zb.qmvleBEb6cMnpNFyi2WErYpFv6p6m9eaTJiOvE4KVJYe1VUBsxAbr1xsf2.Rli6XbpcZqhjzlbAJF+AY2VgAd..AyM.OmmDVJxoGbudH5Xmmsked7mD5px0fk1y+sCzggLd3.XUZfGQ4LYahmk6hMQ.9Jd9M4r+yJUQfr2U4nVoJgPfb81IoNox1w8+xnnFJTzc6+xPy9rseycC43TFvYkz9EX7DePh8crW1chKSgWLq.h6GaCci87DmnzO8bjF6YMcIdgj9B1kC2ZoZvW133W5G8VCXXACeq2bJyQkn8SJYsHaHDkycOu5R4t0oCbi.HpNdflYFLaURp+SpCO.S+AXT9XC9AtWY+wp3XvSwRAW9vh7HMn26u4R6nj8qw3Ck7iHwa8vDb4Yf.NvkFASW7hBOeO18aOKxRt4WQNVY3jiCLuGtaYjDJ..fSThNneKYSAUGP8ocQi8lTIaaYQHQa7iGWynBMNqWa1H.EAG3qVk5gdX9OhXAI2jEBcoDNVVLfVH6veqH4mCRkzdswFiJD8Fl8WqWJg57mnu2FMf3Y+9URuGILdBCg0GdWO0smeoSiRsTdi+Id3l46Mp.Bq6qdspQ9QeJUGXj49ZTb9eFVqgghDlxa9qlkhnI2y0SWDPKMvjcB2psZjpLFJhkV7qaPN52gE619yeYAX8AZTsPQlmIvQXanYUJSsrmDrRVOXHL7n1vVXVssvtIb8YapkSq+AdsIwCx7z49l.UzM9nElyx39422HP+QsQs2990Ep9+wD.51wAPYeBRc2VRiWiiAYPzK5.pR.RsqwfjSAfDIewbrBegpvwEtW6.TrMG7PgQYoImUfK7G6MBIrImabiIMDYrfxMFVrg67XFWbpyZ4NMLrU8nEG+Q6c0NM2STth5fZZzbnId+QtSAJrH6Iq6O65CWnncYxXDGm4y3.75nI0UyLFum8zk6g1N4c+.3.pEIfg9BkwJzavqrjQxVVEgC9owcVqTm5nRjyKuqtxDhqWBrPAqLFK0yXO7ug8z9f0bRt+b8Ht.oHqXStOWSHghtMXq7hhZ8rN2ObIXKlHGas7qdpCr6vtA+9l+6YpYr03DbuPrefjB3UqxbYYRb6CUcqr7r8Cxz9tgHFr.qEivhwVXlZFYz4fDal14zSXCF6Dg9pdl1q5SSnrt1QJSE2bAuansGw0ODoMzgS2H66UX6vqlwAHLiULYVXoxGePEsh18V0n8NZo+USRzS5PHbFQbpBsYqUDSiLT4CJKr8y+M77fYVR9k2DQDLOxWwlvURw9.Fx.ZweWDZ7apvWzLywkNeAff+lGxVOgWU6rlFfVqrOpGjRLzl3x1oOjJH1r1cFxbSWnYMazABtKgvFeg3u7S58ThYY6dWCmeitcabV9P3erL5pEMsTcKAOMn+9u0ZNGEoLpOcB7TJVN+m1WSmrCi4Nx5ZKKal30bpHgdjs8EuR5IFpmBinINB075im.aMuZKilOXXOv92G09vPhU5h+fGYd9vij42AdZYhtOtsb+RMhxkic3PRayPX1im6+3F8yJ8rtZK1EFm21KvAvcYVZ9N3XfwuD.XTFFPldKqSIF8IQ1FTA4iLo7RcX7RUoq.pC4UgCIaOnKmzJ0tiw3aXXHm0.4Lgl8owXmkv18EZ1I2gmOocnAefdjK.Entg+h6.r3SlUTp6QaBwX14wPiVArbdXjHZOrlAZ33HrD4ehCsE9vnIZbho7riNtCSN9Qbs80Kab.n.ukk2nmfMnUTBVaGBrOO8DdpGRRAH+FQgDV5V10rsp9uQL8pjw3vmU8jOMHP1w0F4nJfFr.wuTB27nEKmlSyCI4.ddRSBuaUcrbyteW4D6gUgqxMdVKXSLB3+8LbSODap6MXNZhFxUNpuoFu41PujyrugQtdlHlljA1irY7JGIglEVExlOEg3oYrxHTeQqw59YIeg8WcYqVcJA90hzYJ38TMJPppg2RczDBtiNOzR1AGbl1H60+zDFJ.eH2ZAJvQOpaUj5bama0971wKb9cdD5EpEojJuAgX34tnWycPI71Ptj6Rf8S8eDH0iYLTTo3r9FwHoS7+VSBBWhuhrrVPmhxsB52Ljp8BMslaKToBPPGz+KvQJERqczTFmkWNNMX93DL8po1ZArecnfcB.sL66CN6T.wZ7kHfYT9Wd0Dj09fSBhnyJUplJfMeO7Az78GF.BkLch.LoiYeZr6AFlQwolmzXbyJ6Up+u58r84AQZr6hZfjawaca9B48bH5sUjv7bRoXsGu9Pb1OCmtD4Y0CBr5WFaOh3QhRNozlzANU39veDLVrzucglUzmbyziGOakJbZhftETTraiv6bBABpoPKcgmBaFKbXZ3rdACNIBy6JaJ9GuQ0+DB8aZ4aIfHjoyrgOkm8XDCDbROUytWe8bbR+w9lkHHzQpWnLybOyM5fMbwRjslhlponbwlfTyYWgHOQDmHonJWtVDmtSt80iEqUaSHcouAa0ZUDSO+N.iviGGRn3obYZWNjvndJTyotmszBkZJyDxjK7CyfsaSosaMBFXeyQY0bfOwsUiUr1+Vrko+KqlnvindNUzXnTE4eUVKGT0Z7NQ9fOGYgBQ5Hw38jm6D.HptkHpwZ6FJLOI1xkXGcS1S9KmHa0ETckUFDxv4YNW+GwhuAuLV85OP1d4zxdGTsw3B3AJdJ8FO6UY9kHCdlQEmB8byAB4NHdR7BAWi+GV0sE.MODI6QisylK5ZWmFzVC4NhbOHC2AIU5BDH8EUHANw6VxoTAIzMcd3YOkl2nCDeaeGkv1qOegEoyz27i.SpQ2YMgVQHCoOMftORW+PmIlnhqqt7l39iXK8rzzaios5UwBWa.l+Calw.tkSgSMfEVcfcn96LyYI2NbqzCdso7S1fE6ta8h55klODiUmF5OwiURv5tECpa6mIVE6Zb+E0DHIkLtqYq3jWaKf7ZlLtq0h9WhUx44PXerKXAOwQhoWycOR6Ffyfvk6sFjLF+KM.w4ZHEMaBSTOCWyKzKuH0Xw71ZXgzABwvbJlJZL5qRJVVZIymPX3rBjNTLIC9uiV6JgG0gGEH0.LxCI2KTCM5+lg2ZDsHjY6G6OgDqwZnBTUInY+.PpBAWYYG.GVJTyzaEIxfCm1ShtY8a3iO0bR8udU6yV3JDUptxuwrgujXREDCH41URSPiHfcB2ReLqA+aMZvCenIGL+D0io8fDBdbamDA1g.nHL3I4iV+vGt4kqfilwCbWpfcXKVl2V5hiYweGFkzf.Fqnl8CrZTOqN3XUjzEZxblvt5hjVcSn4FPZJ86VbG+4qqHHFf4BQvk+aok.sypbysoRE2TewTpZnyNvJb53NK5QncE03r+WpjICWUAzGuTPeIxNE1Z1Cx4P1JxQEJXMUDdAJSdT8y3JN.aXm6WfYQm1PVVaVOs5tWeGG+SjyzjY8o07JK7vnoL.BraxG5Rjj30Dd6EUTbn+tnG+SBEVwYLuKS4Oi45jktYsd6ZFIjcJkA.SIuvG825ByrsyO7klLcb.z7PHUMBFgJegF0UgCnbgkZoeei+Sm+C9reNrxIpRJn9eYrtwgcJ7dsAQaVnpypbm6sSXbXOMjUXeVME6jIUvuk7SsIo+AfM0p2P7PNF2KB8VGSEwaioHGihQdLtT8p1zig.OK5M+ap5JISSHKm4KoOdRpeZ6ipzD3fzbP5.u+XotWYw1kDXMMcWPKTRhz+unNyWDpoY9BAtPmm9YgCFz9De1SaPLUBOfyJP2ybKtRR2AbJLZn+VY4j4VQpLtHxyBEik0M1DJXfUEoVu+zSDtaOEIkeuuPONqQN1PmN45C1wY9q3.7D6uiToonrdDW0B2I36RogUuvFwkcrlLGa+S9iMvm35URUobAU9WpXPzfLV6WWzVIZYJ9NeS.dtC7bzZ24PUIXoLPwNYyJiQjJfkQjy5py.jSXNud.CagfRWo8XHISic76Z7kzf5ARJNavfNe710jlIGHJduM7A36nhqYmBBCKDXWwWVN+FcZHfhPJvfMgPtlQnJTqRMceArHZhLNBs5Y8a2EYOXs31j6NJd.H7UWRreknSXRFlaww5jPHT8EeJ+0HPAAmsd7iHU.FL4GQlivtV19DRLIuOXeWCMVylXABVY0hKFmFVCGXUfowcASdEG6Ao01iUH52EmnkQfzCSz5utF9RhdCDY8lmsGBdQTIc7J1qiWQf.TPN2JT7jt+WkC967pOBWKWG3kA.KkZG8MBMdR6TgJZAz4rYHCeJ2Gj36NUV4hhqRGekCENHpX5PyNm4ElEVPf0zPr+domYIObzht1bTD2wBsMRKgp4qMPXFWEYmOzlZmpQbHriqfJF0blr9ubmh6e.aZ5ePrV8n2.uTTAwR1s6+yyZ3aFKdkqLHIIaKrX1m0Upo3z+8++NWFT8SrtQ0xX9+659aVnEHuaKvEZlWnpVEJinoGXyC9HZii5tvTEcOiAwUCOadBl7gz6c6mPMzr4jx+xlYSsqAVUn2aOlWi8IrwalX9nhggcASPM7B8azN4XVIJHdk1kv1pEmjV6rIz08KHE1gzWLPOLGmkqx6zytQCirs4OstXD.HaryC7l1u69aCqe3i84Xff6pI93f4niGkMT5rdFqRt9EeI8.WBy3YWvlZBB3pbe+e4fSyj3r9OzCovDyPubiTdl5P.4M4tuLIootB.8bGz7b5hiyUfKIORORXy+.nqIeGEjtEo7mFaSO7Ercz5x40nbagmlXq88bWg4dBbv948o46j29qWCT4mdMOKo.dhzhaIYVLgqY8819wAX8dnVvBPXJCgFovvfEbU.A3c0uV1Xn0ImD9AsA.l80KeHWXe0TeLtP3ztCPmH4qEOfh1lYmtG4YrFYSGMHvnrIfRrEm5IJ3evDiFgvQ.uJVmAsYJtMf6Asqwd9mm9z1UtfAKlZ4hWewcBo7hosIsd1aP1mHApoT.tutagVBmZfB4QC9XKe75zIqL37X2iRyGLmVJwfy6cssRPGT3nOeVUVWJwYahqyxh.zYXdQoun0m28rx8VDyIiG06bkjzQtx56QOBDULs9Hhiy7TfNmX1G1QCo.IAsVD3K+ebpkOrWMXt8Pa2I2AU8U+L9I73rEV45Xz5YOAgPoNPgfynNmaAmLx2bHbpxas4h5GkOP6xa+BeNLM8ROnrYVwE6UdHK3veHor.iQiGKhTNhUP8o+MnUEgAFyOmDJrVo2gutFvL82jepUlVyHvKgcOoKxhPLq3zyJzEvVtPvVBnot3zSdyZumBxeL+VIrp43DFYR.VbaEHxAo3fxJe2zO5USy4pCEDq7L8221HoHhnTKvNx7vnJDkequwMWzZirum64GNYe1hoSZJlW9SCr5r3FkqKm1Pr.AdUEz5zlZpF6tJvNSixbOZAIRrzUtRjaHadNHJxZcLVAX.vKqu9xaJDtzHLo4aY2iezq+6L9AFEKxp3iD.ODXZnXDcMmTVB.2C5u5G2wprNR+xblK4YijEKbPdG1afb7.YE.i+5Vj2yevDK6cp7IHIhseptXb8YRftY7dXZpsmlfSKKhvVph3K5mtY+uZFcdKy2GBWKZ3WpEUqYWaHbs4PS90mHvsjmhK3KOIHHQDWWB8ujT7wFQm47F38zAUoaj9OPj+3MsWCSeQ+mGnALUzC6qjN58Y.3XYCbs+ulyK+sUx.uB5XAn.rU2kaqau5JvWmTl2dr6D3xeUQFtfDb6OyUCfjqKQf58xatMuIR2uikefbJcfGk3LkqChANFJyujVjsRYG9a0ouOQFTFlDfK50.zb4pFBDFlZQugpUlZIqD5h+gvlLkLFGpQZ3hL4EVZUmSDb51kzrYeob251DOke+CrGELwLLyKvfZ77rAuN2hvRbtNwCSpZlmGSKAIv4IbqJ505H7o3+QVk0WWjjeyJuYN9p.t+YFo.xQL2xMBZKsdYzwp2MZwbxPc4av8kx5KYtJZwzy+yMqfbKC81X94ShKyiiAXrBQ69RuwclmeYgrUxYQRnoR.yttugJ0rtxasg+MV47oYKFNgXqubfYTm48qBqQbo0edzVz6ohvPz3P1Mxd5q2eDM+Pnedrwc8EFWdjj1tHM6J13uC1joIA4.RBoTwVPfZMp1fZuXZ1mxw8EG3ymid.hlMgo1s01Zjcyqn2D3jMZdt9pYXc2COAXG3A0zVQX6K8l4c6aRudCX+owSPM7VrmtLTN64.Jx1FnspBKHiCXdisl93lDMZ14a25Zt8izSJ.vixCfypsZkgsh7PKhC0PWF5Tq46ktvizbfrmxOXY582rMCpBVmixCU1bggdrzjhJ.b17q35w+EIs.cq1aDll5WIsU0VoM+109hf1I86+kNaSgjp+80nyOSFvxUI9wuj4Nkm.lmmAjAF98m6+CGCMz3YgnatsNmZPgjFW8RLXIAgg8MPD.QzwSBP3xJlqBEYR9OI7n.hnjyhJjfMI0vOZptE0e5eCwByGUcInNamEHCMK1LDfNxKSmneFAMKeg9QMnOGw0k4H2MStqHzW6biMhgk1JkGb1MbRgw7T9Bl8EBuEdYqtWKt.oWK6.wY6T8m4W92cAKFY2ZB+zcg4Fk40CsgE5h7fNj3z3L3jAdd1JkiDt+DQNESJnfrS0Q38iq29+isv8P2fUC5WGbnPgGLDrBSQeJvCQYZBn2HG.jj7uPF2fOgsT+6UX1i33LkzwOMTEJ2DW1cDe6AUKVwrY0Q7P0pfnMZDpNVK1y6k5MZRWkAWJRvxii2mzsd93sl48iDDVmauCl5L4rCsr9ZJi5LjQsPm70ceVyJV5KnhFO.BXOvIlpxIObsQWuwrbQ.tPjya9FB2rud4b5oh1xwpyCBWY+H61xsepC5Da5F6.he3.HCWaROKOhmWOc9Xlu7kDRAsouZI.TXGnGvIzQ4fLmAo8olHJho+r9.39pDnC5Hlwr6OQi1x1+LlxVViH0V4gijytzzAEB8etaws0s7iaZO6orMENJZFNnp.042CeSYcVo3BPKGInkEIzCzq1Dlfexhp5L0Vllfub1RzzATgfDaaGnJhlBTe.2r1KRBSNsFXOO03eoxx2ANr9l8e2q6gm6HbDCdrEqcYnUoaNhcFvIJBcg8bItYlV2rOMIodva9KOX3oaN.59wP6aEXtsG4T7Y4xd5AVa5L.d+2CDWJArq7iIpO3VY70QTmvLTM520Gi.f.+6iSh49n6WJwngRwaoKg56sc2mvObEjHgqrXjkDYuVsxvt.CJewosRi9wx9hNyNsTw+.sonWouHiRRQbuJRlOnYzYAOiaLsU5oW70dfJ4VVYB3KbyxNg0Hgxkk0YbBad1QpzJOauW87jsMmAWtcseqnBm8v93wpgO9ASbUYKfSlMH.P9EM+frwkYbZAKVvpMXsVUUjSHSQRSe+sGxv8nemZdG4UZuR7pOEFUoUjcNkH5j.uR+hHJcbdvlGr8cvw4.3NsKAsmltNLboQzB6xWhwN4DAlCHxKKG+YPeCrIZR6S6ETMzBAXUtmdM.zCxYSn2zcgXDkuCzXh1zVuKrPQygOvIt.f6GWQneLYovGrTB4KTw8DtF3DAcIVGuY+vzs5UuE1uUs6fInfOJQ5wCv3IO6gSFD1hle0WesDM8l3O6IIHn9ljd29OjcnuIS47Ee+P7M6J6SptCErC96Tep3v5xINC7iGShqzdjwpA9FLdbfcHWbXDizNFJxHIxKqPRujLeHnBMW1w9T8Cg2O2owkWdFpt1DCQP2ZfqmB4awFjkp28xfvAywkxzAa+n8gSKMWIEMPjlLh5+h+5kTC9ZUVQDPdy96sYAkp+VClGTawD+aQ3bFyrrFmYlU0Wqu0d9qJxDlTVyWpo8S8Xz2w8uOVoLWINHnZmY5mYNdHTd8JPYCLtwiRZ8eONJDDcXCREDRTbPc5hhK8W0FANML5nyNFshmlq7Rvqh3HwCziT5WlN6NgOu0fWgibV.UMYxkCkwJSomR2rj6Z2u4y1VSVf8G2jQ3P3fhhHMBT7eIG40r55R0fyWm5VbBL0GtBckDKt6YCz.uzk5GhTP5TNFIDP+TpQswt6KjUm.xxEfE86IGZixgNEP57NGo9VmG62D6rQ49bKYe4Voil1Difvl18YoQZv+exMmX1DasHQ+9AqMSG.swxFTFsI3JNmJQsLraAktketq7UAU2+YB0AlyYMAMq5H4RsjGLgT022Jz+8EPr+7aNT.4yAyeerss1up.pM7exuzpxbx9zBknf+e7OUQQPVz4CnfprgBbixyqB+lnlBcqKCWRVqV7L31sJU08z0DEPv7M70mS3yy85hsvan8OoA4in6ZRI.mFPHz33MQSKv6qjT2qoa2hWzjz9uNUQtN32GjkwNp3or81Ap76PQzdaQnVfr4di7cnKLC53E1P0whNX2TLZdnO.Q4CuwzoR32WrUehV4yeSb69xhAsSad0rCZpKSpbSylnrx8TmT8cdObEhu4lJDa35UQmao8Ui6deV6LN+KLQO1tuurFX0VMazHYqfXaqPH7WiJkWPhuG4f4b3BMow8t0LAHfBvE4QwEH1Nhol1GS1AW3r37ioYRYdo7xKe0a4b.UIqeKIXGm+rouIxmaLEwjFx2FS4dwki55Thzmfd+kcoF0r2XD538ooc2bgnG1g8XxXP8TH1pIW+cHUzEtq1Xv53+FcYasXJXw2oabXea8qqf7SXwTLYU18CDfIdnj+u3OWJlEAEj2pXhCn.vcaZ1TIR.mEQ.Hk194OT0EqlHaWkNAfkyxEyqKJ5KYMdAmDOnLyy1obT50b.cqNRsGexnQ35RaQq74ZdD.X5BfPSlwgT.sWqcxINwWr.Kv8o9hqeoo.KIXRDxHyc+1HyUSLJIU6s3puSMfr9u7YUXtA1FvTZYFCLtKLSO.Qk04IIwuRpoCDp9HVwv0aj.Zq60L9mTPFaxjrvvIndWVbT7HobDJ0HFj+1dXLESJyapH.C3qUmoDIeZDGBjeqc5WUnEKX45vppaJVj+Cdv.ywXT0A89A+YHlOCWALpPl9hRiIBXmU3ku1neF7UHDDJDB86OrOf5dBwp08HpAuDjXKS2axWhR3IYub8k2+qFvxCKOvtRTwu848eSnET0j1dFdf0vXeA4Sbt.cBhRSiqcBNsjeOfRVDMAkIPjXPDpVe0Fij35BuZh5QgpFWxc0DYJYOTV1czBDeG+rKKBTffP35pEU7iOd0E7fXH2V3jqnAXHipD+w52sPILvkBP+N.yFal25Rgw45CsjZyXBiMxOGTLqkt84EuYlYlnroet4k+kpKQqBJxl5KuGKp9ADNFVkeFTbg.T34eUzrehCiY0.i+C6T0K7umSqNScnsDAUrjNVBOCM903XommMLYFYuVVY0f.tFXOAa+i7SIJETZnDJK11NzjUxi57IIvmZgGYQjTKu0Hxn1TTbv4n9RKQdimnqso3vgiPTXJWYcLl+EMX7fgjwaT2J5SVYDHYati.jFgcZARuRlO8rXT.zQx3Pww+wHA.Oi9I7pg160NB82vkMGdc8.jYXT.318ZwYxvAY.PIKB8jHFc0yNx6+g+.lfTI0quEGWn4zUs5Wnznc13D1NJ4bMbbCWZmYwVid2wwCMZHNHimXkNlvseX5HT1dydSfYF6mpELnB2FosOciXFlSNIvFAmij1Vh0AVrBV111F.+owuAoUGx6MQI+hL+INAkW61oKhFBbFzrXDN8UxocV0GiAF1ULyOxdPrbOuzluwceMsz8C87BA3dhdWu5m8703kKG37H8lngvVy5jB5kP1jdqyJ6QRD1vmUcdi0gHZ3e3J4HDS1C9ofsKWw8C7FHAVLWDevCgdfCkRuNWR45Y0l6n4Hr+kks4j9IRmKaYsFtsr6jQOaO9zciEUFF358Mi0TRikHyyDt7EmyhNXjOsU1HjW62X+iZysz1fKiMB2V+ABdo.KEfxOplBBEU3qeNHkWhAydRTWzS4XMojsNVHFfzyVGp3r9rKPVinBJ7SKGGRUauqbmoOl1sxOdZ25TIeFdMoeWqs6YGNMlpL2HyQKhIHhJcLChCrSliMrK2QLKyX7zBBgJNZeJ6YgRZ+Av5wrhSKNBbGyAzadXV6ORnqKE4coKyKTVQPPM3pS5MmqwTweiJzcpoMYSdPyWdPjJV8hph85VZ3UUjIgBzNnYLH31PpWFUgXTBc.pRX..fw2ZQAH5SYsk9Lp8Bj6VJJWO7JLvOAbj3xiW22SOz2UWJtkw.ezuvYlOZqMl.Sz7r2fA9zDGyj95swPAqcboNwlNHK+8ENKvwtlZc8nuTnFaPGZezrsRdLiErbN9RnnLqkEPmT0gfeR+d+o1wsbjIW+jz0rJ54VmbGwDiJo3O7ExZvI60KmPCkI7Ayu.RxNd.IrqWfonFDiNWgafA2So6RkzhKCbahMaqB186dfEFNilVS.XUniTHvfC.YEKtlJPz2y5QWQxONeR+Fax1028ukjmHjqgvmYFTiGjEyoIaWj4SdMQGCF76nW8CByBI94CRhT5nKnb4OyeNgaMgliPjvf0PexMegG0M7PWkzT6aVTu0.eGvRshdS7Vlagh7DQ9QrfIe202Qe5pbwBfZlIgBq8VQ6eyY7oD7DTxG.Pph1bjhzblM1Um8ZPhp2meb1ifCkadw7DkhO.qIkI1HiQLKWP7LSkw1ex6hzox.CYB3PjCKyZscn5sEGQka0xEJbkpisPelBiqOrMF51W2SxObB3bR9aCR8VkeP7yx7+CXFLueDcqALtdvVC3lqjr3uWB4ntX9T1SD5hRs5c58+a4qLvmhuIzRU.A0kvX7SoyytAD+RZ3H3u+wcWBGsgz+ZB1A8KALDW2TJnlKYRVUCG.MzByli9lY1Fn46SgeFQAJ6JuQWj0fblANJT+Gl7S4cyg7EE5KvGSTv4Uaa2wo+Z2rAv5N7iC.dlblV8OoFaxJzpETHFuD7xFKXC+cVs4WCK7ia.01wgw9npzOyxORfX8HqeQnRZC3VNPY40zjQoQ.YoUNMy0tbObp6LJTLRW09rlClHXtiVjCKFk8HTtNtFPT9B1ZC7gR3lMsjF9jxJ7dHgTEUkYhRRsh+G.H+Ot6Ecc3oP4rpJJnxEzxI3nIekLUa.JyrpjvL8SUPqWppnc31UplVRmETAnfK9+TFqrMmTsG+WRKjG8wHqvQkFzT30lPA1bdP1Q+cqYamNEI.+y77T.UYV8FHP6x.1B43LX5O55.mn5V9cLBTzaKay7j1wACP39DrElVx80T3h.3pOnBxZrXkdkN9uXtoL.pTWoqiwD9Dhk3MlblKJuNyERG15s.KCxyi6XZptrlmN8YVllTiVt0tYt1q19tjzAvkbJop+F.AJpdDNQy4imI3Y2rVQiGvApmaY22UugJstAmk9EvxabCo+R5Et9XrRk3yt17LgeLu9zfKaXmTkPav23C2u5mJ6q8176EVfRLiEqGqT4euBK3P+HmifCJmUk9ASoxM1tjSzMZhcDMwqDY0SywTJXRhy9ftk.WYNGeatg68F6slGu3osQv9fi301aH2jFuLpNK2mzHQS8zAUSk+0toaDZI1TFaOXZpfdXbnVs0Nyng2KvwQ09BLvZwIlHJWx0aR5J8bc9Ken9oHL8W00ldg.qMRK4H.0sMF608fC2CkxepQWua+pXj8bwKmBYPWDVR6hcof1Dyh1EHnDS9I6v+3a2pEOeShz94T4IPkPFh0MAtLUO0iwuwC79gkW6dIWSXJYRlOBfgW3+VFVfYHwqER3mQk9bl7.4j52C3hnPbX8Tcxei+IYJhvHcVMWpYyO4MmlZYR87uEKbdZkVDq9ijVE2V5ay9WtmoMEo2pGLy2a2pIuXPm.hKIrZK151+d3ZrexZVe4THp00+Y2qelQ0pHYLl8v4QAvvqrNZ7Ydo8399UXR9RgA89UjvC7Jj3N9sCkLewnT.3FSsPihmFVaW6A356.U28wFVfK7razAZ4n3pMVOD3vwrLUW3N8MfQEN3KcnU2kCP2x8YncYi+mOBvdDy1xW4lNEldgbdVSDdYcfnWR6cHU1gobcmcF0jFf3m4dKzZhS2UNXcOC1EpFI+tVl5rwFQ1Ejju+Z3JbCcgGqJk16hG7ggeHlrSNuyeKYrXO6pq5lx+Kl04S4EEQ5mG9VljLkOSboPj75CGfFuPcG7o.59TsRKOqdy6NJmDJQpHon2fYKE8Iy+vSPF2FM121RgaMjdnF0H0VQ8eIsuP00GHz9EkdG9Hpa420ut5thd8TVqC3fyZFsijfRFgADiCQ8cwoP0WfIRFjyh3Ufbt646167tGY5w4vOzqzaxaSe.8y1FW3gBa1kIdd6rAeIVzYPCwJrSDyxnzEt+ibk+8C1IJZeIRyjwxv3G8YaKEQzah2XSd671td20IKFjlm1fPIRfBYMWh5fBijrFPl4GrAe9MoG7kFIovO9xvDL4E.EcKaSw0HRqyyLBScn62vqWOfxkz8ICxLI612adwme9+uVSiEKs2psEqgMUYySNQN1MG+KhAAePbNJQaPUrN8vERBVcsj154FtmSb.XFQWblzXrlX+THc4iVqUakrkFn7pQOPldPLRSyX2Rk6ozYtR8J0f8DKptjx4yQqrgfWVa6knv5tvm+km8D4ANhkYp1tZPs6kuy5uHasQIwLBlZZaHmZ.F4IwMi1HINnl.r9JjJ6cyUOizFHm7h3VVZcMaUxen5r1TdxPKuT4hYV0GwTA.7TAeEGzfqThtUNoaDVq4ylPU5HKkwXxsiHjzfMsq5yAYHUjnuZ7omoyUoeBRSpFrDuqIzldAOuZgUHGWc2xKvwmOmrp1DaowYEk84qGjq39TxivXcJJcSe23fKjTxX4LMp.ilaNBzPkI0NBmrsgIH1iL8N08Yi1r3ztcs0vQfI4hYrubKzp3KOwljZXnTtzIrVCh0L+g9dnEj+n4xFwKjNWJrEcMoCekPrC3KIy0qgreQLfFfYL2sldFb.r2dKP+cgfh+frobeXD.szGQF7rmcnVm5f+gFlYyTEOU+E4Kj+Siq5f.jSNm0CEAWgBcpG6u4RvHqpRYhU5jaZ0FxDwdRG1sB.Z9VC6+S4M5RpSMC+BTtykiWRN6GG3E8wViLN71t7sMg.PnNi+wiEYWYifHgaEfDXVU9iUvWa.VVBQT+ND2sY6VAZ5dOZDEfLRE234RfHcLwv87+YmTM52tsuT81Q+E15BNzjrF4ztpEyFSMFTXhw3VpACYlpBfVST1h.OCA4pxrCT3h460NNuGM7K563tJKTKVdJDgr8CftS+4OayzMYwhFK19.8sDn+TDgayVXjpS1+lBA5p27D2KNnvuwPUh213UmhfrKclq5vLGhK4vjzLW+6K3coIsuStRjaSy5vsDq3D4bPKVaBm+QQMiaqDkOUsC+GDpVgi1Uv8NEJlJ1BQGdWQApEG9lTAoR1OQwt1wPKWnKLOfiRsw6mW40X+TRvIwZra70fozLcll0x+Z9a4VUUPRaCRXUxvj7U.lLMQyODc2XgTdw4nOC6i0KAj1dg+KY6jtOnvJraxayTv3vx+s.SIXIYNATijrmNSCzEl9a+lMwJzsdgBX+s.8wwNkw.ZaPYkCiErRwhl9L6uhx1vB5QHp5q3PFXy5pfgkOuSwsWH5sCzfRcp8ZDVXzTgC0+fq8oYoONbTdSyzquOCNk2giLfWR9AyE6DnLaZowAlqoXnJ74usN9JtNZsvMKSj+QOX9R5dOjEGqfqaGovrlt1lIqb7yDtwvEwViuH0EEPXbfBX0q04rpzAOyHkfiGS.T9BvIBJcsltFf5A3yXaGnQDJYsqWG1bqRVcTtUbK2JmYPCCvLMKPkp4LKnyiMTExa.E+Zdj2WKk5KijSvFvQV7dA33eLJOo5NYeFUkJ3aFT0Px0EMMjlYWqjWmODRkcu6Kd4G11.tI2AGhU6kLzCVPPhVW0Jcnxuhf7vvwdrUx.1XiiX2QXnG8ct01Cxn2BRJOH3.IeSXvul.+nTlJtpGV5GZKZF8FU6jRt.QwpDCQLGGW414eZ.6GzVK6xXNisSszjYg+b9.odFHyH.E3XL.7AwUj7ONcZ+zKirab1WRisSSv1Zd9bGrj7KLoz0v+OLI4J+qrmlwztQpYxARQHcbjoRe9Av7sakUA1g0Tc5aICOXDYYnaK2qia6oqtl3pCmLWpIqALzLuDGxK4ef62f7w9y5Uh0Rfi6Gkt+1fgRLn9XCtKrIHe3Ts5zGV.lbir9RQKCN7qtpTDLFcJhJSgiznpKbf.IkNq2z9SCPcnY1DE9+J7bqrFgAmkKm7VTqN41hAH1oLjlz9zh55aKmCf3fhjdvhxBZtKvFY7GwTV4lgGD+Skgk.OqaZIzQ0yTpaVox70H1svEe94ETckD2yudzV3QO98tK03EErPYPYjtBZiflLr0vAIFVPH61YHiob+LNhNSBZDlSo0v3RusHRay3Q+HDne3DA8q2uUkzz7Ojp6dYQZVEu6r.xpEdAd5nB41xLeyJAceApzZMpYnReBzufptQBZXhLVdT6CO8+D65P2+u3mbHkCpOZwjnLb0fKhfL1oSn+XVfIP.ydFseYIirnFKFKEcPaXs5YF9+LOHh1ii328I+KEWbvdYFwb3Poq2wqkoYcCkj3dFh0n.fr9sqxgxxfOvFDa5CwaeiFYiXil+Ge7vCjlf0OPUgYpuXZ46tU4IGACiOk2P+NvmDSbh5OA+sYuDPkTmrDxpBCwU0WnuIFXztBxn2VobSA3P1ppW4dQN2jOzQFfbER8tGwpOYRZ.kQvbjqOj4XB0iEkJaKSaXRkTyNpMWJ9GLR5gKs+Dl8za2Qpcg0bLDyOAIMC66EAf.oxH7pi6GtQNQgo0z8q8aYL5QiVVf9Tq1DaevteTmTbV0UiAdEw7tTRtmIOBiS24RU3i6VlVJOv3.G.2NQHh0q5znraAe7S8f3HIhG8xwywVae.pPNm1K07uZRYg1uen0QzbcWCcYv7jTF30mSOnKYvF66L6wiUi54zSqYN9VuMW4UDVGSfCJ3eEutXADY6oIGtDvTXrbRHFhjEza85wpFfWc2jXdrNsMZmPoanKjKDGAbXAINza.HQOI6lxO1DTvvlqabgA0FeuWIMeZIJ9RKNf6.JMTy1v5vdvHk6EOLcp4NcU78P7XUdywwqFSWwR7AsEGSvVaEF3883zpIG.imhzBn2nuMJxkIPciG1yWygo5AGfK0PiFaC7YA2YzFzMfX8emgKIb0GpSuqRek8SfnoRI6emd5aIL0VGeHdqAI8q7HKsPSJc5Gl4hhoXMxdKU0buxGyC79j8GKBM6jnWRlUEq3z3QIscq9RzRwMgT5+369BNLbP3FF1fyC.5imfpVh5S2zvDFHluNSjcKTVBmLnyiD31tSqHMg.Fh6A68FEkopEkcnlhP+oSXFf.0T1kK7po3qUeQVNr+hlF1NYuuOqsLqmbSXdnRgmf0XGsVydOc6ur1cqB+kuYyaJaP6nZ.Tasw0XySjofWb2JRFoJVcuBzue9Ju+Po7ygcAch.9.RNSgeBrMlJCRH.j.l2Sox5xlYZSKUZhXDGojAGDOX9OO+XLsFizBPCQ0RdgX9nCq39gvYfi8WbqHK1XoXT7+5X8zH0+Z1jRyuMxmlyKKh.F889K0WTlVIZygufNu3cDOxaG2sRJrvrtPgSTtnTdwFe.EFBKcqOfY3L2rcO3.dl4HQk2qRGeBiFLvgOiMffAYohRovgh41JafH57vkD.DDxcVZmczuB3xkW7B5+r5uR9jqyJqHOaLehHqjBY0q3mdiT9RXkCYsxlFNgTAGWhQ9WcA.bgh6iarkII9oO8kXG9+NiWiN0Xe68fiFVRg1LFK7YYw7Fs39F4Ro2Yly6+zuPFCHrnIJFMbe5sq4KqOqBZqPJLKKWfd9KTJOd+dUb+qEiqU6+DPq4U.q5kqoEHjVi1vb3gG+4fwItVta6sjxMw.jBNLdYpHY90YjNp7ODbp2Z4Gkjpv24rI0uWjAh15rlm3j4wP3aytYDSGa29SJUV.tvcnrHRQQXbvqqxT8uZ2XPW4IdEu6OR6FA.JMa1Gut.+J3WKO+voqbIT1t.H.6lcFSygzEDBsn+LVvZjf5OJLRU4nd18PJxFW904ZhQnljaeueCl88LBDaVtgJR3O0+vAwz3iegkXZcd1ab+3WA5TXunl+.d88TWNhkJj0dqlaYnYid5OruJZpHMLttm5AWH26iVHfdj3sHzDC14GIgvDy+DYJMTLmvgVFWKPRmoQ25ZQTVMGyL0G0u+FjWjZsM4DJmgV+3yASMN86nT2vITo5WdIMAhgh3otFAb.5V650HfGY41WN9I6igxVyVkrRrTpssUKdcO5tSUcO1g2IPXLgNN9gRokob.DgwvtIVhZGorOb0XMBgxKGQBXFyFA7UY4d2XTxnU2LdX7+L8n7Yc5LZAAronY1jSHiwVJGWHacQ6dDDu84+mu+E7J4ylepDqo.ywY618xOS8Cu4mL2OpZFNZV8+OEHOJlUeCHn1hneeL5MwpmzUWWkm+EFY7ffxJHqMyHOsQwbdZ65KBpFm6AMPHfr+SHG2HKKLdLetYEg0TRZAQrSyqrUa7QUWe5mjHlQKQJejkihTE490uG8CRExlum9cnFmBGBVeSbdsWwZWnJ0A2LIWgYlh3rdk.QXYVxkA4VueGcyJSVJW6XIpTzvZZR52.w4GIXA0x6U5REi+B7kiIi0JYNNCOU6m2VLxM3cLs9.0RWTTpSLc9gJ5mpL0jX9AwPAc3C+wfzSqB63fewqqsFWifEu0OoDT9WIRj2TqAELEqxSnyPOOtDSpfAewLsXsGspyf.0L.ND32UtKWSBMbmx.kQQb6Dk1edUtGXaXM+9Uc.AMlcu4dvRedJr1yol+s+nA.8MjbFJopJladnS4TncLHOwQA2AokBrmqn0P3Lt0ih1X6xHkhxtGWUycGlX1SDVCqL8TVZT7SugXd9iVnHs2H4YRY25++sjXL1lgH9pmkYFooCqrdHVOx2TVBBK1HsSmtSpFcggz+DFQLnrSQUuvR26g4BKj57Ftq18Ye3vR3iQIsvTDKmDzsGSiI5r06Ahrv6cB6R3B7l1enOIrY+7g4gSiY07SY6DZ92jSWBPyssL9RXUJxO0UtidltvZP3m5Jc8kbY6vHKdnMS1ffJN8VwdKhgWFsjz1ups022aSSnCSpC.2CModFdiRD20vSjr+UmnkU1rMcjbAWtC+josGcOnJRa7Md3o32Qt0YMxOSKQet9eCDR2RWaj4A6EDSN43lAkSsNp50wx..RECYx+GwuNzSEsRBhwXcJGiEeyGvPclJiq2uNhGrDsoLa72s5NOQxo2ApjE01BhEnpC5t6nRQSq0nl12xrC0r3rJ4ZMcWRxq0mgn189+.OYkm7GmKFp+cGoO6W9pBEzOhYCP6R20HYXMeK.NXHzpXNlVoHoR4bnoBWdbTFdLU7j9bmq6.e+xKqGKBTbj6Fi6a+eIyGJIAgZZLPhQdORud3.mDlc7hXR47PY2xtu4yN75ajL0UEdm8TMBseuwa.p6UvWZ2VtfKezwOTnWveTN8rMR.nuTA63d+mKiKCgoxEYEHaFI2Ce3xWp70SKw9OuYLnQqdv8kZSZe14u6.2+Km7vCM208s669IE8uX5bcGW3agMrVFPIGfAY9oS2qpA+f0t1UJPcRvZF22.LXE5gxfKoO4R485KA7f2qIsgnRqWI5EOa3O7tG3gl722tQxIAXrmpkW210xWtdO+rzyuJ07wsh9AHRzKBUHgppvceeHNvcst9myhsfwAv05gJ3YfPokiqXY82aOBH84NQDfECgBi2k+eUx+uQ0P3FcnkVF3bhAIxK8rha76rAFZ1z6nRPNz7eBm3O86RWPG27zlHJTyY5wgNgsJqqpHPQ.FhENwGe1dPCBU5hCwl.fDXgbfmlAw4iqbhWi9bMPeUqB8.+mg6X.AAt6jQZVllwmUtWhfBw43O+DWl7kwnbwdKJZq7KRCKbAhm4sUL8TduQ.rDDCOEibZNYRYbSmH5iC1Zo+mfn7.wtMR6y4vqQZ2S0iRQ97Vnr6g.JSenVQ1tSlPzjsmeeDDoPohFKA5t1UqrJZhG+Mrr1GlVqlvyjaE2wk1sPHj.k3EEjV94s7mBJY4cK+es3.xlCw3CFrVBldd1N+Vkq3Ya4z0o8G3kLDIhp+wa4P+OJaVfVY0GKztase89rSkGIF5sOW6jaZozfGXL4CPmFHqhVKl8Uq6pDRJie69HCya31y+6kUjWvKVB+ZKU8XQs4RDeoMli6R4C+XnrSPB9ypyqovv+3kkkVDpcKZgwkVUjwAaCAMkDyW9.OcMICtEkM5PtbJwsycCD0J9ukgrdNq532VgGNxuBrvc3nyJOfnigrMBNIMNJaFWah+0YqbZjWBWRokRryMkU4Y0gD2qT8qlnYvmfohYDBdvN+K16ovTyHSKQ00zvuFfrRlQH.ZOm9mDanhQ2XXeeXD1jnZQs86YADQgOH7QC6Hg5gdktUZ7xkE6iHFv1ba5gLjBcbrhfWAFKAZHAUWSl7ZwYmMBPK11phlyuX1YAt0SPfE1n5VWN6TF.MO1RWZsnYWbEpuFKM9XMf0RK3UtL9zqLTXUNOzgLKWTgKXSKwEmjtIwbrNMR3zRy7fZUyG2ikbxd0ljWhahs6Sa7UXUeU0D4koCdpfk18m+ZjWM2GbYXh2N6f7Nbu0.CyHrnkt0cdsC7CyXUv3pGJV3s5pfNpFsI+1bG3XPsfkFKOrTgeFIKHrKYMHY20DLgQoElqW9WT0xjbrvkrKLMe+IQqf7vLbvOCfSaSlUirAMGBcN9nvYcvJjOVRcOzgARNt5vzqcTPuD+z15LI4rTkWuegWBxL17mcYY+E9.NWp+dUfXSCQ5Tk5tG6YDeanF8Fev5a4vPkxDxTiiY0XC230IvS6.g4OsF7jUDN9EVlT394.Yt..+pwr.imkrEcrvUdieszFXdbbRK8wq3DWu+oJ5OqA7GlS5r0M8mxMiVuo+nleq5o4PBNaS6BVikdibvuebe4iQ8f1BwF+8Pd2F7MY5yy6evA0rut.qsCavp8kj0Ru3DhaLKY+LAQvhQF663ofC5osVhScr6ZvVUukZpQS48ViB6dz49QmXzk788uD.AtSa4j9kGRXLr75eAQYO4GxUiu3L0XV4U7VbTUUXNe+WjslBUCttl7mlA7lk1ozLhpcFnlxegPlgPi8JCUKA9ySQcEoL9Qrh7QWBKHIIT2LP55DYsmM8JGeTzJGYzDx6PiI7D86ZMJ830CQurzZ+B8qeW+++R3vX02GFTHWYJpV.a0ZGmbpPEZTELf1z8YCHOD69.NHBHHBtPTfeuNQMm6pn8o9lyz9t4Q0n6EezZei71LfgFLI99pSlPsLyfGO2jTkveJQA.i3RuDX.u007tKCAMeYsk6kBSHBinPidVFmjC9THD..+FSBVpbk+sgmV.ANVaeV47TcTyEc9VqH4Dr6zG1CRiyVgmPNXdDiBipVRD2Z8GmLYcXHnE39168.fe22RPQ6ajHyM0lSSWc+.0FbEApDh9GwFF1C+TpbrwUuGxWI8J.GT71KrdgQKyNpoaBKdhxHCIjorzheAa1ENAzmhC86jYhTMoxSRdGHqw61tqvOYRGmanM8fckVBkfyq8ZpIsfuFnQs64+8Kyk385nCkcqnz.UekAmrtKLSP8leKfekHCYRgJ67r3T5pt4Me.CLnlPYTYaNn0SmmWt7QLqkDncnrEg1iWUkXvbsuxbDeLrpLwvh92EPsk49z+wtLvXKDG1bpgPbTpmHneWNw.Xp55KOtxdueY50bslCxFUgHyEEsuFPBrzD8VJ66cCFjMRJ37o1kmjWKisKIMCb4IFONr+VEkGEp+Wg2a87pILYiIKIfh41dpFcbRqLtLk5ydop6431fjYtJ0qQW5Ikz0r8YRGvxDSYLbiTp3Opd.mC4xtSLxCsyKXDhpb4jM3WTRwpWr+X+3iScKs1sqUfyV43VuvAJtARNwzkfAlz+MgcxydCD6a1UPdOU0HRLaJkQduMol3FP50f+PvNMJdcAi+eqBQLbFHtj0UPbDbnFDEnZCNvqLq1JsfHk79fsqlxtrC.HOmkgxED2GFQBoZJdu7hu0vb0fcxxPdkj408HiP0z1v0dr3C+VIcvu1jXC32usI2ECLbwmoi7fvSj32CXwQoSMakzHbX6kSZwgOwa8M+Ire4MYd0FnMhIj0qNgpDHM+NB9BnojutAVuyYv1ivnOBrC2Tp1hM9tIldaFw0LPGLs.KjsaJ9Fyn9J60Go7zi1E97TWR2NMwawAI31Fh8P6lVa12oTCdAqKv.4H8rnjVIdshtDnBynYmjZ4mXO7zf5liHQsEv0J4YXCLILdazcbVGtpRsBrWvquYlb2JURdpPwIRrh.gu5Q8nfg32kgB3WV3enjzgjMjR1AEEpzy+wdqjMvItxGUdnRYDOggYAK2HnvTtgcWJ8Q0osvEZhxhgymyk00rQ3uPfIOIcUvSlRzjoh5LDAVQuxW8tAewONZXoljUA7jf0fvh.WpUrbMWXXbT4gMlerkP4vPgz8NLA6sQfhsIkwcJFQl99A3WunSt648wcfjDE+71X1g9XOJ4891+8KCKdoVUhBDayiYMLXiHa2SwTTiQmGHefseYwJ1guFhvTTlwEAYVRqkGzg4K+eFHDLwx+Y4ekdwHtOkOXRZw81AfoT4QXPPGbFLCKtNMr8.Gkt7.A.M7482.uy4sxerPk0di9h5BEwmsT0uT26Kfh05FqVO45+HPw4PoawLdtoOe5J3pX8bBTp8hCA2oI5VNHMywZX5HfC8+kIhwzOIJP1g753S3Gko0jTUQINZA26qwsFO7uNom8hwMF6oQVZ9rh2n7BVuaO1dciT33f+OVJy3UZrpw2idThWca6rkjingEkCZGosYHZvEoEV2RjFv4IS4eBFli2T9jwXOxAyLIxv3ZXsGKv4lOXczkZSPfRo3nNj.w4LJKfluqscFfEAKOOuCo69b1EDOaulT6yVFbiZT4u7zVWx885Ef2Yy0aRCKWQQv+9hmu2clT+r5OblfdJBORbMGWwzQmd3rcjuPM+8hnyjB6XCzxh3HF1x7Ct3NthIQVjljbmdKIhyhAyA5tPk6SWS4ssRn0+YVmAymxdmF8jH30uqUsGFVho+3LlLdobRyvXuhw6T6XVVWY8msaYIiBdpHAocUcMdl2npLyQLziS+K1k850g2K0iQiIHkvCiQIQd2Ghqhrv83XcbXoUHSImu8+5vkYvbEpnWRL3jVTZ.LeDPnIXGbE5Cfv4DeAF0vrnO2SEaqKPTxINV+RMWS3XTd9awf7J0XmyfJB2MzE0ViFuSa9CGkedn8gL2eVQqU9IWvqjzlsrxqlZKUTCXp62+epGOkfHDfzSAdkOqY1AGX0bZJe8Uwn8XIYHjrr1BbLXzHU2zA8.Ab5EVnQbaBfnVVW4EiQMFnD4.+H0MJM.fqzon+hO.UNSGPPExxfy3WacDCCqd8gTcGBlATqjd96P7y4JqIp3TqyB4lIx9+eMXCPy2hgwKES30P2j2Qe1vQ3JK+GrHXXyqHY4eBjdDCgGL2xIxAHI.ri9gEiE0AHoSVOnpPr8+sc8EGqAqcch0ZoySinRBmAepRJfFzB1v2kq4tcldSwxrRvAj8Dc6d6wNP29G7gdoeAMvyddIvmSi2p199.5Edekq.KlPX5F2H6RjZE6eaOzY1yDbcpc9At0ovBW8DC18onvaxjf0sOgtZFowIz2bRvtGQRhAhpp7nGeJCMvph+9.wuRXeocvr7kNVoou3COpMaJsVEbrNYeV.CzFyg20EJ0RQumq0rCQRJg3WMTp2EY8+fDlj7Bn+LWXMxGukZDb7+HmcaH1BBat1htWdFiUn+QfTBWnqkKnhcEIRC.Fx5CovM+eYz47Jp3LJtGSFQPZCjd88kxLkpU1MxVG64cGAE+5Nv2RzwiohrRtT9APprDR+.y+abWhH+JAgv8a92792tgCOBKVSMYmXcb2G8D+9ZOT+kN0sFFX13Bfb037VVfiJIk0OAU6OEE6.iY6cZerua0AjPkBI5U1ovwGEjI9Y1ME3AeM07yQ0YkUZ5Fc9E5HB1ae55YjWj+Spp.Lj5NXPjE0ItEpeAtaeocX+SVEoZEErB5kZ2LgLuT65PFGIKUQwxYfYEk3P55qCOvPxG2pRJecDJGFZk71sXLSzNyQMEVhI+GwQFboRSeDuJdE7DQlSGEv4BBx1OAQwaCjaXSIATW0pOi9G+Ibv2yHlLuToxy1PoKl80Y99RJIwZqM2KTnXl4P.4cLB4bVlQj5equZfTmdEsKHfaFX+hQjPiZ6mKEnvFhRnMacXWhye1uU.0gfNpA0YUr6STG6d05wsFoQgs6HMWnHICEhLpq3zKNdGZwYETPCu4F28ykrvxMJwrLr1k5NHC524zEHGCGG0gnY4D4XSBl3DQnYa47TauAfABsXn4nQLyN.4U9ZwH+yzBHkqk0WbIK8158bsSqlBJjCAoH8dacOISYCJy0w6mCbzD.HjjgZZOx9AatzDv6lukoqEPGxBjN2ExrC.KMoxyWj8+PlRwmKARCZk0Q1D3X+5MyPP5UTpEyn9B2G6R3E9Zq2CzMUubIujiI7XRZ2Z8oTPrEZCGCPWb19ge21ioZpaRDnmeVukHtA0X2ylNDmkVlFf0PiAptiEjJDe3PW4qf2A.XAdCEGP.+d9XZFs2+Kw.hnLsR0lgN8G6l5jrhN1zS09lJHhgrKNnOtmDbWSYde.lzHpNH9+7LveEy2TpghSIN9xhxbPJc4uXMud87QU4CwHm0I++Bp94ULinlP30vqvdmH7U5aiOUdmUFqZounSqbg21UIoUkcfiSun8ggKvspCGRgn2p.APjCIAecCCv3ri8pmeynbklHGFBWyXkkuMIXTVvadnNZXa.ROl.7OiZHVlZ3mXdBo3axWV7fzZntwONSRxDrjNpTEh8k0QjcoKm1Z85nM3jnKGK4EPV7a6CLoi1eRvmv4OqMXzYgITkKV3IQ4ZMPo4nojVt7uL1Le4MbT3nPOlTYoz6o5mgZiSUDXlkCH49YKY3JfjRS9bZQSTAeckL.JITi1xYnS5yhd5tzHubY4oTnAcRXdDiQfKxCZvN48toobJRSYDz8mvUotS0um+.1GcynoXg.LrRPRCxIYgcmcVsShFoCChicCTteWknMaW4EMu5ZyVSadC1Xe47m6fMCS.dPopgjZjaO4faHFJIaUW8AiVj9kKJLkhIUFOw4m+y0YA0LdJY0NaL8kmusKnlVFfZO1UbFZiM3NpEJUs4.t2EmhMcjJ5rmQbIBxpmx1TqkDv1mFKBPdcUXnbpM.AhVCc2csdxnYGbEeciiX88As+w5uxcDEB0RLyMaVQnIdMwcIiutDuEFWQweYvLenqnjbs7PL.05vGk+4RBRcw5ROLtkDT8SHz8nt1kNlTkFQazNmbvhmiTE.1dZbZgCDr18EPRi06YGWEuTClVfIpGUp0Dvj6wQ6qkXUv4i9RBfjw56PaK.TFB5QEbGNCq+EU67cyIy7FFTBVSmh37U504uChmtxywg9V6tnU4pOGH9Li8e3BJ79OFToP6OuFe5aoBjFlO.Ky90RxTfBABUGbopJ.80IUcn4tfhaHZiD56kAE7Ftq96HJDUpWbqswB20nNSTrvCOJpGyB9UhXfw9e1lVMzbJNfIZD71DeVLDmihdeC+teNA21MNz5utaPO6amDxLc8ZLHcPUTQ6HQ4BMh7ZS30UQQlK4hcrbHxN4DH5JLL99J1hHNaOcgvd3BWJWJbe2hv3yK6E+bxxR+PJlYz2Z5JlPzy9SijLVCY9VWvNMRlagl1uMCrdzLuJNl+dQXSobVX5.0EYbpkUEuUUeUT4BVK5b1Cb3pLGEd+wnduV4un+FP+cfCHedZSbMk4GekglsecCXFJJBEwNdVu95cbdTyoMY+o+bPwPiYW8Rnsgr3fKZ2OHuiUas.SwBCHCZiFZMobzIg0ij.MLPSml0wDRQ9VjKNg7ATEN+fNBn3lbAD6zilHV9WrJLz4s0+EZayPEeaz.IOHtLJcZdCog+zL8L5xBiTan1qsWbngD0l1vifxqAhdjBkFa.7IntNuUmMIwExCSom154OHYtjh7QjG6BiK+iEpZHLw8uWOQJpTyUM2lHbRK0U+z5aNH18w.63YRMAVtNYpg7vSbsCaPPRnWwlsMwRMMrD6.0YtCbnDnUiiZ8eCF6vGf789h.JOvket7miP1xpPL21CqSZmJZKzpEg56fizoMY0BL5vx.hKQxFAe3ChbT2EKgqCjofgQILRyFE50lCpRo.MB6S0a4eGxefC.uw87yEdXhwxGDjvKsuDSfAeofSlhOnM8Uu7a9nNfefd7c+TwLr9mYif6wfP7Qsv30AwXM70+hrIxfsKH0cTWeC9CwVKD6cpg1Fw.iVGwyFMGPTc26.ONZYpNRrcQ0.fAHAZ7HSMPl3Za3AhPYioG4hCIWHW.+NoI0lmZoiQ2ELoSmxZaw9qX9chWmGl+upuFWWUblORJUz9eZ.G.jpwnzPUmom1pnvycQ5Z1vTQLvzyU1c10fYFG05EoFUZLgtzEINjdjal5gBW0S4x+6FJZeuc04M5fRRfCFiNhl.BAUb.mkU5lEbRQUtnCKDWuUgKgeqdX37AKV+O6th6WiNgJiULiNQ.SK1qMic5AJ7ZweHRt2CWKWuWuM0HwQymz75ZJ8MHA2n+sWogJ08L98HW4P+.PjD6Cspn2aHV95EsLvBXJDtP5NO73vOleq10IlyodAdrsXc9evUwSSDvYoVu1rCi9VbIVd0kxTfpduOrOh2Ex0gbmT652D+NdvCntV73nj5.hkbBRbPmpCwy7bgc5SYWa6xT0bjfr1xiubaxd.LxyRMcCmDCZfgogAY6a158zihBePHQbjGmQkr2RYi3MEJ2DjJQQItJjWw2YVQ0QhFefUA2hpCE4C8st9PadJA+TyXH5SutU62SNdRjVHlMz3AU8xc5LMZukhbXWhUKLN3+UhUyf.ToW83sULO5MgYk..F.1K23l+5wIoQCsfnY6hv5rdj8vQZMidw1mRoMNpyViiRIlIZurdvEkg2e0tVyFhPokfqrrrolZZkgsVpwCTvY2mO1RWMA0RCZpMuMrvPXZOg9KvjnqCnmR31vY18ow8ffweGE3uvalz5rSjhy2qHoD8H37qkTPgY9+WJH81nJz8RaAX97YU4pZbBr+KL+04xqj67rlcM0rzuc5TnahJEqlc1J0gXVafABdseHoP9EfIIgTVDxT0DTJWhb7w7tL2kzBds5Q0G9K4XC+6wHPVb1C9JZx.9D6gNiGeeEbJDKSdihoy+gQ79lpkRdm.9jjTCdz4SBG3GulXBwZIvlEvF4GpTLGubSXNMf3ipfqcWjvaNe6eZTg+swzsjbkWNJe.zVWfcEnyoUSsYTvSTL4.VfokIWHnmmun2q2TpLBtt9Jl65imiMQ25mdp4jg7z1nz+9TvxHyTvoQf5sruBsgYOaD87HTKYPKzEKizZsQf.hver2WWdjArYA50TkL+7DqD7LkTBR92cACPULpsKg9lVKmnxVskNMsK1ZHhjr..ypnv47o1938n5SN4IzuOInB9cOMznqKK9SZLKJ74nYHetG6+z00.DkUDzb5wGACyExyifpeuCM45XsVsHQrDSbIN4aJW7ras8.T8OM2QYOu0yW9PlMOmpwaAVOF1N3FICsvoAPHuP8vw+LuLm1f7DTmkHFraGz7ChJ9TKmPk5BoiMWU60es8TSqzO3Qy4jumriuQ3JddqH3+GgIHkLj7J30dsym1O9uZupQGwgUxJ83DOjfVig1DtTFocrWnfbEoiYTmFCc7OMLNbwSUd7GK4F.o+6UKKeiADbIW7g0mysAICDLEANRC4KU5Wn9ADBlGMJ8.7RlSU3Wf+qZdItJI+ooIZEZs6bwbySQEmrl1MuCvgEmdcFOApY09uu2WckLMVSQDCEqh.xMGz52db+FZ4bx36sdAdHOxhwrikSluPfVWTNCQy6gX7y2j7+gZEXmiVbnrtc.nhsPjE6h8b47R2dnuNm+0uDnGLP40QnJWpAh6CNXkcX+g+FWlMXsej8wNyxBGcjo94jU9V5el8iaLzM46DOVPrEoavJUOahw3+dk.rnN+4fjbfrlkUM8MZcm5KWsffdCQExBQOqseWBHb9ykOUtIHBKAnKEO6vwBE2W2cgs0sLH1LmH7huLGkMmSTVj.n9dtKgGElwZekuElbTX+hNd+SWGBm5wibeRVWBtAEmZzO7yXI+fcl1VBmvy96DJzm5RnMb6LqziOFdupbd6OZyeQMe6JYb+PIf.LcOZOpr0iDQ4CgDn4w+dy9wGen19kGZ9RKDA3Jq4W5n60IfEAJhus9Ec5SW3ph.C3Bxp+fj0aXmmN4PGP6qPHuslkTcxIOn350vI8C0CJ0E4oQqYMOumnLx+Dij0uOkdjeKrWNZgRKHWqFzeJPjB7o0.1nZyUHWcnoZW5C9D3qZm9CMcQ7ykH3Fc4+BuNrogz4uIOgfi71.LJTR4MNRQvfboevAXaYUuIESHBt+h.Xc1F9nV8B2oM7umdEgMd.dFXqPMhEpWYt.mNru+gyW2JaOWWTJ.cO7cKbWi8zyHif2yjE48Ya34njba2qa7KEXHW8VfArH+NVe9xZ0tb0juLv29KtKRvIqmAnMzDISU3EASvGTuNohMsu3muWRjotGd72N1mU+06LDLTRqZ.1cLIhAAi1FFPNZhoIlbqnH2YrvTwpkBCE8xIOQa53mxLd3C9+TEOkNOiRPvg9YKNTjP9uR0nmgbSVA0ZS5uUsBNNeS2THFeAvan.sYlfeXUTEgrGFN.TczloNAoHUy+LGDBklcK8fid7BzqVgln2bNU4MhfN7ck6ZArB+zPPX7ITaOoMpqBQia1k0Yfa4vcFNSYgaBQVaSN7mCb2VcPqAGL5IRSi21FkqF5wEyaXajwbnUpNob5qIOojlIQnIw.vL8dMbFRqkRdx0Ymw87QuDHS1v76G7VPMUlAcDrr.EStah3tmzN6cGjR93LZAKEutbar+vgrgAx8WEy8fvZreq9SR.l1p6.LvA2gM8MA7KAIqb+Abx6rcjA2I5QlQkvP3OUXsro.pLjBv2HNBMXC0YBlmvfufj+LkCYzamhrvv.kqV7oRE.lS.IfOVTwDipykEFiWXpzW+X3.KjLJ6+sbOOA7gKk1gNslx6dKxjwlcJU99924FxKkOoU2yvNqfkCu4IQyz2.kXo3GL6uv1KjdSo6nFKV2Q2DJTp3mgek3y7YWpT4+z08Yc1ISH3ABEhzs1QkPRagDvfnNrl10tORRp5bp4sKFUVWs1DKPpxhisCnBcmZ4Gb0tp5245D4YrmqgsWQJQVsyGyWf0PTO0Lcm4ODNTcAGri89qMCWtvGDyBHQrXaxYEyUZisX784VZjQqAIIa4sQp.ao1dzqPsqGnxOHhxwXFU6swfDSTodzf0V1RS4gf1vIhPbCoONeL2O5svHnxNkAcCUoGbdy3msxyOie2GXoUa.HE6YDYc56t6X9S3VaGwxtn2v6yVgCMAy2zsKkLOwfX173.VhjZnVp6T4udrg5Mo3zLqI56GEDKKwDpyfSNRhUgBm98zHZPkHjQjO4u.31vcevAqZro8g5YO5UNpiu2wu1w8H07iAioNvmCAdjMOlSul1MM1XACQo30CxCg92OQmW0ZFx6n20TgsFcO9pII8o9Txvivb0k61Ad59I0svSktLb9.mneisZKcXebIdIiflUevvIP.g7Dk1nXfvc1O7FshrET9qasY1iq2EtK69kJ1Yt5AiyD79cH8MjbGjMMEiSrULuPkYYc7gjYE6xLOI6fPDskCbyLeRQxflHi4Q8uEBbMUDhG6YZQgcWlhBAN3LsA6yG88rGNQrHGckPcrOGlFXfgDjUmevXgpJPz7KfA+wCwJyx6bqzD.ItFpVwTk.seoQw7vSjXuzAVQxOU336Z4rS8RoVKRV85fhg3cpN2AVKQZh7U.5kkynlEBOmmZja07fBojEkz8o1LJoHVKgEL8WdYRrXQ8AM3MsTHFWdnJoNqkg99ZtCvOSVjYl1Y+P46oGy.6ORwT8.W1GUTbtWQEPSlyHFry0UaAWJfrxmWF2OwBEPOPb0HpnQmLZ42D7VWytvP1Ty4VAcCvUE3L5ERF98St1CL2j.rg32AabdeSHDHPqBgQoiBBqIqfkiI1UnNBnnf2Btaqpo31UP1SG1xFR64nm2kRX9mKNxUEvDHvxqOAvr5LSLTHFermnm2cUDHGwc5U6WNgPF91ZIGowUZu89PM3hkw.ChXEJsPrHujnCIltUEpX6mJ000OkTcBjHHDR53C2gIsMkjhwpU.UwKnMcn0HKGt3yDBuGZPkPDhNBjp.J0IerxiFi2w81uv3MGt161G97fPzj5PsCeYyY9toC+4Rl.hAGsSQaXoHoRdw2.aI2oN1CBx9ZeGtI82GGWYVTxYox4p+1uM+UnIxeuTyX9tiGJ4Uokh7uk9j2+iPkMnAHhXtW3EDrC+8Md09yU0Jd7qhQB0P72YqrJohweR9jjSPnTALGVFXY5v7L4cfCvBmwFXIkXzUhb6k7pjWKSva1GMGz7sFUYDcM0WqqufcG9CzzHFndtmxJ.SAFG3MjynkXuO85jsecMRMdUG7jmC2qZn5+ZTk.qgKKtiTYnqo6tUE4HZTI5+1QapBZErkVpojpdhnKMZbJoWZQRvf6bh5zjYKkS48PVx2QSpp4.cuxx+FQ1oW9tPJUgdMlV0DyYEh4i57UekLjROIOhwgsAvns+kTAvGEGBIHaBeg7hwt9XFXAV4kMx5qUrsWP7nqhCAwlQGUVb7AQeb7P78KXN+RRxG+ieQ3Etw2eTzzcGrojvN48hxmf5lAVSnpCHUUdrnoxjxoXUqZALrY7lq0TW7J36Rn.jZSIM0vWIOeq50A5jt7S0GIuTxCWHlsoFqBwec2YYHkeHWFLr2XzciM5Rvfe9AulL67ZW867OAgq3r6twrL1R6CqJy3ldQKBPeguiM.f6mje4Gu6qG.D9C1X8jT8KWrXC+pj4QIsqA7Qtg++gn.l7+E9oFw8jhVZpjBY.0mYyK+OECU2T3WsBsv2gqQMN6YBZa+OyqVxwoFgYBNF+jaSeBoI2vW.cCJl4SS40gr8gXkG9DSzNSpBcU1GBd+dxPjQ+eHieDiRwOvqvza00L7oBmu.BFQWnKsIsBvi6mbSszTLAKosiLDbzhckrB0VOxU2+67HQr2sX1QvxgrLGx79Fz3LAePEt7eNZR2U4BaK.CAjFxhB5+msu0yaFP3nJV1Z34OOr.h3qzfe8KMtJjCBKte55e0d0iNVTqcGL8vyIkWI7RIottjErSlDLyMFiodbfcH21Dky.oXP5UBLVwIigMjESu9cFBGizn6i97Z74ORJR58Up9BI9MFJdO34rQRyOA24YEyOW+DeonWQQ0XXg51jTAqUF9XE0FW7o3b5kFlVaa+gJbWflIky5Wx.rz.xtibOtTRjANY6qfqCbyawPPBxt96lFlNwPDidvj4Jp2HBWBxqLFLmevo6WRCbvbzHMZIWzo1o39z7VSyapMmsayCMTrc9pIINcSDUwJ3Dy0tHbnbLxAUoylCcpWzLyihs5p2ES2ZCDGUBK7558FWCPFuKOlWEiGw2hvziueAEWcAzYNrJSDbDNQJbY5N28DsbnpvXA9GgSStVZT8FO8juTI70VslMcFEHu3LAuNkX3qssV.zra.4b6rreNR+0itHwl6E.OyRjM6o7zjQJUnQ9Ea9hIorvCAAXOa0fURT6KFdqeYDdMIYlUsexPmGZEn0jy6u9GyxCKTDfu7jXzQ8rf+FCXIoZHEkgyxUs0.xYY64Vvj4dw+D9kddc70qQrD4bhxtG2mTa3eJlI0CfgM5g2bc9UfWfTa+SWjItwxz.08iUodbINTMHfz01qodyCsLPwMq0Tq6qcEMMPtkzly.E27iAy1A1HdleKxYWSbQtyWYKHn1C4LpI71HYny+k4un0bMIXoPEqG4tugsa2zR2cAk4lDpBngosc.eGpEGmw9Cpl+XeHrIIODafB4Sl9a0QFugf1DWReL41twp1X8uQhKS8SC8st5Dx18vnoDAotVZqUABfD3yvRRgJ2wm2QEp3Y0YHFv.jXWLFoM1FiyJ2KyiPwkLQu9ipgpMEB6KDyrBAbguA.U409E5Zoz8A1mYy9L2fgMxpPAgUdN5C411waG9BMnhfIkR8lCYFT65GLlHT34j9MBhtbi5F8HyvwFpBGglaZbPnnBJsRNZ.TEvMATXNPjLNt14mzn3.qoxcYQTy3ywTz3IyhYf0B+KuKCWRlRrtFncqYb8ZKZcEnGoT.Ffhr9c66p3m3VSgClTSSQavhFXfudgriM0TezLPq6zDKfzBAvLLGEZQpcuYg9Y.qBmNzQ7EgxlnfoEMYe40TyXTlQO8vT6KYMK4oBLSxwI3PWcJ3O+DoPWuixFxK9INp9xAkABWzayeudDAnVnSzyAsT1rrzIk7C9UMWA4hzHvMvRYtOv9aI3OQhVg32WOZJC9QEFtMXBsG1Of2xD3giPclSY36PcAmPOAmqiptJKTCfmGgG+hHikOQiIL6HBAS+xtyP8n+lUFqK6kl+W1mzprsLR6WTzqxpcminMW9EPykeWSRpblE4+mZDYy1.DFSg7r3zS.5Fw+1tY.sd9rIxn18IDdZM4QWJ+wcg6othPNI96VbzYa7mgTPp486Km6RrfAWWx+6+7Kgz8u84iUr0ZDt.fb61FB3OD4Rn18ovMYfFO7kWlCriERsfu7AOxgCWgUhxbRfjB7A2UPPUjyYZmqksk3tBiizJO9rkLWYlCKVH588ZCkrmapOm9U0WJaviPV.h+4A9FNBv3T0hOzy5e8gGd7mWf7E7TSxqQ+RF1aBPIh9WkJE4778sYabYQ82Nl8xHSboHRmshMKT17ohQMcx3nuIyCoeL4Po9dMbHtez1G5p00MhDoblobT7R1lt8OsDeNlLTUi2ZjjL1S0zL9rBb7nYM+Mi7Rlm5mDswy37gLDC+L8fCFko.+r37dV6kst3TDoMsY8kH1h1wS7x+lmDL8ArOw9FKD.VmH3DOZfIf6Fhm+oTMZJa54TmG1HpPDLmSStUMhlkJ3CgDxPQQX3HL8TlNsNQ68II1oxf4qoWZkyQxIoXBOukqiuVEgzi6AcLChJaWkVqq4QQ9z4jL5koZ7fLk3OL.wFsuIF3YWmznONqlWTiQztbYtSeoCTUmOYZvs9MtLLMdKDMe6ypXGvh1ZsT.EnZTxNX4gnWLmjdECUVweve0epF+hjgms4IWiiH7GQXBy3s+GGU+.xAysOGzJjYRJs8cKkIVMzmleKPabMNkW+hNQ2Ef7s98lCQeMnO81lOjHdkHMxroaRQaZX7LfAbpL4xkDfJOtmwP+nECnjm0hpGt9QKXaXcUoLmUINaYMCieB8cdKGK6NqaOyuV9ymN9dUOME4sCnejF+7XZ0llBKejTPmJe4j19KbiQAUKZGwPJvSQaxDPWUyDYLu68JzwGnWp6IZn8QfL4aF21cV4bldxg2juc35TzPu4Yc.gDpAo6sknUfXIPUE9P8TYkrONj4YP3hiyjQv3QR0620oErVjWbmTSGn4owwAHZCRUMr.YVEC5zcbV4KPj3uwioo37T9HKQSPNAoQnUV78Uz4equbsULSmJmmCGeD7PAF+w6CwVQ0VtEiOE5aUmeirm2EdG2FPs.lZYqaVAhSw9owtEKAM4r4NRnW6DnMVTs4+xtGFnA3gKt5+7fKSz9.tCvMQD4GwacBdUIFt+JjcCEWQngPA36uBAP00Tlyl.QKqToL6XEiZMRo0jOj5zSTYaUfBOHC6BMRePT.XrmogUjqmiDy8sewQzW59KTnc3ujhttv3AFcegQmqmALdQgL8gcNl6Qis1l9i0kzyx7va2v4WkpZmGHumMiZNI1Iq0cLzVVAxYSY8TWql4urcGk5IAxcuBLMzAtwJte6M3EVhE4aD9HaKMlawF65TEs0.JsG8vf.S5kfFhcP69deQcPYqxOPuJrAVbMyn3xTYehZ2z2T+8.j8ZKnIX5ZhikP+1XZgCa3Rs.vdRsuVwOt4TW7AcxgpW72J2k24PC+q09MePHp8kvS4rwJLh2kv3ywi2XVQcI2Jzx+NF1iM5.CIUYo8hJcxVif0qTGbzysFoJYWdFMO+Gx7nH2qQd2d7I1QgA0yuwipKncabv9qlhZiNeRRjoUSrmBkMBMvz4j3QF6Ymc8NWjetL.I5f.woODgXbD2pH9tA.jf.YF2YU5jduRUD2zpthMbHcHzj21uy9amuGNOytY6HNnfbKZbH7v91dE0QuBTv5zEScU4KWp+sGWiQoh0NyXWPgIV+U+ZO2VMbfo4.nuRLQDsAzMQ9prgusXfT35xUptU1uAb7Epa9z9GOPZttrqjp0C+qx39jd75tKbFPiQlyuxwQ4mI.xeM92NE25AR199qdHhwGZrleCK4TUf+z1RO66PlAOuMZ8uEw23rvC9bwq6fkwY5.5RS7KGq36JUyIOEMsnwOzIKNdsviUYaaOoyJOfcrTiWIo4YIWuGqCVFqjXUwshpObyWWseSFpr0qCmoFyTQFOtREt4YUla51gAH3chcqHfv4T4XOLMLM4B6zKJ4mUUS6013i4Z4pWoKsvxvfiMHoqOXJPp+86jMHCpARQkcnP+5jXE.aGrmp.1nLbtorwFcix7ZBvvnWZnCbvf8AlSPlCNXLePeB67449dEhFylJGH+C6TaP2nw8ddEFAAcP7DJvlmWKxpyTderUN6SCeMhljISN0Am6ulakqfAwaBC4ADvkIExRJyY3Vm4ooxZHyh3lDrBk5jy81RpOoYyYzqz4F9PVlklBFwfvNN866ehSCMCMz+cHH4hpKeM4WrDOweOxqtnzzGXPtLg0JbIFqGyjsh+en47UJVw0X0NO6ho0HisiHijEb3SQ1qcrCB5EAZaONMsr32786L0XXFVj54alhPdeha9mzfgtOcW9eIsd+2hwe8jfSpb510tZd7c1GWlyZocr2MFouS52p71UttRZPqx4U0ozpW7XXq5ZknOHabjY8qUQdC4s.LIMAUFQiIvpc6v73Qbj.Ojw6Uhy1yZrxhGd2CtfdRcM36W+tiBBv+Y7p9pqBEoSR4ryqPGFZBQ5H0VDf8nPn.k+udpx3UxxFfp++Hg8UXAYEvzigowI7RiRmbRZfqN3roZr7X41SMDsqA9jD6iVf9QJLu6dbbqInzVbpE05dz1lGuvM.vPTDyyQKWDsEQnVbte.iUtp+JzZQCCaoVuENQj5ns8qF2vS2ZP4PPeFnEOxOzdgwhCH6tUEQV+7rB7mBX1u0rSJltp1B.v0beR+.YB+X9FiNTnrkxByGWCYQmu2IHm9bQGULH28.f6uM81Do+NdPEibwSmngMW83IcAbfce3cXt0XNOsJIh7qUYhNlGLPQZtcupiVqjOFTibLFhWdT5yMpUw9QkWjgaiwNBDZG+H3GOw1wyA6l+GnNPRm4U5L5mYcrw7aZic2zwh5Gr3qhb3peIR0xOJvDoOA+ujo9R+FVwSeAHklwL79lSRpg9MkOq80CUIBZr9gk5OZvv.N6OakThgo9ZjJlOKw2eMdAIt7NCfM4HMzzRxTpeljgwD336Lu0TYwxzPQadlcKY7I18NXyXOZX0bM6sdWuxt+0jBkqEp98MXgEk7OTYZpKzvNh8Rbo786f3Dcrnr9EOVKkvyY7enXXctsbsoiA5wc2Bpbn+MIwQfzy66hH3ksNUWtkmgQo6KT2yGbd4angeu2J5+O4bPEloXlsBMfiucOJwkIO4kgHe0qvwG6Cltg0ZpeM2PKfVw6LWgLRSC8JAjLaXd8nNduVTInddnrvM9lR+mKWCNCPjpu0eya0Yx7G1xLLj5Nwj6a0f57QKulgnYvZmO2A+o3xL0QHiHp2XWt7EXbfjRl.bPvWSxWeTaalA.4joKyOUctDgp9Kvk8Pa35lGQyTsF2icoVIOF7qUR8Gi5ZZEO5vuFphfTdUrz8RuSu73wTmCiWiUR2nciE99QrVoykpew26+TyYuKc5xpc00KGDHDGICQVhlJ6OL93YOqkkC9hA6SDyYslpQT4W1Baoi+IMa2VW98y0w9jjdLt6450AwXPueqrZd2gwAUCPLZdbtl9vYawL4GkhLGgpT.nZyRZbIsGtvlx3CxXTpgTMV7Of.xiZDzvLWWN5pCiCydTTK4htdCamWtYWwoC9rEgLU03H8+ljNwXnJJ6e1A.x1i6gIWW8yp3d17oGxOMALJXBnQFKPuQ6gOnKRxKubVtb8KNW8kF5Un2h+VrAKYZFBf2nBp+2XE.mnqGNZPjBXTh0CXkSSwlbjzPNC+CdjxdwyUMxhdIIojlrvcowiWDqjgXzKG4WHgI442DLe2u1v49AQVGGDuSPaOnVp9pak4T.p5xeacR4cK+B4f2Y9iZM1drRs75PpRXrtDR7flwkNcC8jFWihAx4nME.kZ5xQ2vRSBz7bKbbYbx1MmTjTo+I+F..Hv+f87QYChmeVkHTy5xaGnzmmL2MnKWbwVGSzD+YfrD6G8u4ai1OXlQvRXiC.QL5ceXWAOf7EOjCU6zxlHDFWToYNWwg0ed6Y7p7xARaMiX9tQB5Y0afaMFeRDJrrT3ADxx4tWygXOVd4lVjLWGjRO7u03JsT9iPOToaGilJZ7+3irnRKq.ong.d8vUPaAY7ymz0fUSCRyYpfq469AgXGSIkfFPQP7ZtqqWIhP7p4swQ5pwtVj8I9IVvAvwY20UOzB1pWBD5ynTAuIOkFg4RHSHC0BN.0uORmlYt5aazhdsoAxBGUfrfuZaF3Fg+W3bA.7+CbazqrjLoOc5Vj4EdRtUgqD8mSO63xzPZo3dhagzZvCaqZmhcw8jHSKjSIjpjwRUCOFV4I5j.Wk1AeaI6YVYi+L3xmqSOCQ2ZVsZZWioVW6VQjGu9wlF8UccOCspmaReVUb8ySh2Lzh55jvrs8tyG7Cg9oTyiqM3AZp2vIV8uvkF8LmjeCTQAiV4MkG0d4RMZrFENqdNrCZZlQVeRvailOTCrtpYkspoWuQ5N4Y4rZRqc4RW6UybDqHJn8Ucu07t2dWQVr.IBUud0Sptn0YDZBHX+x4qo25P5z3hJ1wEXk5vSZOEiIRtn9Jlm2iBnLGdwTT41pzVJo9CPsQcSv1LkNI9n5klziwznHHH3Xb3BfBPPNWaQb6sGDF2TsMd9kiYC1PS.8cGNXRAPVoeAdIAsOAVPih.IYGwF.Mnn1I+k+oCaqq9ftG+y1Ax.IX+zx27ut398H86gEhk1xi5YoQyIknlowbh+sP1KhU2NfhwktqGOTrDI+6Y63cKZ.JBZFvyJepLKCtSzFa7tMeNAu5+XDHauNe44IRfNCwTZEicVv47+UR4T5rkOciIbl1O.XI5LYD1+vpvKVugAtElxBikF1RLxz+EXM56m8MqQ26NlcjhgK4OQKpVFYff2QmzZ4+GXP+2DexIjUI5InqtflAqELTM.3ujp7+WWWc3AgipkQZxZyJ6z1BW.w6TExtuw3ik9WkFk9Tn232ices427SJk6ZkJy.Y8zoMJba8zRCTozso2pyAWTV0EWTQLG30aNE7i5CT75wO0egollQCgklCSzKl7wEXQvbAIykbhJjRgbM2wRZnDEOrUKA+C0dmADo3mEYahn1VBgQyC8GR79W+2VtDGCB+igFOUWKOzpMh5HL7dgEi9NGwDgZ3xABh06H7RbxDaAyoIcm8rwsafdeDgi1hMK8U+xXyTlKtm1ngfhZK93Z49cklMFqxWIl5HD3C1t8YeeVV4pH4UaM8WsGDBQv61h+4dyti0ICYerNiQi.6xeA8rmRSPgZi7D+xl0FzhzJvw.6evUTf1cC9vQJcbsXIZgy5jPEqeoQkAaat.jd38PJt1jYapctg0pG4yN.aHIAanVXsFYLWTUaHkA+DpsilhRHsem6z8yt50qrbaxJduY06CSNjs8n4obwZrMvDQamCoZY3h7Mnw5pdP7dwdHo5dBl4DkyKrwl4kQ+YwWt2xf1H+ZGBVsW4nQK+vxlKKQo4pBu8H0oubVH.C3onIeKNCMZLhAU252DtCZvm9f+n3VOheD3Pc7XWFVx2uaLlYprf.FaWVqMAXIN8SrBJjZpoOYiwd5QxUUV5uUJr83OtgK5IrmHFy7QtFSQpaiW6DsGPfvV9BxXwc.6oMlGsZ+xE+3gDO4uGvvu1iMl4hM.IMTeQv32lJp5vkJD71UnohLJ2ubu1owZtkjNjN0Yh18XeTcESvAOC7k6NwP06mcqC76Ayw6isn2PG13SZETnL2ZrGT5q5MhzgPZIfyZeavgdyvu+IQAH1ll2ssVI.i7aa9fJc37QHTU2j6Xqvqk7xV6Y1G960BgauE4xJnWbz8kF0uSMz9ym6eJaKNdJsAZndenFEuDD3Ru.3JpuVjDXfGn2i7oYak6w4qd.MZsR25p9wYOrAnpnBzED3f778ZX1DUmerRiOlnXCNNxWl2a.TzLth7041Vf26W+FzE7LTZ4tsGmSbkrM7BPZlTQgNWZTPYeHTvuqqez6r0vtBjCDl2FJKTtodvKKQaqxwgMaTKH01ZufBOMN9ZzQQQL07rQ631bjBXgaNqrzhHvA5dkvgzx.9PH5jjlc0NtQYlrAl.xkgo.SPBIBBrb5MGKKXxWpXydP3w5gr01d8GYeX45jBz9o1ya7S8OoHoZnrJCmxcsIdz5dFr1d7GIXrdRHzlykLn.X8VZHPlo1wZ9sEflwN1ULi21rT2wiK2xSkdDHiFvZPHWQzj5iq.ri6EbenvVYJArf4tSoTBp29O02FcGGHcs+YaVjPbbheMcb5ZEmg47ZkXMpWXtpCasM+2AqSm7G6Y+d000XSWWOJvi29pyx45NfAmlsdafqrQnFRtkRwy8O9zztswEbm+wI8SttbWp4BG.M+YxSFIrgRwNgeE7vnIzb.SmVKNBcMcTFJiVmBVKGkt33EgXkgZQOG4ShQ1L3E7Er7R612CY1H1Q08YWMZ5r0HA5rasqdcEzlz0yV1DP+NQFrHGyxJ3.d7SfFGDdXMVByUlVf+qyuBcmTrNglSGMrsLR9j0jQgWt5qN4NoS8+Wab5BZhEiTZclbeg3h2JEL5PrCyvGJudWxLYuaw.M3mtLJQjba0+xfHn0VGy5UYRbnq.glo7ZjlHfIhyZ0xjf+ryv94v.JxqIj8jAzJp0s.YREK2qh8PdbfacqdwWu1dIHZoDS8U256E1GN20c2enb3C93D.o7lmO5k1+bt1LkXa+nR15Jfv6V6fuWCella7BDaRDd8.JnTsv9lpiHlyN6soe35iJzV5eeodhj8fWlITTqIyO6mJnFK0iAtV.2pBLYtfj.bRGOydcewx8sdMI4e8kRxnbRTYU84x5DZHq.u.g5tw4DtCOBL8hLCZTAhi3pbS4lHolMoRyybXAVXKvilEj8nmuERvqIvy7DwxUU8zEft.LucHEpxBQZJBknLTFbyNEQ4TIGBSTb2uF2qTqpJxMwqrnGbNsL5LH8r4FKBC4lxngJqJmRqqGy8zw7umC.884dbGG9hnqdwcXEpTdspAJNwXk+1oYGcKmtH2XoBFJ7w2ukvd4MZ8m1PmquW2Kj7pIfrZ8DgpKw5s.p09vrGJXyyHL7YxKUmMPB2rLTuyDJ8+BP2JDBlOStWDp75MEoPI9Blf4cxme7t3ce+1xeUkoCCAvI1Xdlr0xiR0bu3KtpZXzMGO6cJipdlXyB9NQU6xzDDwdyYArM+.p1EXwKlRq9e81azKQkS+.SImH++.LJS.tMJGXV.fsM0Dgca63TaWFBa.6f4HITjRNNFPWoIoTuc2ikt.S5EZ2WE2vMoTCuwsMnVHEKED24vfSmC751S+8bz8EF7tNsMZaA0fpBADUpw3AvGUfP8rq+HeM7+3IU69hsMoL3iNgXlYwKDp6PuKfqvO3+za5pF1UyENF5dKpwCJw15vzWuVj9dOJg4pTrJWy0pY5jfXMiFbVkytYbQesSl0H7iLaVWuP5Vpsg4bn4mK67AXs0y4K7s4E88WeWyWM8GcOTghbb9R+7MAbnPatHAjAa9rzO7uO1AlJeFnvz3mLZMKntQxjpJ5p4ipj+CQcABVsOXki7SWtJBR+PV6i0xi8HC8yLaSX9LIi6LpjOpFzfdHUQ2cqebQrs2VMjIDoDAxcS+vSCt0M+hAZUh8TYTV0UfzhHa3lWdTA2VRcjvNBhuKc3J8txP7rvpfyOtxmI0gBC.aoxSSnpn4Kew26l+dW04r1XXCxwBmuzQV87UaQBq6Zjg1M1RLjWWoChMi8.09752MQ2d3RUCHTOjXXUlncYyFPh9IYWSgQIXEdDeo6HAyd2OmZpFlugZsBJa73Hj+Dz7M6FNTSSrCkt+DdZspqsRvNXtPU+hCMRSEZkeKhoiFf.SnsAa4oB.4+ckKwkjtRjOub.NWWg1.cQl1BoiDb2YdCEr8D0edlYS9ZNGVSOOyYbAyZ+O47earejazhVdaHPAKsDJoArmPYcp+JqnZsbk.Fn882jZD9tgHrsoZt2YdHnMqTdaceCua49+8GaRvCgp9QgyP9HZAPFxaqtaLM2CC1kyIG8KI7LgMS8DsfUYR4xcvErPL4IxPFK+MISW+4Aj74TNb0fVF5Z4yqSqshGPAsISSE78CpbcUVPdNIH2IqZZ52nibbNCzRhLmFgh3Edk.2fv0aIYdM66gQ6EURg2Uty.4oIvSv71gBhFZmS.+LJsBEx00PrTtm2Xb8Dt18vDzJeD1dHjiFl.fWt0cwiGUcR.I.djaB46e0LjpgkIULXunCWEHSULScsSFA8ZUk8C64jLJ0QLEAn2VgFWbxZxWgHbBCjkIXctUZiyPECYu7moIhXW0nbzPVuxPJ+Zdd+JyvJXZYYLpA5T1quDWG32gZmqNNmdwMak6d4noa96ESV2D3b2aKEuq7VYYO3tuc01ol5gcfwVAUu8ze0gzGljoDWORlmPgMEw59zrU4T4kWsv2hH9YAlNqhgqKjLSUJccHSTRul16iaHwl04sRAU3VeJyURC.JYFtU683N+1Rx8h3JJpvva0Lvp6fL81QeWFn8T21pJ.EULmhIbTVu3gJqV9jBqUig+bX.HnfkCyCAf694UfH9q+4UOwSNTG5q6dFofrvzb3Qm4YGgSY.m6FXgGyWGwy0FeVNNTk9NYv59CMo3c.6UefpmxxKEtwEaZrb6h5nikifQ1.GdWEt4acgf7d6rsP.HnIH7SVpvD0oFcpSZt27LO+pOiG1p+F8OKXbWgRURYBe7Trz3FjVUs+xkaDfR9EQBoIZFriwJ+OaoCqgEzfGlhIllyKAPsw3Xh0wMJT05uZsu7lNUMnEIcOC.tU3S+VGU6.lK6ew3VrXqln2UXSTqSwp.F8GTyEoaYYYmsaW844B.hEBCSWMM5HK3u0GdPl71sG3IUVKiUox0Y00FOVT32fj3WSRQ55M5X6afrPhVWRChaut8n1Ku9e9.0PZ6E5MWKGxMAZHwQOwGIQCeypAvtKnfNHBdUB.u3jIQxX5f4aXsLzHLJpJlwpHH9XNF6+C4.7Pg29S7YaCJmRxkB94eYyY2B+JfBF89Bx9ZGY4U5b22Zscwhs1Glw8TsDODNsbkzMM6v4L0kr7qXXXDFqIkssJVEs5YuRbqfk3JG8BKb97K9TPCijA.l1kXLh99XsUe0FurgBFd75oRsbfrFj8BCa0CUd9FKe.1pbBORBdg5P5CTuT5NWuP3UK17LMKBHHkMrr7Lr8JhonJUsxaZxZyv9V+ZLKPOI4KlSDqnRkRFvmMNEg1tq1DQZX2viJGq5odVkLOv8w90qdpSWBMyxS2h77mdmANO2DcP5W9y.8u2HlLwKvTAbLUSQ09o7GBhtQ4JjLtZvU075LQwWYGDrnwe1Ywe4RNKlBFxLyzqdGuIYaGj7FTSn55J1XwWhatE2h.byW9SZ.lyvoOq1pfn0yVJof2ejq0QBip+r1wgZY2vlyVkXhPRxPVvXRk8bLTZVHFwbHPVCKqxejHc0IqJj8QdZZVRx0fUjW6bWVpigooftOQTkxTbCQhtXs0CZrPTNcmR+FBP3ma.vFbsS7AfORe.4sy8MUK7jd2JzaF.MZd.1LAyL53AHK1yYdBPaw2N8XkYvcUB.pEIEuK0.BfsFfdGnGaY5hMMGkKzQAd5fJqAN19J40wKaKLxa78ZP3x7rlbBaBCIpV3albrTVvNy11MWUC6GbY9GN85fq3fFAnFHNvfGSgFQqy6II.0jWu.5.mKX2jzNYCVEKVC7XBtX24B0ciDH6S3OFqi7F5QpPuJu2qZEO2iSELYK05ZrNA2PXHElx4lpTBJwdOjwQmxmc9pf3URbl6uzcAdyNfVpx+l3k4zq21Hdwuy2aRz6p53OlCE9vFgAqqCSUHxsoq0RXvosiiQcChchmv+Rj9MD7j5DSZyFTsoVeTYA4sZoh3matR3Cdo095ig2LvpKJLuPsdkIEd1wxIdivhJDloXL+Qy9N8rxWDDqoYBHVRu3iC0UrZd9BZaCX0MSyNzwOWoQR8604BtNj7DJIzCjDJ6AZ3wrG.AE3deT4EqH8lYLp372boAMRQdRPYvCjbH0nAcYhahG6E1pufo8Gnu+pouk.0EPLfK+gjz.DPXetDPlEjLtYLAUTjQLjcYIheAIQIeMDpnnwx.hXlcP2NTNFsKPS1Q9ZkPN2aFLTfw7YaXKcDmiq0LCNOX.1OcObTuVOcYJYXPgX7ot4Ri.fZe8ZvYoZdaURKuW7wYXwu5.7pghVJFM2ZYV0f2IDxZgfdfd4xzQ6FpAJRV8PMN2jDLBdXiiAimNHMa1O.I+cTtxN3jzfRSEB+.DqZkuSUdMKmvetZyh2VPgoLzaew25J7P0m3FujdC+Q2w7wB97ZJu37nB7lMJYEx1th4sI.3RqdYhKCxz+t155HPYORMwfj3eFD4Q0ALLD43jIxsWX31BHk1AlHdJFB6inIt19Rvztt26rjdhmFr6DhwNIa1a75JxxP.y9bnmqyLhxCefGMocNjOLWuRKroj8WkYsvxUF6N20971PNWAApjwcRqSy7s1AsDOJKgOw0gijGw9YoIPjAfB96ylNZAFlnFiiF7ovHqTBM+cbdGu2w6oSKNwYysiMXW1WpFufrRJGnZS2pFCvRaZDiXh1S7nQS2FZ.6O0xBz+MmVo+fs88YsnfzGz+4JiYQg08lBD4RinNQbryRpVn4iZDR47ODHszsr9UUDQoxpsi27ps+u7J0hhPCwfV1ekWeVQ8QdGrBUr+SlQj2h2MjWTiTFXdUhHwuDssK86N9PSVrU1nfYTOyOiC31m0MecwBwWx95K9TyYdl4jKzrnz1KSFw0Yyfk3o4Ac54DXByefme8scU4.djiVMTB0bgkIDsJFmo+9se0ytj0GfchmN7+p5eWFGjlKabLkboL0wLzfCuqKH6WfkrEQZHIY98oH732zW2iK3AMn9BEGWd9IBFFoBabQ9oZytjaRcNRVNztZLmn578vAvX4uLxFyM6NKwy9zXFZFa6PNLjTXSu26VZ4k2FN14nogPcKgN+FDPCYjfev6VyF3xqdYBfLM0JpEYOaVpkz0bLrxHT.r00f3LgqN5iYO8jsa5Hh634SdFDC9Zygh4QK8qM8.8EAFxbjMMGc3CDwgGVVJCTktMF9x.5WK1inUeEle7V.FAdpBa+X0GeGNzapI1JWkpxdfyQoOP6dCZuHqpif5eFyCm4c.WXV6kn6LdQh3ZgNbqZZpQyrv38651cueKkpcQFZsGOHR6H5AsZuws4SQXDKkLD5tOS6UbvueUfA7MGWk08bYT5Tig843aWQBCigHSGebDR8IFrvdOkE29cTGiQorFHAoUbAox0j.lSy5I9lvhnimddcMiaHHef4.aOrnI0iuMO8Arspq2hHhDOoOyZt5P78JIHRg4QJEt3G6Ug5rivUKgj25.XEQBVQtq7gEy0zZ.t6O7xu6sFFOKEYp8jJ8luIqJhyZLDf0VjWg9LD7xUspjPIYg3kw5kL5QPLM1reIbdRwLsKjg7+yyAUjjlve2hKVrCbeu66VO19A0+iE2C4okCaAbogp5BYPjgggFfXA9uVvKbJ9A7d2vplsT27Tt.y5DIg43hdWMyCXnD9ckDWLDHHBKJaNJhdbu.ci1O9l5XzqeaDUcKYpejOf06aP96lXdLpmnT6ERYtm21k7ggIZ2oOyYD.4PRM5AgsulzAKHMwjQgggLeqknTsH4ZBQpJ.CwAgEOdu.Y.VDzrur6s+T71N01Ubfw8+qZE3Wjuw+sUp+2RQmaurMH.wGUzMPzDrvyhKocxgmwl7LqRxAyur2k2PCa85kmYgt.pRJKERviKp2iaxp8UtMkw92FEt4ldnUYjWnGcPHeCTkVh+K.G5Lswa0koHZxwdWPtYl1mGG.pY8yg9wR43RQsOa5AwXjgv8Wid2v1GkgFhc.pPDJDaCZzKoMuli1J0g2sF9VxfqZ1DM.L.15+jXoAxvqSoWQx2QmGYfAr8tJ5ShqfOiVwCLBQjPz.1Mb4CHJYN6XaPHze+t0ftVdsKXQ01SaL8ImfCAqe2h9jH6DpZPXhlXeI0tNpke.pTYk.ZRNC+ikjPS9vIEXoinxbZm7NQpEFZEmAfJB8U.D34INTNzmxfUxrbaW9agbIUU6Rj9C2nqWcvBlLnUtH0mylu9.GQDuVoAhZKp2yoWKJ6JlrV+IM2PDPLUubttkGbqYPtsLQspSgt+4.SDPmWeF2QKqL7m0K75MOFnXOYnQ52qxC2KVfV13wYIfLw5DdXT.V1O5wE0d7LbCUB1tF2Xe16mm4cXvcOucTd5CkGM6b7qZRuq4lEgK1+ms8lNA3mzGgB7uORwseK4AsSpoW4cshWVN8tMUEMz.sCQcg9bnFzrIjyjRM9mf3VJBX6FAEmT+3as9XJDPN60RiK1sVDIB370RMwZvVWoL3re.2mggFb9SxfoxlI11qbhZAaYrANUl2R14Km4AJQ7jz1zUaH.1Qtj.4E8yITuTtI8h+9WTo1EuUGsoUCJgFrqENPNdcQPndvL5qeVu8fzkRUFK5Tvz1AoM.McjHjzrZwlqOj9JselwoomjF+dPCkg8A.qQPsSU2P8I5L9.dlk0sDcIW2IaH0RJaloD085u6nd2hvAa+Ug2THOK5eqMU3Dmk.uc2WDhDa8JFxETOTki+gIenW5NX0W53lrr4OnYLI8ih.9aWVPcE73NxNNoqwpM1HBPcmdckAGTJ.cRa0xE9As1w2xcNTsmE0J872coZS7UjFmY5fQzjyd.5Nd7ja3ihUuQeTWMsIcZF6OItYdQeUF3U+CUPMCyh3XS+xFYbLJNcTekwzumdihuSgvgt.55bWhc3INAxegAKfK7fRYUSAlvbILK+411lY6KpItb4GohhDVB+wRFg4In.wJ7X9bszzHt2ioFvfOIuMXnGbM2qjbdMxU.5tBrkrgRm7cwk9m8dzlQBzbjH05O+03E3yysFuUYBP5f8kgejiNphBUHjxE5+foCp3JUjh+24GbjXQsMy.1qBWrTfYIJMk0JcXtluaVaQBaGTQsMTSeeaeqtB1jCGm9ix3STwt6917SDXIXuOzvA77NHAkGwJt6SQlwDZkv1Ccyhbq7C5hLA.nJN3K60Wdo2vMm+D1bucvXgxjsYHBUzmVkykrQjrrYZoEiBG88s7jHX0srzh+H1sRmCCDDdBP1T1lgv9zZx71SWWRjtpOyryFyN4RlggHguvlRuLznP.tV1D2v2mu+z4t5B1pfeUc1aWT2O2Q+z9zL876Oz1nQo+i5vii.hPLNXJMSwFoppqErz4x1zgheC5R4+inB1SgufQJYIIUJ88m2cZTsG38gfscgkigN7In7R7cuk2Qc2WmlGYNtgd6xE8uYfRF7wDrhAwjX3k+kpG4KGs7joypD.fr5Lra5KgL2Y+7dPEJ1R2Ms+eNJDILmsraH3jK11JLpNptsSC1jAcPpmpzLA6BC+adZUTJT9OHxK50VyYmr8Dqf3eZL6AXLVytvogrkiAARcZHnONFYLVfd0KjoeXtpkuQWiMUgXM3oYRXRY2nSxhjkqDIlFKch3qbsMEt+J2chI4RWpszxXWXRbI5Yl1W62XIBGbQci7IVTVQDLHcwspO5w4fh1+EoNN4jwRk3uraQghlwQgTm3CRuRGdeAkpX3D1QStrC7mDwKC6bF5HgjHwtw.6wDWn1TkMjyL.iL16pqWvS0yb2i3Lr.q.oIzp8fzmBPr9XUomRHljQeZG3JozEtzBmWhf3WiLbZKM.vHPNyNOKuq0WFKcgYGBpBPDe.42EekLyG.gT5U3W7.8lx6INL9CyPg+jWMoqtYCmohP8ORKTVmIN3Nd2yP5rkaKl.VyusUR56xIGl8MgM6BBYBRJiZKoSVFdftZUZsXOR3x1OLlM.t9GS+L3Hcfhd0Tp3cT0RWHZynTyjfX5dylL1xlHwORGS14M2U0gZhGGboyDfINDk88SCRx1ENalq58qTC5wN5OYLtji+xPB6ajl8xV2wXQ9lcC9p85lq7yO7sw8Jn9ZeokNw5mYrRsln5g5mMfqnxM2I2shhNEar1tffscdoPQr9.U6P477MYfV2notxUSneniU6xAlTp4l2cH4uEzJmNQ22cTwRSmwWo0nKzuPgrt1tFhQr.tR+ePUch.B4+mQyGYwFxr17K2A2z+QMZ0p4+SI4S4Ew3SBebLLEFjskLYy1tdC0FJQoj5NaEvrLi82VwMnSh2ixK0GIB9VCRLZWyVhYzEToBP699m2fnzMTML79li.ra93peqPm5aXq6CDLunv.s2888HTJjlDrV+3yzDb+jjADsMqovFXWCc8xPwcm5ZCJeAhDNtXGaCjLCfuYfdbktqHRI4fQND7eo3covtxohZaQ+oA3rMet.m3PNPej3Uw7HnLlUADKhpnTdVjeYvYTOkEdpzaqdw0VCULccRjyjiiifogEcCh4+VGTjzzATMiTPwMvX7tYtWCNt6IivPljSMG+K2RLA6gV61azymQxBdNbBhC7YZMr+nhK.SdiMjhxVGE3vOKQEv92o7sPXJXfLK.qnd1V0SoCZU7UqRFQRUa+FX0UoOp0w0XKjkb.cByXRxqfLtU+nDnpaPoYLsgFvios08J8fRISxpyFe8wbZE6IZdiz1UNIPdYwK9tYpykUmoSf5U3p9NzuUBnKZcwTdpsRs+QDK5AUn2l4vQyOlrA7TAe0A+WxuPlyTHRZEd5ry4Imao6YR8n8I+JfZJVz.cAfyMFq9EGvKiwnwe3drNFPJWpkJBx1oGDOf4oNNRfe1+KJloyIVjhIFzzn3cEX0siySGizFD1AjfVLxEi3ZJAsLlOzRce+snX5fjxWQYqORdN9MsWl3JWMzpdKxyBLSuPSgeha3DGOXS95V5t+YXYvrad7zANEc5lMklKYAVe84aAN55QdRYRWbwMuSyVSBg3uYe34BXA69LVwTHDbm5kJ+J.LxYbbdJ8vktTDEyJ.hd2ouoQktRMs7vCbX3eO5LvdLtaTc9ZadXxZfwZjwVlmGcZ4SXgYJkwBElxD9meheAo3qxUiDXiB6TuiIXbtwanrW7Zu64cm0VyDL5i3w1dwTPojB1GYYHYnvZ1fiePvi3NIO41rO5pG.UnDrW0bs25zhXXoEUsHCd0wBcMCLQVPOaJIjRiiiPvF+5pl3xtmAMtLOlrj0tyzSZhJxLr1KB5NSer2QGJX5rJQdvJBXhPzQxr0Eh9ps4W7tr5g5yirutd.7LNobOac5jPUu7WEARi4fKbonEiwclN8q2jLqk9PHDjTjlo.0i2mUnJ61pTj8bPBULG3bpA5.tgzeHLFUXsNgUOa+KXgCE3R8+ZCJtqbt6B6v4TKkHzMVVx+zJ7ovxbTrCnDKzclVOgk9z21itnb9Clwa7labElEvt4iWU5hj7xZ5kHdjUa0Z2QH3Zr0pF55DSvNJLPQraUVBQtqhQoNROeKWTJN4XBkuviqAq8mNzcT7J1i62FhmHbLsttatDb+UXGwGEFEhx+3I65RMW5rY5lF3VcS8K9qRieoApcNMzADdCoHO7RpZRO0euK5.nO.D86KxTlaUJl5kt.Kg4pF.8IwPsAvGzdHWCowsLp4Srzp0buKEHqduHi2lZWeulfHMf864DsKOhjuRzHdC20pAVAenMLr0.tKVvCaopNTOyVs5GK6Z9l7EvmwJnUuZ8VlXl5qyu099mwPbliZRHRT50bmveJksfpszd95vgiGbUxEl7eaxMoQOEN.eIkB7tzg8XPvHKY5CuzkJ6qzO3jBQTpOXB2nt8VDm3XkDGnlWHPT3a76C168c2nCLIBnBdfaZ4zRLc4vz5kP78687mI9VY.ZgGjl5PsC0rR14gIxUjQpMarm.6+uNRZ4QI3Sa4va4Ku54gEN3ZF5xZtYV3Bn+RyRi8FArBpIm+qLCSyq58GndtvoL4ctZ5kDozoA.g8l7yYZMZsLKCfFuoe3rxmuDAoM0YUwiAzDu6AMdLRHsEH9b7TMMumSbai1uJFgOn6VrzYS9Gx6a.Pd5gw03FEBTk+r8vM+GRhNP+LjtEnavqFKLPhmGNKGDytnA4Tk7CKdwQJCEcwT8wWPQXCsJxWza1+yCFbP3zg2VYMKT0VzNJC5AiC56wIxO3GXG.bGpDqUekGW2IaW2HZ9+ZPaTVPVI3WEP6caWRzXTkITadkgY7wplMn12xFrNU11xWYoYGCmVtEBE5ajMVvv6zJTcgpv96v8GpozoY5blLoXk5p3RNVLd9ilaqfcqpWH9e9J9wd0xda5zrdCYbxMqbqTEsuMC8VFDVMJB9BnxwjmWhsvyFaCqQMp5Ov3kjlkjcic7S4MsK1fPwMKb0UwvzYKj5sqVXd3Y6Xt6.NgJQ7VdGXhGJrm3qmZooxuqMt5v2EiNtuJU15sJkeun2Qf1rcck9cyI1MlWKWLGRAVSU9wH8Ut0ujieG05ZITuJohccaTW+U7DgXLarTb9yPR+9TJ6qcsclnOpXAWZ1DQY9rCimo1O.9wMcr20L7jXQKX+hFc7JyTgjHH3c5cJvFrDqdnGZOJp9Hzp3ufpNgWiAq0abpWGibSMUjXemO6xzv8XdhsIoBQdqDNNVqJo1sz9Y3O8sJQGCB4QntgV2Pt5GfRQ+k1uKy6P8066+s3a5Y3vF.l+5sOBj40BJFLwmjdUM8nNN5qXFu.cW1xdQSbap4n1L2H+PgYyoZO2cxxrnD8oLnLKxiPh9GjUa3E7A6CwcAFl2kMEq5939cx13HsarzA5MLLgQd8xG.KVOHXQfBhk4eWJVhdWwmr2JrtXeiV8oDg9hfPlYPPc3U32pV1lcfV3crqDWiOu9VidiMQm4zF0CbBlGNk9YHm8xlGv5B1uYtT1dCmWbDOCLPMxBEE3zNYplvSBeXM0F45qozoLBesXct7KepHBJTLbSjCjnlreRzNaVQgsN+t670rTrGsYnqGKmGXmAizPEntU3ud147uFSMIAITMm65Zl8zHvoxR4j5sve3yP2H2srPYKIPKrI6wEJu+pLs3mrT9XbtfCC20vhC2H8j9w70efg8o7PDY.Ruf2k1jTs6EMugIivw7ZDwK70y8Ltv0KhnzLXm5XE.Ye7aB4mZECRFGmRCfSPgOydeiS911i+8wxtztvaYJxwOi.BxVToB9hiymRawf34fSCKklBUVMppU12Sr6t3RxIqmpWUtr4bVESG16WBJYUixfkgL0XJoAC3ftV9pPaq6dkEkRCcx2zZZYKiwIWk7LNJ.I0URf8oBI3ZsZzIRsSBdLvydHfTQr9hFvrxDPMEkOeV8waEBY3EpuJSEdR98.n1HrP1BWkLXK5kSzq9Nx7sTAodMNsC4aacbnCEG3oTG.mQyCiY0HjmZ8f2LI47FC519YOhf8gezOc3b85dOVh6ijem4SSR8i4jB+8hTKqmolPb9Dy1Vu7is.2a5GQd8aUl83nhEL9hoT21SmYjX80FpmLUFFcSaL4H3TIMXXiSK4rqz4h+R7urrRpxzqXc9fmYZSOcoA7U3PSbpSanWbGQ.4g.y72lggMuQeJkTLgZ3R9kMD3CvwuaBkQg24aKOMV4XocMv7vfoORq.b2.C9RDCJJa.6dLslY6ML9GVL2YHjcmI1ZYLZJbQYA4vmMastExKBnUhcOf7RnbhiZ8JReK1Zy+yHmxNelDM0a.09.52Qv0SuZwZKhgaonJEVWeqpVk.wmYkMxAp5.RscytyJfQC7hT75opHf5vcRXs30aZyPVmw.g7daAadV1M6PdkKpPwWzl2TBneDFiXJxF6Mk0QPBe4SmWjHrdGzVWa+AmxWyZntHKrHz082uEB0N4fVaVNyVL0.pGOozdO8aC4nlvoEnmjMXrCBz8sxvNJRy9jGFMfTMj40qydp2ZwuhW.QA82DKPNVMSfeth0pDdhj8aAFyzASrFyR+oKIT74PFiCXaWlxBw.ff+26VBkv99DAWVtnha4JVu.CqHfBafdGL155EkJY4fbLszQ.clmN3ZkwvhMHQ62jslEIrpayEmF2KT+ka.dOw+I9Dje5vmCvH9dtasNsKGCNctgpkY3OAOmQWc6VQvQgiznqJGfcYOapJ3KFhwRJIFGZ.Vr0M3eKQuPmNvQKOa5ALXMWu8U9MyDX5Cz.AAwEw5hLtQvEq00MQ7yMG9d3wNZOoVi8LaxlDJqImIWZepx.IWQQP7.2xxJTs6T52p0cbQTEYOPJaCOcmuvwti.OLd4rAM9Yc32JJZ1n4LrwWsfIBhW9WVJevsej3+tr453eE8xyTcs6fJgF8PNUdYWpfiWh9tnKYPoOIZhlTwt1R+hVTLqHwc7d0yMnhOpANO5ApT+VV2l9X+3EPwMCWFWu7vrkxWruKieWKezC15+jIF4qYwogWHVoCMkyBJzf5ZpyTuOX.zRLWpTpiaCVDOE2WgHY4LFQZ7dMG2jknZUN.kKYvfwFiLw4n+48eLD3td3VsBAUfZ73wvsBz..zWptJLZQIpO1dv.a1iZ+O2FrdKk4TMrkTTqbY32uuCsALg.UUKtglnOk8LpxYMlr5dVIZKf8WPlO+d5XhX7I+V2BFFuu9I9sOBkMzRuTRd6.72B7wSDxeeSmudU5jxf5sOTEo+Zz+VkENVez9Q9Fp9Exgz400bBNhDDZHfkQ96G6n0JCmK6RHyceQjiOWjuLZDceNro+deDXXOTNJHHDC9QJBzkDn2RxahjYIvetmvqQh3sQzk0bi1aVvU9CmMV+OiWsg0IlZlWD6psGiDfnTFhoooOMwzNfKRh5ODYi5sg0+SGs44UPQAudrbOlQMD+0mef0fIKBn1tCWr4l7xYi8RXsQqL8pJsi4UYxMW.Dv+MuErAwuOOxs4j3nXL1Npp0WVP5exHSam.E+uMZ.6ogJNYneopsfxaKcUemLNM8fd.evR8gPBZWu.jc46T7TNNfCcInLR71XPQLIYdRDQ5Q1wJFN99eaJD7KjzzW5S5ZwxwWc8hPIVfCJ0CBCBrdFcn5RcstsXYVH1EiPe+y95uqshbnNjUmFSRiq5V5zmvHReV9QDe9DYO+eFzMR8qNpB2IOhFOB0iFMbh6bb3xwP4XCZWi3Z3AhZhRDZGh+OGCYUFKHtcRBvcEVdFLnRlTeHkIfWFP1LxWQ6uj2GUQ1gDILBL9zEN0hh55PstQGrJfsOQgZYwvz4hMUIKi8tyUuxIryqMZKnyWYl7dxiQuedtwa2Ej4N8e1pbUTbKbhYdcpTCq1h5ezjY+lC+UD1CUb3U0ruQGq2VjGdwUinreSx3eJEmTQhIXqEYfLQWXpYq0Vh5su491QxaUB2PRuefIZ3HULfpYYa7+DN9tHJ3JFB153XmIa7DCfK1R232AOsGuqWhAdYPLZR.4xjozF.xs3ftiT3rekFWSdKv832rit2u3gVkXjev6WzR0v2JzGV5pnLrjXqC4bxQU4WVioHJTw7Es+55fVvNHt9icdK8y9e.pLvKaAN0Ird8ZKaRDD.Tyyx8gt3ojgMVgTEEZ832R3Acfo6iUMcz91Se7tSFvt7yaln.NyZRH7Pbn9dDw4pohazGA3U4GWFRowtmARzlXGIWD.bDx+elAHeJmZSgfrDJCocwpecj8mYTuo3QZSp6uSTGuq7jU+5CuB1DVewnLDDT42jSywTP7vivuJFYkP9uW5n0Ssz9+HNJVjEMM18cxImhmv7VTCu9ph1N9dtuK+q+iIBIJ7JhEVkxOciEemoNppWSBHHkCc5sd49I3ufVIHJ7C2BWJNJu5cxl+o.NgtpQS0CGGxCENr4Ix0fA+aUMR2Bg4RDbEeFu9gssBepaHo2+fPC6VmU+KNqUGWV+xgnsMQjAOtsPLxBmuP6M+FOArhsHQGbzytNVIx3KstxQNL4CC3d3of7cn7aR2Fay08dsjCILh63OGuyiTuCip4x9joBAMcx7Z3zWZotEse6g15MM3i4uUG1QYur4bLekjLNWNT4w4FHJ8Lb587ZP1N8.ZqHrdFrQFX.9Zn59nMI4ZQaBUFouHLkhOA1yM+sWyYrntiz0IZG0XJbYLYIUaNGrunaETx4UV+LVvcEUjaBuBFdyW.eOd6nMMypkkVmbkckyDVAwVfzek055TbMxUTxDv+EkUctOV3.M7O74heBL13W91DiHVXOLC8ZBcds1HUJaskXw93f5dXIKi+7dvCU5ziAeSWsoNr+BnGqbCdigerUgz.Ck4QI9yDaAWoZLpi2P4Dp6KJbFZA03TED+Zu5d4qe+ye3H0XnWuFa3f+uT.0spXQlRNM1THHKytSg6Su8Dj5rOBV2dX7GIC8TZ6Cx0eTox6N+DYiWSbgcfYfdX6XLW4Kz7X4g9IDdAyIkTLpz7eqmExMQyMfC8lJHYQ+Hv4C0sdTcygz7CdrE0RJUwv8tdEoKyLELsueDBWLiR+vwv2nafDx+ef5unYkNGRgdQbM14z1jZhNMzZpQzttc3WEyBRfDk0Xsrc1zqX9d0gljhVVZv81hrCfYibBI.Rx.ee.Cqv1LWTveWb4HvQVnGuhB3X40yU+rcUZx4rwjETKNTByWisXkSg7rGd8TQI9sCXCgzwH9TO.nee76vXV471HfzVtH9GPPJDlIMF9zcsyyTLKoUyZxi41JjEVuMS76IfWNYIOMPBY9C6gcbnSGTr1QcYwUyKfZFGJ4YyK1IC6dzx64.QMt0KJQ.EEkga27xfzCZAmVbP8.I9jewCEnX9RbPxFZ2665J8hzpjusdEHWBdK1NhjPUN3X7L.al5RVxC.bp+WHjRJ8PD7BYqPhAhSBqxh6mikNc+pGqkV.RsgbKLnumNqTkLqDHLd3rYUL88l5RSGVMWZ1fD3hNqv0je9ykFr8uKHSQr.jUfX5eJpN.AtAcHHFqAOVvZ.7SvV0McloBBXD3WRpOylzzUVDlOGyxYvHN5XFl+M8kGjWnDISOmxEA2v39LSRpO1O1+UJavP0+SGYsfiYYk6WyN+JXlxUWgJvmZlKZa8UO.jw1Lg34Yau3FAOCiLZPuUjB089sonwjfZGkmwXvFzXLuXSc.AxcRHMQn2kGbpOXKay2MPIwz1XBLfc+0KHBZXtrjEo7g3Le.k.GDQEYjNST49FNDNnUQrA6zGLSImeRdWF2YahSRVqtmIeMYmOFZnHTIu.2Ru9uHq5p.nu59BivMmMfpfDFLanzY4onVoS.A7JEpT43aDnA8d59VaPJCTQ+SPcfTEzrQI58c.D1nfEcUYyDeHp6aiAP8BPy5+HT9rVVsG0sBrKfpqVSqN9zxQCYalQmSL42Cxyc8FTjI2s5pD7t75exYNVJd2yq5w8Ey.gGGI21AAqgOWx.zg4gWElJGiZhycKZndDGfIzO5Yz6wqk5M4HpTUVr9khQVyToxdd1AAlg0nUWfCbPXPv5nEnoSdoX9AZQFLyXJWUFvDrp5icdcO2UgZ13.JNdprKSnGIX4ym1Bj1b0bh6YQoTfyC6rNMIFGkkcsXfFTpj66no6gAWAQBsEijPpYIsp+iXmfjW78qnwXGNvPTAqgASoHIB6r82p9b+3mjiUiSTTK5opPGpQ1nY2ffScXYEojoJTLYhu6Br.qf9TaE3xjXiJNzF5IGJwkjjjwYzMY0AM22Nwi8BIjxHw7JGBPwd94y9L1fvFhMZhuxYT5+X7F+xo8PGTHxgxyLwfxUc.AO6eg2HwWZMnGbXufGBPDMfizuL28LehAwsJ.z.xXNmT9z7BZzq.Layz42wzBoZaJR..9IZjOnjbZ9EmJtZJc8LLigSGUJplp0EYa9+Qhbu4PLxwIAKl8EY9GlK5H.0V.imfdeOfG+vi22itdUqcUd44SjWU2fN5syJElId218C3Nqig118EfB9tyiPP9nxcv2oNLLXWTA09vq2kFmqNu9JE7Pw9NzJhodUlye+kk.bdpgSP2KiDbLg3LACZdTBk4CaiO4a2KIEANRRLCwhirMp5c5va4oLW2Y6wSqYylLs2SS5fKE7KUhpDD+C7m.Z0VOJQCKbITuE1lE2yX7p9E5jTDju6Yrnp91y901iCYrkdDb9M9NKGbSlQ0hrdKBAUiPrq9QONRSb5+Eww4dblGue2RuBYeEaeV7NV5nDMoxdfCYiO+fPoZeQENFvaNnfjvlXnjnnkfFMZyRAB8B.hwnQFHHJcDyP3xHCFmtbyHT0M6Stg1OzjM+4vf4JQTZwvYaRQeTZ8AObOtEgyiDvgaQUPDs.vZWpCv5n+QPSUXdlRZ7R8QTCq1y3LT7i4qC.uaPxDl6XiBPcfSwRBs3oqPLbP3qB0s9KFCe2SPDFPRgHCRXeFufZ9HlgxOssH4V+B6CFtKb+BZs1KYzNk+XLdyiTr17VHqlLWB.E2xu8PP9QCZomP1fDTbLfPxnUSGmCLs9Byfygwr9mKkebStDcAnqcsbYby7sxrshB9r7ZwMu6y0rI6Y63BN.30YsY6FX.xu7W6N5JQkZ7S2bVHjpcc9mBgnGQpxV8NYEGsK5JB+15rnv4oiyCloB3w7XEklAubBbHHjBgYmgsreXadpRDe1qyqAfNDmAVdtctZdkxX9MYwQbwL7ZX8sLK7u4SsGVJJiy8HlOnxXup3yLjKxYo.F9lMkhmnQBUfYGJYcnULmx5zNrsYhXbyMaogLOwo4effVG1A1cvx2.yxLybfEhAEzWbIJ2F00bERsZWdB0LDSvW.M9RIu4VWu+8qKwaQQMPJ7GCCbYMPraXA9Jwl0bBZMsJa5Mt16TOZZ6bjuAq1ajGB1DeVLwVKC76HpGyFxOdgCflb4c0qYAMlYzK7ihBO6aBiGw0eVvTjCx6Ib1fJcoTp5EuIS1yoeVKAtGmE2rBU.gLdZz3lp177Mn+Cbb1Mph..rM81tsBAtDzMP35tH9gVOmjoeFZpAn6dQfYwmfa81ORrV4yIGm8nbqnoSWZlDSWXp081SfgJhounxjF0Lf3t2g008DOuwECHLnxx2zsI.2r5A4mvua2Gk5WhoN1TVgOGARdAYYnlNmcdwDvk7lXIlqxFA2E4dHGbZa2IsplU19DQiu98R.hxLyhbj7G55bUyggPF7+YpUYqmhRJ18CQT+NYr7mZneuSz+WGo5aVy7haFPzx7I9LR1AQdO3ul.qYvZSFLDaLqdljAcZIoTebh0gZcPHWVnoGfThRr.FkTyKTwyb0zUacNd7rWc1QilVhQStXYvRj8136ALTpPQNPPyM22HP0ALI9MtCjnE0W3YEgCbSEhid73UTTLBCKIeg3jqj3uBX6RjsBOTQlH2APzpYgZxHxwIuAZ7O8IXBfRm+4lMJ9f4mML+C5jKan5Az4hZryB6naGquoOgy8Yj.SwFpe49Qd5Q2B1AHzRoJOQ7+mNRdspSg5NFJ2+BAY4do.2zH5rgQ.W.vKJJpPWv..VhN4vHzeHZ.vbG1OekMuVvJP7sZTOzD8DUc9Z8Ak7tDZZgb1Nb.lH0pg3JrJKYR57PI9BQWq4QKSxuuXaqsX90Q2y1AAf.YIS3OBdbWoQP72KdqErp02Xua6dnL.9LjwQY+rdMUKk624ODBK8q2utAO3+5yRTmjyi4CdYegKMpfL5qVbC3KqGY3AAUEjsOuCJPihu3LCujQvujTuODNltdM1ZXg+CIEnQ6vGmcHVPbcswSfEJNHHwDKO7qyXu5jEMQYsyrNPx0UhKKBZfG5NYmXik67usXJtZaAA36n62XIEO6b9XIUUZZIy4bEA1Ps8U1CN6tSikPlKo6DiEn5BMlFBUnQrKb3h0isKPMUUNb0uFawhzHvsb8ecexH9u20ml+l5v+Y.hm2UVfR8sEQT+gFM1RtBHy34dyImjY1qf+ktiUcHhX12OT8pSgiewIvm.QdWwmd2mWw+hNIFC4O3dP+Ysdb4UxP4OWLNbx7.mlOVbN3GahayZK+Pz5FbMXqrPWgIh0yO.W+DAF5cx3ZYrgyyKbd.Q+ygdWXeTwkDxdftA2QPd8kAGEdPmYeGZbhB7xuslpT01CSrAu8TMVmAuAa10prHFP6BOHz0Y6kOMQdjMu6B67uG0IRVzP9D0cHjHChYa07yzgYRZ0kJ4mApHn7j2Eiiw8rB9HMMT0lIo0j1TTtyZz2g7CRnNaMrQMHTCPy2BG0FY+5XSS6wKE8DrbEaBMG96Mna+Aq7zdnxs8yJpEpmcPYj2E4K1ggMms8WSWsBQ02YUVFWml+dx1aKXHVUOHS7F2zdEITyh3b2Xb5XTErUiRCL8kYR6aqVQ5LZIuQVG47VdeeR24BguGt2KhvBtR18RGNscoVtJIj9vhH3i5ojBk0nxqeaUk91d4N1lczyNz0UyCEBaMz4rldaVklhfXxr2E4khxmYFAA4UAfy8LZ8O2J.3MUUZgs1n3WIZ9Vlo1adbzP8NtioACIByUn9RiiCnnqzpxnP54+SjCsrAo1gIlPlKCxEpIHHSzbaeGJ+GSeYQgHn4BZq.x2n65QWHlkaqbW2pWg.4yrylQIoMlzpAihC3IzSKcvSmKbZoepfMmtLZS64jgLlP2gflP8oWs8js.WiaI+h8SVEUYWY5hovQ6t5kiQZ4i3plzwiMhVx6WJ2hqbg.iMcJZjLu6MOZzfJjrDID+c37oVY6N3LVZ23YRo.ksjYv5Glc4cp9psI6fqaYVl68yYwRaQtvJM+LgGtoWo5U85LZJqrGmUvjJMfKuaYIFfENo7UT0cw3vrRJUxcElYInKf0JDuh2zjnJKqABRmm4Jw.fKW9Jrn.l+mZ7RzTXgr23vXEE2UAHumN7ObVXKEO2tPuavioF1FyQiseQcdX1o+NpIR8j1Dxka6..IX58rBr3I+Pa88FkbeCkQkdkbaKXT6al+CmW3OvAZDDyZN1AEotjk2Ft8yiJa6hsIPTv0DOSyV31ATf12tS71L.wetIh8mwCKJoGlXAXhW2+bqCtNEFoZM5spGWX18PMcZQiCJNp5b+D90kLJdlV6boWV2Oz8SyExBJllCNn1vx68hYbBghsKGco4VUW6yVVaqZuWrWWKVoc2xt3bVLNuFE65CJ5t0MzEdMq1NWz2uTqvOwzVKS4CC2UiekEhQ54JBPokWZ8KqAuWAtuS0Zh2hO3u66N1jIee1AhQ4nyX0Lfn+FfZxtRg7nociqIPIxGJTM+HwbdJcxSX7yhHjWv0W.X1XpoXbzG.IJUAUoqU454VgDsTzHOTd0sM6+z6CKUpggA9DnecWNZYtoLLB.x7M+pr8P1xAJPbsP2whqDaalKt7ukob8c+bqSCOwfpSuF4d2Rack7Cxm2mub6rsecCIVXX4RwNKJlxXrftvNZOL1h6dpWmXTVlSbCcvqaE.mYpoujmhFYxbjQMGSFGD0K0wLa8RMeO86EcXrd1wTRRX.8S7lP6CtfMTJg1VndDws2lhAzOASy7iNde192Drdk+E624.zflQcz0clHXTyTHMabD9KnAoc36VdWtGdti+tXmG68SD6n1FKY4E15gs.E92BTsyy600qSGrrJ7h1ecqD0NZ5tE5J0T3Q4gyJHO.SAxaD3wRc4jcTDpMY.rWxEkzQBjCCQnlmeK6FYOaLT+y7O2cz3osoG62J2TLJtWKS4S1H9nEBs2yNENDwvi.NCCTGPXMCUJApYoscy2oxfWgk53vQZa1IyOGdvFsFzvrgjqsh5JMrR0gYoOaeFAy6yJLVX3+mBbGIH8Uus0uRFimBxX0+UhbWfIJzVW222M0U0deG9nkF5Su6W7Nr3gwpcKq6xaKSW2.g9muqeFKWxSFyg5fEDkzwS5P7vau20WSay+3mWtw1TzQMfnLpmJf.ikAiFFSwDfMP07bDTXgH3sMCqXGC2NpcPPkRDpQGGh2fh13Vyw4Qmzqc7A2tY0GDlhfQzWTF5MPHxB2w36Gw9FG7KgBJ1xvVoqXSHi807OvuGWiAKoLF1qB0tHJa6QB6e0lBmR3knKMgWrcHN9q7ntclvqpfTk.vI4LzkQIhd7jVsrwaVlRb3+YvG0C8yprZR2Q24xRH9EATnLYYZQkZV3kwWJX7WdbZbTOvN1MXisCa3rZ.CupyzM67KKAh+8c.KLeU7ijNjwBYtO7CfooX1P+1+UMWvFKrcN4MWsBE5ZWLDp6MgQzK.qOVV7bC.BWH2gYD4GzTDVZv2v73vB92IjKhrzM9gWyiGyhC3dYW7RwD0rV9nWPmgfGmQi4Rec5wfCO3pH.oAYjsdbEQBfyKkM5LZen+HQzNTKkPsd9gCAnCXDhp3xia0crs4b1FyfuB8TEKX1rpsQ.KtwcecqtIZgmgiQPw3U7FiwFeCFyhwnDngLG9SvTmqEe4Pf14ImLMF4iJ+104v2.jvZIAna+0DCqkbj+KWynBtczXsKc0WbbrhUgtnimg8O9F2NJNBTD96FOCnXEQ3TVfnfGJgP9WHJw8eaWq47OFRF5ZWIG0Ix6U9Ample0P40Dn5pwNhNOQDDuTv9iF2MPZ1dNaoQ33ItZrLcj+ktVPv2Nel2ax0HqUL2MqUvYJTvDPvbSC8tGYGhdk1H8vB+0wTR8NRhozBsajBB7BxMTF6jxdLVA.dLm14VtWDI18dvfBvCoB08BEb+9RxyD27riRIuJ6Fi5kKoPzpgSDH3dYuzfc+xco9jZpuu+eHWwo2sS+.7GXPBSSjEHl0URtbdGfBl1ACs+If1ODIWi99wNp+rqg4ChKSW92tmjoaV27vpkZsHW1aHrxBa7489fCDLoFQoAD9c1wqJg2H4wU0WulbBjQ4TVwtgGqMMOz+PJ6JlLwN30OhDZr090LPyNdAgjh.PrfVm38i6A9Cj7h55iztinf9+6vmYlzFIojq5L3qlF3JfplC7mCAqHxglIAVJi099X3Ydbfc.7lyff4+rA3M+WAO7Z3.g8nSgzft3qnUkQ6Oa2qeai4QgPu7NZeiq0qKBuFa.FVlpfDsQ8732qQF4eqQ6IeMWuTB9ZpyC8uG.VLpfnss3mer8Pa9InofFiyJQO9XoT3o8QOvmeJNNFehJz3YqrQxvCGIvuPpyihERav4KIQ144pDp1zGHggnNnzL39AQzdGnDPUWUDs24UTr4fAfMIL6mTaM+.t9u6Zv9AhbBGp+vwzC..cVmp+DvuOnbfeOUyxPa2YmSybz3K3DSS3.6L0.hahta1f9tAOOBjlq4QY62Z1LDDyEVscIt5uFoSGb13v15ME57uL5UrBW4EPHbHSWdPShJO3jUf28kxDhwiiUIggFKb7fzZKxWcIMNONjzPN4NFUY+Hy9iAbiY+R3+mVGeTeM.uf21eQw5lcsrogWA3UFfF4tgu0mo9L8txQEJdHB51DgXbv5sxo3ZKRBidP+CqxwmtSFvD+xkUxCBuX2ylMiVzEvQ+ps99iyxsaesPS1iQDXvzqw9bvgLle2T9L1RkNhVMX0gJobUtwWm3yiDAGgB6E6x6SmwQjPm+3LeQhkXcHsljo7hixJF0JULbdhElcfq7Qvh6VtGQ0Cc993g2n2cYYU8YbV14iThAADS4TU8.wKWYlhEm6qApFjNT4ucXLtXW6qEuSbJBprTqgRBm5f2IJOxuJIqg04EyZdUcDYQywap1mdHZvrtcmKTfvMNHwAdPsk8bF91JD9muTxxv7PXTl1Cmlvo8UBdTvmCA.jWbwcSs6CREkCB9CeVUs5hxV0TVE4CmJJb4st30+mA+pcWW.ENAaoSZoQb6OdiI6GwO8y+EBeOiykxZJAPvj5bWA8w7X5c1gKsZFpzQ3FdeKm3c5NpsYx9MJjSTVxgLfYzv+EX2IAp4jkqg0mO8rBZ8gyiNgpr6DqgwcZ.9vwxu+odqhknqUYCE0ZRNYcyEU8gPiHyCuSq4S4mbO0ecewXJdxQ8n0u.CFRoJDIHpeKr6qveXPmrAsBkoP4a2gKcd5OwzQCsgDorfDvPtRqi3CWVfJesS7UEWKm+hNtRXl.GYvT0iamf7sjoLaTRmDyiLer2I8vysQnnm8+F0Q062y4.kxH88QufxO8Uq5JEhxlnmFYX.re2Ct.2gRQ5pEb5RfPH+I8W2Z2.ylXO5HxyPWNAsEweb.fI43Ls0DK0W1+ElO6NntadP6KwrnkYosKag6LYRP4nE.42OwKwELci1+yZRt.qZHyMQAqcyunKrIg1WKUggNBvRULon+UbMUGwZNTgSSvGggskrHWsfTEWRqtT+NgHrQURLjLmpw90BpwGrb4s++R5.jS+2Nr0kYJZ0a2lYzrR3hvbqJWaJkys5km2shZwilYWnCTUurLvakJM0A77r.A9MbM28uw3nJx77NUy0NBbYHDlKhF87FeNRgfgJKJsQk8fp5NP8KaAzAwBzmXWYEwRzMfRSBrpaceWN7d2lcn5PIaEZGSCf2uJWe5BiKGp8.BhjSBl7DTlfGIhVw.AD3F1jKbIq0FHTd6h.faTY72RnxqJgFKMWoCurvVBQoePep96btqmrRpKXUuRb7D4koClTROemHvhNdPwlhHk5ZHpR3Z8IMWQLqGgwOdmYrR+zUGBZwne8cwFymXHDl8x02ryz7rmV8kqZ9Ds1gLNxsnfMVekAjC0SiqcRjBanKZVlE5YvPcJbi3aCag5gVwZQ5ARsoztGOxBM9tMm0HgRpjK9RaBo9smAvc5kYyOrwBEgvGkSBCzDGNrKprPFVjG6arQ.16.V6BpsYvWCKkpmP+8z2CCUxk+zTzSJDvMS6XfL+X8A2ZydNRGOjQ0.+h4svXDX1nQnjUMbw9HokgAlnXkz5mYgs+G6FDh06RcjDqc1s9odbMwWAC3LLfE+bux5vK8KO1JISsMPfvGRRzLJ9EO48ZDhWQKFwaizjofUWD7m2xs1QXcbvIcka.2LZYy71YVoIQq6pmSziOq+nJR2WpU4QdVpbrduo3nHZY4AxHU9Nasnw7Zu9wDqq46iqSCO+pvVcrbaDDszc2tyfJc7qwG8AQzFNhyd.gCDUYwY14yH8nMF3IddfVtvUzrEP7eZSD0u+3lMXqo4d3ejLfNoYgjgVhpBWvxNIAB4Ez5lOew.0W7dTbgv4.I0QOmuggpZOj5oHzgTijJaA..kEanjY1aKTt6Lx5Qlu.PcGLw8c7S5iwHNmX2VJcI6jLwPtz0iS2GkZt6VuCjMdLfHYmYYbl.p+XdCU0oLHVq1WLotF4Ci9g1f.yM+kwJZ+gN.ug15gslVoLrGcQSGx8JKNxSZnu+OEAKKDRz5azaoI5NnN+rJK.aeQlWovPARMFZ8+PPpvzCRqGiIR7nLGk6Qu+xAmD.RLfxUXo6Zik+WwXho3cyFF2oxt36dI2DUImqjjqDn+Tv6yNmqv0.YH.uyeCRKrS0vBDSkxrtPvIbUWP3C.sUAB2LOBNgc2YEwYWFNrUdjd.OSFekB0pwtzkC0wyqGfuEHogHl5mBHVaMkz5AhwL+OgkpR7kqtBWdy9CG5ZUou+lkxl33sc3lRz4kZK5AwvN7B4LQf2tshU5KACTJ3Ht8dTyJrGjKyyrch6DUuS7s11uQBdpR.6IPPg4sLnSCKcKNgg11icAuSjw497YBHW62rwTRExOAEW9nN4nJg8hjHzqduEArvPYIPqWvY3VRhJZ99PEbJCZZAoKajyZLJdI0vVxo95DnOzuQuB7YTNSwul.G4wiOT8BukeC29M.d8fMduqmG2Pe3IU4JJhZ5c3QpIAbZ4WTn9QZMRwkDdxeKLWuIW3Jy5+9wkHLP4SRNKs4BX2DoONmDcvSMRF1zyGVqPTOUXXXlMAUBGcKIjYus2J3Ly6+NPQO64MhIj2aRf56DWbD1OVnMFRthj2igI0qgm1itIhH1I9IziEufcRiVxoebJ0btumwFK6CwVPHWNkZ27cbDNiTmFtVp6Wkik9Hglf+48Zb7K2P5bMUGE2mDtJkWnxPvcZLkH5cPzMOlMW6JaWlKZqHx0OC4iPe4CGsv3BhOYo6LKXjwHVhQEYiDWB+NHWSdrL2XOyczGaWZB8hiia0pp5yjJzLBt4wieeSga2Hw0pyrYePCsRd3SJtpUNxoT4+zrUzt.vYv50ywvioN7lH8sN60mrPhMmKxcN0I8UffOY0QMxdlQ8Ymb7YBBiU6B5FBGmYP15AMrd7l3+PIhaAcnmYqErvh1NB01OcT8uoXUYt.D2nA8NRrlPqzW6l8EAAOf7kiBsUNXCz6zcP+dCTB350UZPwMDqgcEfbWGBXUdFmuX3CzDZufAMTKo7bYhBbWhodb34dTpRuehUEotJqYX956GkrP8T6.Q7McZwI.RjpsRrsfvaKge1T.ydfGplj1QnAHYeW0yo7Ws3nMbUuYyz9To367vx0nXBgxld5qyUoRFuvy.NWOSpnqvARqUJQ1JxXWNHE478lgrV2y.X75Ib0hZVzu3fS05Fq2abPAzjDWUKuOOgiv7zdLdw8GUP6i9PmOAYTXOycuMF396CqS7pVYD3dKYIXbojXUv6sxbAaahwTkB1C5+eYaQd00P8Ej60tzqLM2H.64eRwVcxDfCaa3DwiS8qvCvCRVZ8fh7DD5BZmeROd.+J83yGjk5x+Z4WKru+SulMcA6zEuQQX3clVto0SNow+.M0GvxD8o5nyKv4z5O5n9B4t+9gG1PbhA0W6zTIE1tUm1fw+Irj0YKY08aYwcEXJ9GzBWEn6O+l5fPCBQYOrh8NOYOmK4OlXacnXJBM6Y0vck8lrP1HPcMBxpu.yAHe0oqpB93W9tIDv2R4qVt2qMtmoFersnoorMxpeQk53rwdQqge4y45AXQQIaQ3NFuVgHqybX.lFwncHjSJbBX1wBZzgVMySv1SmyF0YI+HscuhpkE67FvgPHuOJoq5ebDaRQet5UDhO9.ngiGOkkkjddjYu+Oo9CiIl3bIbptnMhmhR1yU.En19YeK0qBh3BgxpDfxdJECZAqyDbiYq6rGFGFY37Scx0JfcNnBkAkXVaZmHQ69fHUifw6SeIXpPu+Zm0+ZhdElQZrUNYydehXHYTRjQJIEVRabMvDTCBiHK8ALqvlaeL0DTBIWpk2P+8aH4CJPU7cyXb9Pm+Fnmt3E62TZIsk3mzgxyfYac6sbgBWaaK5nd8JaRX0FITV+23msWFCpfDllWBiqdI.MHQaPzQqKh8aZa26OHqxBz32nm.u4Z.eoSReNZbPgYWm3oyGPhPGXALpMf08t8FePbmAsLgXBC6QIFlWIeX8hh0SQNE1W4Zx1Oyb74vJqiSPCXfLm6xwnqUhqHckiZPQXZ+Nm12X6CaAa2737w2pbzeRYZ+nrVt7UoitU5jq8LWcljwkTcaBtn+h4.V4X9h0ETWd9meCxspU86cX+FHe1BemwvqAk0Zn1.3neoaocfsMAR6vMt8aB.0WQIWttsHXlMaxT.nw29ujcDySpjmAha6c+FO+NkcIuK0UAmtKTGxplV0FIvTacqyxAOsPLQ15VCqyCF8CSe1WsyeLGEwVU01IDOXH9HY0R2RA5ZsMIftIG3r+snnVPAHTyE.4odBqOHYh1oK2KQ0+SplV3TIeNvJ3uA9RhAFawQSCqQMgUkGoijOEzWJVCUI9fTsWVNavdSqyQSdAoZTDvMDqLapc0Zog3TbeMmxfiBUiSSlIiT7Rd+L1VZF642h0EeEuai99Q.0EY3EFII0K8LkSr4PbeFe1otYJaZs+wxR4BSeSrag6QoPxBSSuLHU9TTTNl53jZwMgTv0MqRj555pLn8Lt0wbpSHhyaOkrbBma70bBzDUtvOinIbVMnRUkJgcQMrbMTcQMrQ5uWDIdsPliJUzBCY1ZjE3EHiMkzKPHOwGVO4g9EPzOuM90JX5bGpgyyNSetA9gqkB1Ik7kUakLpslHDUVfO.CPvuSB3pHOJcwL16DWrpBLyuyAY9axUylnt5JxWSaqa7bCdN+BNsggI4EBWmaq1WQuOK2HfkkaQGBFjnXL9C157ooUyPaNPQYMi7RNwHCEwOOOnrew7GPBbOxonmVHt7gKijXpG8+2rI3B4lFLFAG3f9Cd.kp7JgvWrGDj3HzHHdWm9DSImkvhZoHpiSTJBe.EB8T8SwQfABpaDYfXmPbMRpgF6QXrKMewMfoRQS6lu.bV3wD.8VVy3wOPBz4Nsl8T.rSQ.+2OtPn9AZUlzrOcXIhcEeRlUcWhpeE8.yuEFc1S6.lCHFxk543TGDqzncPNYUfrJL8I3VBKKSiP99PjO6V0bNLKIKUuZs.5Y9g3785NaXKC6TpK5EpKAIqjDblMix0ifEvFatMIKTL1ePXe6VU5ELTxedipB0DX7MemHXdeQsYy7CHBtFeCc3FvKwoE1AEuXGXNkOC1jl.Bgu.knGYyQ06Kme42q01lhUZ4oIQNnYlG+jynRbi3iOI3LyUzhzhj2zQQHN3iqfwzcouPGg6SeD4gS0aNbiOHOj5m6Db2Ej1aX0da9IxItg2P9+ebEQfqVxiHw5bm8VvEx11Gqo+sVrUSp+NazVIgReRCG5mhTVAUMJPF8hbVUvn1XvAuRpLJN.EKZX2UtImH5LEqdt9+cDnNRrYmYKmG.l2p8hvFKVXaJE9vvfxr1b7MDOEi2OUbNI3IHGQ6Uzn.OASXvz.GTbBxCvpylE2vVUl.6X+y497f3dglJ6kdkIx+7gsLbANTg0MYdbFT2YsLZ4yNMAE9pnr9N494rZAxfIHrHwoOc+FLZsGdg44Nn3R1.s.lJSHe5nUIEoe3GJKhMckpqFLNtKW.Am6CB03NVO1N063LDFmgAzR.A3KGjbFEFY3.ruwlVm3S1.0ob2RM4aFl3B.Ddl7fEWBuq7T2Snwo1WBvjS9YuCCcXqM6kGmZsBKbiTwKZ8uIZmrVqfKMyjbZHI09vPcy7IK5dp0J6m6iGKQAxNJAtYanI9uQh7VrEA3Vr6V3WNaixcC+Y7sKTaZLXoCOyjleej8a0z8QrcPJSub0hUl1cJGRtBNwFbmCl1LsaCr9N4EsJQCuLteiU7xgP3Ae8nU5JvEh67S3JrixFruvOv2AD+bcPnsXHl1n77oBgpFV2WoGuOnfPylVlK4e54rb8784oCarFgolqgpgWb4bkW.qEHZzQtxggeV4nGg3bqVT7QNAGZzBQpg2ITcCjhxD9zQrf8ukfwKUCvhhfOPeDI31z1mU1To3Zt8dXYGa8BI+XBGf.FFfwV0a7Ke4F4PgAFXRFQtClgx5+jWMCAwwUuZRFb4sNs5beDAayPh691cbySdK523YGU2LDhH6B3IBYCDhRpRvY5bMTZYRZ3b9reSVKdWSggRgm4NJtQLxf2WtZjyESVuLJ3NF.WPOLTxLmsVFYOF21ZLfghTC+dSyuMLL0RWhDydmz3ui9lk3m+bOuCD3DpawzJyiN9pqgKiO4jcjQRyA1lR4GSzM9tUFESYfb3qiHj.9OFZKWwOiuybd.AJHBZaAjTsZaSUFzukfT2jUtvOyX.5s+TGF5UgNBimONAq4dDkuxOuxUN.NLl747erNAt3mQOcDZOXsOlwoHu3rvbt4xNl8m3hMdShS5qEaAU1m4cLr9M4KMi6L3sW9RS2dHwDiNI+8RpaywnZOgpvOvQlo7j1r.3PykigsPQknU1v8IQneqcA5kbVHokkutqE0ohG5ZbUwCe1hMxJFu5AtDN3pbzCRzV11VycKEgByyQLG62lo8fsMh9.cRsXrGHmlkcVOmohU3BczAOvkYE3yQvNpyVUTHMZhK+.ADkt47JdWUuO+I9cTfPjkHyqTRSTGILTlu0d6Swg4WdDtCwDA+JZ7uWibwo+Juidjis.WIkyKQFSe9OIe1aqHXmTs5+H5kJhgaCb70BWsKFD.T43LVq1qrt5k8+bU50MkLcOqeLpUUJgG8oAwm.adA7HXeggH83FZKv0b2pzWsG8aSjz072BBWig55MUHPRLOuEwPuN7dHoZ9dlGiQi7HYpd5oyHcxUspDYtJuZrtC17KnbSKnMzD96vgfisz29tViGPMuly2sgwSTiYUZAnEpMFq5oZ+9MgcojiqU4Gnnko7R8YQ78AwwWNNPOEbpr3Y8uNk8iwBZ9DD1A7mbxR.+33UcawbaZbXsQvaqhokE7jQuiQAb1W0++IhEuZphtMkCJ11VFDtuFT.yFe+3BJQC.2lRZx79TDDBqUzTyZCW5XU..GBKGn4EXj24r+owztqbEsCZqGXJd3w9goK.bYIExk7T44PNBEyDh0x0lTw5GkGShU4JbZfpF+zqpDA3.CvSHjLpGTPjRY.fLA+An5rOwxYeh6XDTm5yO1Yzr+fAiYwrVEb9WfIQURrqmj6DAQ3ck50vE4x8kvxkPouZjBeC5Y3rfokCqJ6olzh94l.JUeEg9RSfOz3OTBMsmg.GLM1LK48GY9IDxHRFhThiKH3jYd9LcZt.CFNam6JtVQDuY0pggz++iSYY+g+6UYdpnIs3KUEJeBZSal7YusS4EGyFoCyxcBrys7RFMVZj.VK79Jf4VODMqosXblg6gFT89WS7.OHLkO2J5L1Prf5M.kQqEOiuNT5zO3aLj9pB92gBou7wJAYg9cBWTQYT6S10YAtR58VQz4j7oyZaz4jGwFvUfyY34ZbWgcp8Z8RkL811Gu2N+rWiDhAoa+U8TXShdEtKr386W1V.KJVT6adkJME7JOA8CQIguUewRPV80k0ys40RJqlKowrSZ5uA6xfV71MTzplXUpaasR.PnPnqhjJ2U5KSxNbBk5mnIcKdivF9PVVzL0TpQMUHef8w8sXc6S6xg+4C94VCY06kvtlwMYuzMawFHWs7e6yRGIrYIQXSAJjiZzE3EHGC26cOTqKkbaeY7XWI+p+MiitpJcTMQqUPbiPPe4H9qS6kJDgFcPKCD+EBOiYd1fVoSElqIZozJfCjF+41CIAwfiueIazakTfHsEkehXpirR3x9QkDa2Kld5kzHnQsPCpq0C8ST5e2AfaMomLZSceDcHYH56q7QalDr4ltg085dCSpCypAxjIMPm1TafS8092AhD+CkO.0pdGwtQ94MBJjosJzkK.8iUXmSKRS4B7QR3hfkZ52eCtfiNJiRR68gy0t9M3ceuhu2uN0h0ohRX6eKV9eT6LobB.VeqSxGggvTLZXM8aQzJwcsOfdzlb+ApOOhBFEFgXgoRzj3MULbEjKMPbt6WV95mvTVVJ8wjnQv0Xe9lu58yuZS.lJi7s0uGlVO0gmsK3JUTXPlgXflBtDQ8EEP5x4PITC4VMQAvLi3Bbl3an3mcWRfOENDnSE8rbRdDDntmVyMXn+Jv6t6HqULzOvXILuCNIbx67b9AH8SewhJkJIkmlV5Dlfa6L+Fev75b9k9oDz9tndfnsUCS0TP9u5IDiVh2NRfBIDXFrrE76snsZA50KpUaP5PGgUoJfw3Bogspu8wAIJv8q.oqUhyqYOd9wncmzSyqM3dIPtzenH0dvIiAOS2UBEfz1zksQSyhfFHMbo.ESqSsdeZv5WRiLJRiX9An.gIdm.U08lpv8ER9yUbx7SFS5GKuYzlJPbXvIRe08+pZDW8yBLfAGDWlHEsI+MoUsi6iiOuzrzFrj0q3cXvCKgaZZWLzwxR4kte+0RRSsJavQhmaBJdAvMu9fkvIt3vct6f3qpPzkvrrmzEoD.fFHNg9Y3EiW4xt2+d4Wah14rW+ySRA3mYxVVk1p+4Nyb4Gt50gEvpYQGRa7lPsNb2h6lgPIJ1La2F6De5Gn+cyKI2U2HPZRb9WsEJ+LIejvJZJRlflVl07NZmixMY1na9MY+v5Z3cNwwPgP39IxmGrgMVa.ZyWPLw5r1t5cCbQ0JMnc.vUIAcF5ATaJpcXDZrIs49B891HZMEFVhaL8HNW2EvDbZkUgZilnuuXmFQVrBb2CLivWMemDZocTU3PalSrkVVqOEdIBEEG2.FFKRNl0IOuCCaonULgrMWcaOGIs9JXRMWEXo4zYEKNYLSCjKsxaj+ED7oFyIGa5xioXhIXisFHzcPzxwdaI4VFFV+qLAQ5Os1kNihMRxsIcGlUlHykOY6GxY+WXu4wB1BS8moJbR9WO27OV7kpg8JdyyEe9VuYjEhi9TQXr0a34kd+M.Whwrl+BmhFulMyu7lzvE+O6UjVrw1U+T9I8pcuPw9vSQpcwroM0qA1DebzGWGihLNENUrk6W9CEGmzzC9KqDlwlLKoqaTna8hZ5Axe+UhenCONECPHTjBGZ4DG2xjv1Eygj.akwMIpWJ1aHeGYmG43UG3rmStXppyYgVFpOBA3qSzzdqSRqYR9SLMcO5DcLO8cTQTMephBTYxm4DxH62J+T4e4HDdJ60v6Urtdx.2qZ04K4L.JV8midW55W0WsBdyAl1vC.U4pKCJ5LLW8Gd0.b9HKgS5rdQGez0Bo8qPODWkCrZv0aPs0VmxVxzVw5Jm1SVLoJZt3wphLu4BA4GGVOVU7gXf1X8CGKoiiIvppIM593qHXyhOBiibocgpLUrVuIssPsERLvtxrTsuqV7R85ydY+Rpnp72FYELzUABcodpi5rTnEKuHQpjrOe14WwZ9cNC+8IIYy125SRjmw.au3lM4hzbNn5FhhV5v97J+aCB3gkt1ML6HXyQJmwbWZWqHbqHpL+aQ9dKho27jl8aCPe5G.twFDA5uvKnCVZZqxKj16jR6aI+CbGY0zJ3xTFnqk348qHafqcLPLYION6TCDSKiGtHsFrWg8kLwnXWGHSgDBPpZ.lP6yXVgPNRJ2rv8jl26IJ5M5CY+o1KyiaELPBNdr49LPhi4Tx7R1BcCUfb6x65FDKy2QTL1oOS+QlBwny0YgsZJTswhYxqOvLH9qGEZCaoHpdq0HuurtNwdMUJQy2GAi+KgXASQj4LvLk4PMXBC8VycaoF0SU1X+7VVL1lhL5AQ+HOG7+YV16tQYsO4v2FQF2cJbLhVqsh.uk0geZhKwMii3U5kaPT19CA31EbmPut75UcrAx66vFX7KpcRjOXb2Ba0Q7o7QybxYYvyzWTDzBFNWmwSnkHtMuR5pGumiN9U2Bn48GSuF.JnTGElBYkyRUZ3XMQlv+ABTYxFQAIKRE0QMF9xqxiyyb2cGgwZwXG7b1kMf4YbEu7eoDW5qn2xdxAZkQMdvnFl3AwF8T7jmbyvsiuK56mX0spEATJmo3uX9DKmWRPFMc8zbFAKu6uwu9pNfnWWUt9Wxq8dC.XiCUTbRNxDIsn6qqCDQVaEExkX5hTJ4B+Yj2WUO9lS3xDfOt79QUr3Ry4hEz+uxxOIkmND8S0aDB4jcFmL7HBATL429zQkRER.5jtUu6Dw9QdC8RBFNfCH5zQ9+dRMmOwqY01CU8X7i+I.If1uqwDH7EX+dxXVcmO71..NJXaeaeenH7xSoo9JQYuomDzHPs7HxlzTgPzo9prDF0T0Fh9N0H2RHZinNnZ4Sa27IQ7B+CZq2qLN1UbYsaaaL4qrHbhnZ1+ywpGWOLK0C00yr4h.2fn3rZLc3OrsKuM4sZeSTSMtQ1l3h9Q9z31ADy.jJmtUhO8xp397NbPFLWkS.3MhQQs1646wo6VKYwUGVChTwObbVjDyKSTGRLvGemJpaXMtQ75Vsj24SdSTLxQzLtwEMlQglygk4WjnzUmS9Bw3scQmqDH1B5e8ho69QK3WenO8BMNJkenePyxkjKQm+uYmGZLiG.k.mcg+IBBKcSUoNVcbKJb1x8JsMyAYYyq7wY8KmXsGbUwgcYfCxbjSD4mQOm2G4n+UbBFhAJMfFqMZAbwqFDXshOl4Xi7UxioSQ3vpPg0xrTeDFHXSJIf6.auH7MwGGcPcsMltARKlUMmYv8LtcBPFzwlsrDQmsTIiNqhzp3cFNYpqjOASNTU8nbqB23VxuvJp5e1HWi1R6yZSk3Rxz7uTOCQ1GeEWsplTtfJOqC8YAk9lP9OM8Q0xqP1xe0P3CInJONEOSmaR6AZ271s8HV+PffCyFkoi00Fntix1Q9Q2uIVXz4Tx4C2Ys9qu6+PAtyNtKgBQwnWeVPQxPtJHE9lCB0.nNPDR7EJL8mSi9.5JDiBdeygtLtwC8XCP.eXJTojFcOMJXjiCNMro+Ar9cKPo16bet0tZe.MphRixSKfnWVUiF0AtPRLoiVU26CZIjFzp7FOb2c.+NwVtdAcUF1WbVAuoCrLwi00MrxHUMQW37NwBSuj1qVyhSEVuYsT4ipem2lWNz+nbhVG5Bvk7wQk6aSXJCs48UihufzCN5yaENwsJg8lbQm6ZzJBGh0BtgeZnT9LDSHdA3XeSSy.KVBKG1ENd8FpxlidURxP4qVn9ZgOy6Sldz9Mdej.RyQp8Upi4+Mqcqo4UZNt0dJeGvJS+c4H7Pqo7L0GdUfruM2bVT9cj+XSM23YI2H+hbXIrtSSGktdBKqU4q9Njk.jzGIeO09vnvtszCOX6UYbAXaXpHjf8c8yXMgJmEI2DNgGiSNtznf78CMPsFZwWFN1pGrKQMob8haq.FAM4f18ANz.gumzw+8TwEYcW+60GIOFw48IxG6UJ82UmmgbCmHDmy0zzVzgAuT30cW54UEKrckyZ7QAa5rvsoL1sQfqW30TNzxvXNYot8LeGp7mnGPet3TyvNwO42ILEZ4CsBuQSSSUydPn4WzPkGfIz4ca.hlchZF1jIAMpaBMK9dV9NF+Lb3.iszpQcy0p9S4YxHKQCmDZSQs6resQOMLUhOzpAF1GVZhEoj2OMO51VSZ0D4wFUM1ZX0b4jwg13IG5n+tuapZwmkTMPvfGemb2IeWMcfJ2vMEWhIxq29qv2LUbraUEPJjhfDuZ2MDEYZ45fV3qgJh4MRiGZH.nJ3KuvoCgI3OpuwsznGDXMwHIPZY2KvknXfvFAw2snQqpp82FKSQoql4PAwOMha6crBn7PQ9n5Qne.y5jdgIHDH9ih2bLloKHMrve+6gaACzIjDrTCB.ymNgk6kVNMgpzxBUkEKUjtxr1.u++5AlEehAl30aML24amFYsCeCzEJvHmx4DOSIMWjPbCImG+9lsCwSWT3z+yVa6h70L1TSSrKIlJaIyf6WTKLoNBchFsK59KnfS6HE3On3qg4.05Y066Fo4E+6Hf7lA6rg4+iL8hHoNBujtIGTCxmrNN7VrzKBJjfwPC.FWZbaH7o3h.K69xh+JNTctq6TIuptJO8id3K2LGTynxUoQlSD2IAdct.dI.bRYOatbcySxmn54VkgR5z3LxLsv+qUrYhGAK7p3DV7u+jXFLyANuS0mLSV0fotRHil+EcUg8Q328qlHUze0.3gMO.PpRAzii.q7avL0WIjSyowx.vkUM+R7tGGuv2GI9HFaNmW3JpMTdkk.W4zWW+wduyIRpIeHnO5h2ASFBTowsgjuz+cd1JCukJHgA4xw9061TmcADjltoQ1MmgMFLmldhwVoIG71Gi7MqZa23Y4oBPAfu0.Lp16BTbMEEl1WV8GhqUfhPvv4j+YIgPXHG0FYEFIHWy78OY+Eni5R9Ur7V5P8dWSUXxSQSykfkaFfDhShzdmv1SLKralkiPsCoSlXMl4FOzFknuf2FJxdl01Fq58wbqVl5e2KCKDdLwpMgVHDm0OYl33ZtoRBAC41VxbId0ZISlNXK7681BWlx0.eRbk3CgFkpnRWBB8pz+.TQZul8.Q0exuJGvCDg9cPGOTAQHo2YPM3lJfws7qyQ0hEU1GaiU6gz.gx5Igg+kRgR6mGB2JUdbLYPiD.MgJvJ.QUKNVhVOFuchUVTVG0qW5AjDsa7L9cnC7fKGYm8jRlBWj5g.eUSwLZ9dX3rQO+yP2cAF4I.ObVO7YhVheSEJ0+7hztVnDcfXOzabQQEfZG6fvghqWj2ur3xDEKlk+tB.lQbgNuiA2Ea4SdsYZwW.Wh9+pXK4scoZoLIAJM0zPcLd0cDzBERfIZD8cMn0evJ9wKUgxrI8DTxUxWnJz+WqOgIRBNbFyiFQIlsR.XfHhQUGbbCqq6DEqZ7jIvbeOx8OKPTsKoNrQ1SSX4E6n+5Pz0UkdESf0KX.xSCUF0uyESreQbuO+GGM51NlxbYa97vfvFjfSdpBQvPlE16SiseEfmd9KWzhlNdk2g2W9urWoV2gi+JZ4WXPpz6L+0LXPB29WdAnLVtYjxdgr6vVMeVARt184D3+JnJ+9vUIpkQS5T3oqMkGlNykbuH9obv8+3ZinpRcMpMdPwqXA97KSUsVIGm6sbnyorRfyMSxrE67ju7ijLevqJnQSPqSBKIstT7OqfEq6HIq14tPwTwyYxSeXO7JXBtea9y2n53ieHFjvS1E4PW3mcHi0alM0rHSgLNrPL4XxGa+lj7ufGcIsEH8po+eDKvUXAtapD5mLYcAmyny450w1kTs.T02qJa+ZK5Mg1L30HOn8oyCzdsR2rXvMhSqEiMi3W6aNT7GjGha4zasTi.wH37nYO0H1nYOU77kQeTms9W6Hl6FZU2FTe9QfQx3kby77.umRaetzMD0Iy9ikBLsSNQs7OGRFXXLN3EnQbFg2towKg4IvFKWeCn68h3rR8HdoWCw6ZwvzYFRmkKpgSgiAfRuGC0XF6lLMGnjr+HkSMezxlAyxbFP7H2+PeSOcT+bj.Bd9yzdk9lcV2kIlgfu6JabxrfCXDwOayWx+mwE7oDnFmxE1eHV305Tryuh5fQfYWYOoOZ3A9NlnHDKYdpXRoLCheiu415znsFw6MvjOIpWshbJMnR0ALTUjv9G1FBKwOLj.23ThO3xrlkYmysJNYoDj9vuxGb5NyAJiLXzDRfWbzto5dAn4uqIZhrdXdnl4zv7DkA19NsTiyULw1rD4kClJLRGnEPVoeEgcUEDK.Ax46IR6tp9tFwU7vsTFPXZHmZO6O3T3kVPsF0IYXyv7+wT566edbMRJN0IKVgrMMmIRr.0dUv3A7F+6SbHqB983dv8lnYABdbKcpK6N529pxm0uQBtifKJrtSq.xTT9FihAxSqwvY84ncyH5WFloCk0P4j9swUtYZnxLxwbfbhRdpVfHkYiMyRWFb0tTYI3xjSICUi7wHfkMUWiXS2236BMKhe+pl7axiGeOTuoCK.acpaMSvxBjNlw4RGHdjGLta3xqySvcrmeebRPsjhbMF0q4tmz2WJfY3lZDoK.wg4zHyNwRwzvmlPRx0xNagtFbvj66zX8JUo+1xjuFODuHjSUnt0BQkP2Bk6MQLfzNrK3WLR+zlQ6xVyMchxK1zcxsQ1FBqzhGMgzMcyjR9WuV0eO3I0URPj7SFUHeENr4LhtGDSJ.KvcCxL6yNUUbHkKSSJQzBnL7X2lLnUlagCmB8uEG5+wqmjGY6agQXbx9Mn+JKYJv3sHYrk5HD997Jc8HCpTvIX8hHY7P3FpICGtv+Ic2jO9FlDCQpokpQzca6yKv0KkOjff5iG2lI4IFEiYOImEMdEUm3QKNgantUpOdhG6cQPUO2j.VYFsIyR98w8uQAoLutRypaVEkbmQUl7en+6nV8Q6Ni1LLD37QYNo.HP60rn4ui25AGrRpNqF9TrztrOjIUkwWccGJN+F5Kf5dcqVrEeQnORZzPsApVZgLPMBM8ikArzQFwGqRAL8qvDZU7lHYB89novHjDh7Wgmk5wMwNozh6JxHIomryVEWekhjSxU8LbMuY+5K5wiQeVb9W5.41eZgG9x48PXMdgeO806icgMkWnESu4cXL2r5wutPiQpA7sbklKy6fHJS9mad6Bq6hGijDnp.1yCQd43TWRdhqke39WD41oNj35BNAi6Wwh12zlNm2vof07AIZUnEc+ezfeDhhnSoiuTLC1ksSotD5pmwFKmbtkt3OGrsVYcAqFHWzXbgU63bKn8POktEnQsmGr+kN9Vwb7zYBFQXYbLDMgPzTf0XTazRlGrOWDFv5g3WQjc.fpK4PQtHpFHpL0g704meFE5Z.WBrWm78ylJx2eu8vWnOVvXJMQJg3mza7F2oc5nILIXohqch.lC4Sn8FRRwy0ciXORPuslJOkNqHSv7dFqjygtBw+n47pHlHZaO04SIWYrVvWNwsX2V9bhRTJVulAQfQ6de6LdFfgMv+A5UwIjEhREjx2eyjazF0Ez8gLXjqA+WPAefnzwmIwh23OeJLvFv1CvBOvdcb7JJJxYBee7WOPA0Wuc+vHwNyUhetKSU8gufzFJpOMXzTprNggzF+WNXvIQOHe5KqR34LWkpgJJ2eLsVgT1g2tjjXQ2whXCk9JTs+FNBgjvnKX49L8cmiNx6p9ml9YmN4fWdi+sgNAjF+FVC4QX39bjNnfRtgXMEPRSpW4W1eobOFnRNIJ0p.BKAof0kYzKHMopK8K8BqEx+xnhc.M+XS4FpXqnWDzq7ZJO6rs4jxYvJbOX0C5ejS0VMZIp9eg94V2.WCu2IeZZnCSWMVNDzrRWnzI5asiqV5eesyLPBHheSqQoeHFVHT0tKFe35S6lflkXgz4L9mTFXybsjAqdyttPg9.inqB2fufffEiCMzJLb+HhZmhqFa1VGG8KPnYuIibS9Oc.JC3oCl+UYljNZM8qe7yKvOrmZVnSaRe1fyZarFF9KR+UvcVxRzjk.5Y+ZlsOdzzgeRvws0w0uXvSjqA8+KTxd1JnkQq9z1fwmStbASghfUWnCUIg7ZWopxkFfTG+wZBjynxtmaoVRSGcc6H5JY4BfSAnaAagpggIoba+IqJAXBYjt+71ycwdUeVatWco.iMSzrimHB8m0f3xHo.K1xvnbsGquJxykNjw26w1a800ukikIjyT8Q+AbfQSq0fWervOcluUF0KyhMrGPwkgmUlXBGYiWIJ3BLS8wdZZ2s.SBgP1Y1Hm4L2mGXvlyc+mfs0n.Ue04Th4YtiwTjwJnJ1953LVg+YqFE7zyBjtZLnebEn7ukAv6HOEnX5wStmwwKFwYWYNPlizCmVViVrNo0fTD2.qLJ+8m3tGQ4nh1uEjojUXptijVV5oldSGL6sJo2xMgnDTNugUDBNpTe2byt.nJhs2cU4o2m1c.LhfNLcj9lBeZx+olRmuvVZJoMHbKLePSbuiD1MBgAoXgKPW77L.mTc9lpikesH4fTF4cOVG1MnnPDI502f+1AL3FuFKRhIurQSjfDnSjKOZK+HTp3LuCMY1RVdPp6HHCb91H3v+R9TilMZsTn796Wwul6jsAKoQtbh.Fjd5076m81BOG7lzi4kaGxsh9gaj5K3wNcujTbXC1P6cL7AT2MR2r9RwO7IgEKh1aBqb+rPhADZMogUU2fxhU.tRC+dUNR89gWtugBx9iE5Sn1xsKLrnpBd+bgFYBc088F6mgoxCX1CxNGji42vSXNs0kGWFrC.Z4nlVXu.bhMn71hccEIS+kUMBBO5sgLxn4CgnTTu37mVuYy3L3rlX9YDncwUfZwCNlT3SCJoSBBUGPj3nzmMfbO7jg3mpaj.ZgRMTcBSa2aAexEKinSHWwdciLJFqI0p4ixveoPvCuHVn.kK3ScxD0oYdRm4BBPoSdZPQr8j3BIj3ucb.vz3AyixHo1LFLmZs9cWXy0OmnT9UWwP85XILKFsFU1i8DG6VJybSZUPGo.f6HAyNIWCbfX3h6zrfl3TaPV5I19opsQHzzSmL0pDBmTdGkl4Sa4pJxJ.46bigPRgxI8xk1NLOpkyjfG1Pi.Wsaop+V67T0wtiknzUJ8mvSJ2m87oeeH9pv83WyoMvS+admbFh5QicXsuLqcfGfIvBmQVfED1ZRhejR1cEJKLmcUIXGk5znfQQoikRJFNzfngSX4bLGN95dZfXHfOEcMAUztTgfBGiSV1vlwn1OEZzAiyDfHbcCfMEgCQwRsvgLxnO+lJ2Y1oCNpBHE0.JHIMGtsKUvNf9ccSz6zgy+g+f.I7b8LRHthzjKdI3C1mVVe4XnjncpVUpARk+nwSXdAWkQjofwN1uTINLazn.tr1uycoD48cuAe+ijiq0VtRPHmF++ox2wBKDeFI5U3HSI9CPu34mly8bANjjJi6TjwgaO+i6UWtH5ryv7iL2RzqVpKoEn3IcK1GXPrRIi1WPnnChj9toxs2rsz07B9WoNOnTz4b1CxenYWXRF782wkUXUPAIwFcVGrUHtrMgWDBZtTicLs3IXkwTtBXiloSPevyi7XCWStG1bBy+I0+ZAiGzz04VF68d2Zm0ILitrVOVgM6imfK1vmDx9UWzWyWaqMXGg1cK6p7kVagNEQLMi0IQQFD8GJYnBlByTloUunUwDyRcN32snCNslYJ3FlAlLnPE0chX2MPq6OJ.CIuQb2hoBoPxvrBfULKiHVHM2UKwWquJnqWIhOhaohSiuA6N9MM0fnkJuEUO7bmBxGojsaX1tppbeGmk.P.y3zwz.bNk.osbebvzPxwCURPqn01kvQIuZKUB51C+hbKLugK8Cd7pRbNERE8TApDUuY8IlEIrsppvpUM0o.eAr1E+Qr8O9iliybbCnJa0Cc5DY8oM0fSQ1cVP4uZmr.Vqsv0BvgQ1apGA50cKEluYEgeGsYuE+WaKctbehkk+j4ZOBtdxcqY5QZ+4VopzSg3yTQPr9ldbodtyESLJ412XWmwqBI88F.3t3Vfh0EiCQomluNj.bs0YIwsd63tBKtsI6x7e1I39e9cufjJO864GjX1PVXkEEfO2MktjB71peJkpU8vdmzFfrcEZ8tel5lFy4tp43wa3OqKSfpvr.18X9ZmFNgO0snFtCEG.4hgm0FEPUskFU00BOIGxyeDyhse0NNh6Ox4cdfkNNF7PGRmexnySSfK31R1meXZhB4Q6XDUNsOf2720o87EtLknsGIR0PhebT5cZbs5GIi3gYlgBwdBoPY+Bg1rZR3BlJLXbjbz2T7koMwm5+wW8YC1d6DRcSzz6sHrH+noJgGM9.fXRHDkAfbuDl9MaHNXaGHbpoDrJXQwBBQjNRy1XOSauTFcCkHGzXmqDb+xNaiey8yLJsIhvExSwxKsUzdk8iPi52jZYDHxoeQD.yHr5uLpterk2BOJAKH.JfDzAuP2dfSIBp.1ZzTwec1ILhL.ey1EKrv+mS8kbI5rh0gubHjoVDathuiTtZYKXzVOv3rQXWaSOHB46dLcTf.RcP9dFurRV0Xkn1dQukDt5VmIH1o23PdCxgi87x9sT8rTMzuKmchjx3HlCrzTVMSVEpDwrOpYlV0NRF5m8OLWHcDBHLGgIkR6shKErR+.VF3CuT3goPf.mfzAMexTv+elvWfNRaiy97lo4sbVDEewBQKYck14+wPUfEU7g7JYDPxlnDcpAwg8jbR7vZwGqF4sGKKZNIrsM0D+I6fcISUyNbXSx.qL4sZzuRqgENosOYZlUJLNJb9e1NVbDWuMj1KV4IQlvO5vAUoIiXZjhpHL78QS79uePVNq5Be98qFmTg0M9QEk.fMM6estIHhbqW1mCel9wzVge3hnSobCLabxhpTsA2Y9a.bieiFR1vF.RtUN0ivKP2UnBNmO0R3M3mBlEL2T+zJeuA8StsYEwt5XMoZZSfnth6zdKYqR8qaQEDK4Mz8kHOYRN79o++zu53Ff7s7JHfiF51Qkih4iqdrY9hISpmTHFJsYkhl5KRrRst4Cmuwyo0MM0Ve85M2kqmlnp0Mrm7GBnfT5AVcMaAhHYYAVTpjx7zl+yQBTQf5ugM7RLvPZFi1M7fTX9yJDMU4NZm14QZA3zvjrZBDOW+RwV0R6ccwEC.8U56pxGu9vnXnIPUi..4La5s7Xs2NMatsUmVZ6rannHLOErg.s+AEMhyjUOU5gLWyUxApIagloqC35vOz3RgHrxOKr5QO+A0WMFUsgzaH.e1ru7Aewc0dn4CytCKJB8F9XoDoPqikZzIHpqpYrck7rFSADG7VQ4oP.dK4P81GW8IplRNvb6+uWhxgZBbp0FwlwNwNBx4izIV4ouqJi+hfQrvyBzPUldhJE7vdW+cRJmkRZgLlAZxHIzUoMszBWmRA1EPfEj5Oos5eik7CqJCrUOAgtF0d6hfaPtqRkEmm5Uny3pQD9yEonhuXYmna5pewHc.G3.buhn67.KXO1JlS0hzp2sZfbxLp863a9M0RyzXmes8geSB3l1GrRN1GhUzS8dGd+UNzNUVJk5MmpMpuenRat40OJFXHSg0DapiMrs1P4.4QkWQgaZbTGBVygu9UotiPWIqnpsM5L3ECZnkj7B0fWRygs3Mce5YbzZlu0KtxvP4pfA0XZXu21strTZu.omLqEqkbCgyg519Q6N9ZhrUOU3JPcS7D0h1S32uEtRwHeZJgH..vDigyZ.aD96u7dQoX43f7dD2k7CB+gKSY5Tw8GKQFw4BEo+GWrZDyqAKD3gdiyUGJHW91fV9oPAg2FBH+uIYBQtVt3Ic6KmttG6JHOyYaRs4qLBUGsRUF2yw2lJ9Pm1fNXBzzvNODcmy0LBQcRS.whb9ZyWP6o0mI0FH+UjZ9ALdxU02FwOL7IXFCODra.89TZPLMbR1xq.vTUPM53qcOV2RdStS8TPRratEefMVM813NLt476xfNxO3bYiRigVtbpqwUJkZ3t.F6+Lhg9Osy7igS1C6gPiJk7uCriFRgx0I1rEQGdsyIc9f6Uy2Wwu.ZxrrzSCsxeJK7lr8w94wcLqXHMTDTVqpLx6K7TveX2v8X5rlKHjZht9hVB53m.i6KDSx371MzwE.w9DJiLnVLLXzWRy2mE3WGtNbRJJt1.9n1ZqJWTtFYKvpr6aBGieVqC0fxxSdyK2sfkAVORKFHG3y0d4j5SahCs.HR6.ETEJ9fereewAsE+ycIfwHZtTfPHZ7nCsQE5Tu35SEL4pl8UofqSImjBVtKXOrK+3UV8WxjdLj5qWYVgYo2QZrC2dshoNK2GBRqK84Zajd6P52VRwWeghpX5FLFEEVvrtIrj80fHQPftLTy.K9tyV12cmV3WHNq4cBtf.JrokFTXeNEngmbTd3Vij4AsSoanQX6HFDdnFUQzXczA5CyppIYcPlV87vodXWxN+GttW+jxHAD+BBrclk5U0hUhQHduy4stcZdSAVcA5ANSF88L717mM+skROPicThb3JFNiB2sv+gBQJVHDpDULNUiLH.fBilxJAO5IB9oD7dCs9naJBWagWd.3bsGzhVbFsr7KUr0y2A6Hcgf9Dyr2akK+EL1YSdZxaC59nvW9Qi1ow2nuekYR1.mTu8oh+.T1d4jcbXSUwzgyTY3cCWVLLhdkmXpplAQ3d4smRoKaOL+H78uhxa8TTZa59qCyye652vUwsvBNui5ggEM9wZkpKyPuAFkbqZvcZUM9eM4m7R6fCBT77kywa6DCnO6nHlUqZF8NyY58G04VgZMvg1yYP439JC3s+nP9X9vthzBLOi3k.TQu6SnO.X+pSjtvZT8V7Z2PJSIhGMlAGAJGJ2taGP+54Qo04Vjl4jWARvqULhIuWftesXM3XxX4.7L1o6N3hleX+G4rEXkUUwcIe6iojTy.D0wg5VtIh69Sf1uCItCNdP72pbD+6ztYEsTQYhR0gfdKto7VNUPKFB9IDBHAGxOhyBWqe7BfVY+Jz3YdPOdHl+NABpqgN.QHRS50zA+quUxlyOpTTwIDPnLwHTcrkjqnhXdmCUqyypi4gPtNm88Rd1afYOdi47Ta2MqW.eBwDQiMXkW9izJsQdw5YC3X.L1sj3hqwlBQgV36t6ZvRbogt01QP9bGDjpWBCS88t.epj2958XLLTqi.NK5BGm416WWGfj7aR2KIubE1GBuDjkbB74fnxAVYC03XuQQPi+9PwWstmg7uWAChZPYGfdpQyZ2+n8J1hCTtwcq2ok3QV8y5+d1RzyCCxpz0HcfvRmg5uORsYdJkIBfYtdldHqjwvsXflE615.aQVHQC4cn7DHqKR4bbNp7+xwsuRuFglVDUUi+6CQpDG6WU5g8KLxQuGsPoiyCIY2kMNVG8j3teX7E9tMB1cJi1WYjFbyCecnp5tEcPUvhjpIebUIM7oxa8Zk9.36ol61OwMxXx.O28zDXTAlwPNYN1Hth5sT7hpmHsnIGvnM1ypMXe90ucJ+WvlKZGREGbUpNz.rJupuEgR6uhNVeNpnNN8T3YES35yNbtQLFRgycU4XwwUyc7Hc87ERwkVvg4HnFsDeLhGmeG+.mzQPxo0mfIooBq84a3mklh42uyeq9sLRKmQkdoivRV31fYAnud7HpJMS660ygiKOLmEvDIHVMGnIeVZOX8qeSH4TIiM7WGMFoxtqW290rQNNCW9Zg3v9a3c.aAwfiF1v.KSNRisM3p5vnaLL9pR1H7mDcEA5B8FG27b.vVmRGu7Yia8R2vNudEFz21OmLFxb170ogLv87cftMia5LqO0cpfnQYkbqgiGOQ63fKTQrmBIzsCls1oQ45frpNVn7TYNjvVd5leHodfYFFe9Gw79pwOQiOWXWrxD4SMTTBaBdjLuiIequpdzNCTC6GG5n70WBS0FlrrQAoxJv0ODGohJo1xZNeVjoujBMwhCkwEpcBhfXYVj8hAFe.BJYi2BBZdgphjxrX2Ffv9mh9jL8ELUDtbvyDKm3xCgNYU3Zlwx+jNkur5f3LENN10PNHmIPmLwGWMLlNTiRRu4zSkbVVWkT+XFXkU5M8UC2vwUocIHjLptLig4Fc5lVM89yy5k9I97Z1YzBRfiP082lvwUV4DbTL+049aWDjPzDZRtj9.G9taI2zVwh6GyBr6y.xRju5IQS0JvJ7oifCb9Q3T7CYIpPyHHsmDZE4pQ21aU3Zb+zapSpPM4eFFOP8PVcRjuP.eSj.quLH49.rIHWWwkfjoJB+fWb9QBCi8eaopblob1fuy+o2vDlKbueRnP2ZlM9+Cvb5.P3dzQ3aZdQOH2wyUTAEYqfvnoKlQhkJfWunCn2Il8fFKxvZtFEe1KsJA6KxtkWPAQobcL1kVbTjaVwDfW8EiaNgR5SAD8xyqyqhutLFqPBW+0M+JXLltngUNvYTAN6QI7ySE9ScVQ7Q+84fYvSTc9VYZ.zBO2C.jFbcIrSgSUIVIdzzBzpfxRDJ226UhNnin8M3HYPQ+OfNOrDWbtSqIM4nyBfY7bCbPB3Xu6e8H.ptcF8qcpYMQtOQKbEl9HwUiYTfMqRE24uKoXfaDY10eTWqqVLC9iy24Jz3P7fQ9zlqYlVPITb2F4gMfRxRMShv.kWMSBrVLgccN8xMzhqs8PyQdiY4gpZvIovFoDGS9MkK7o3Xi836644BHUnTAb..Voddgpjb7rfeuWVQVLCjq8fh7CdfKJELYF10ROwvZIVhpaCUjLHdunGaa40ZwDyPJd5WLrrH5bqiICuw5WYjo08kGYxqwa94uOS1avg9mwUumrIjZ8FrLoAFv7HeTEDgVpIDPOohl4gUSWcJAU+oUyh8tk4ORj.AECze1pEG+IkJnQo7AapdOnZ7qiXuzRYLinwmV8NuEC1aac7aeKSHUyMnCRh7iyczk3xeG3DXgM.3P6CMIYDi64RuoKCDlGvvQRW0w2Ts3KASfVNRmCIj3xMA+wD+nbhjNr0zFvPM5LsWpF0b4b2wmpjDnZBwn7rU.ZIFxidqiAi5tAJtsraX77sfZDabB075YyEsz6RzcxT+h1g744eJ21QpxDRVNd+clpQZaogXKr911OLy2LlBeNWPPqLJdKtojloJC9aRgovmGbIceelTm4V1GTGojiGA04JgfJAmfcHwPDQSY3wcNBYBmKqdEXftmcpJ1J8B0Lhyg5Emt8aopnT0.VH1QMfSApeplZfEklhz7WhlckPo28j9sNTz20z1HPYEk45jjKpvF+md6vSIA5WBxiyUJsjZirfPxKn3.Ymp8eq+mkGJOcWHA2GKmfHsgWu52TTNwfx2dnIj0OaFmjmMrlHPZFwJz8Evf6fKcCNjB9FNiagQMv3vpg4Wig+Q6+ymzMxKUJD5msUrYVpxDY2Qnqu1v0C32HWbmy2AakGiviohsbXhlI+eOAsrUeeunRiIuYBC.pbbFcsZz7jga0522ogZFGLPW4zTNUS5GlSX2WnPEVZsPkZkH5J8THy+kyXnTYtN0kKawnd7iO++T9j6GLGbjtli.tfJ3K5ERH2ui+3N0a1MwbiSshMzP52.yrp9eZZNh2sC8QEzgxwCR6TFzkRA3JzUere8Btp1JKTgdcVhIeuD7Pp44dzDa2AgdmEkBnz.7u2WcKq5F6nJ5JJb88Bw0ovPqWcKhg+hmYqxdZ5RStLg5lKKvyL4ucMIWGEw87GCKlhkZKXBvJxbsIn5tF1qQbNkxnOMAe7pk5+HOyQY3tbkyLZyBhrdwxmSG1cHmIQ1ubAsNBOkpoY1G2u9VeDDkJj96gifYE2TnOP8UzhNBLAz0QNS81R8bSfNg+9p0B7dvKv3xKUxOy.YEyz.IzzN27WUz2aBlRmdX+WCI3IEFq4tQez1ztVtf8lQ8aoCdGEtewPVE2bmXl+qIjoi91JNrYWjYg52uo156oiQ+RCs8+WsHEtOEpmjWVujCq9juD3iQiexYRmuKoWJUjAlKhuPXcQv1fmxA3k4ype4rSxOPjny5z89adj+aRDHUnywL27h+Ot3UdpL3RG4I9Xs.VMU1Z+DvEMPDTMWfN.mINFIO3nZaWj9s6.DadmzAAgnweRgzxe95EyhK9JvEyYoGPJSlMhsQMrRG41HJReS4+I9GrFS6o099n5rWNPyiS6zV9Gf6blRidnVhYj9w1.WCnTvwezyI70VCoSQgigZtbIrzH1fZTEL6ER4pRHiUiA0uHvktZ4GHlYgu0jtiyDcJ3Og7XwMUKIlX794IjvTYAo2yQUf1cS8WHkbICjIPM1ZccDnIMQRQ7S6w+VsJlEuGdvoHTNKiOJMh2RnpejdXIUPQMfQnEPilG15XqFSt5n39Y6CfgK87Y8OYSH8Q4XiJP+9XyXGBEWOHmBM4dVpTUXRGv2qIrfz2fgw0eVplRf7safsAxgKFezXBsqrxNBY0Dea1KhsDG+75Wwbl1+2I5kB6y5SFbGjqW4DEsy.0PMy+31mLA02ElAntRd+9r2oh3gLFrquEmWevTL9lUrJhzI.CabGQ5SIBdIosbZu6zaNA+VJCGOYB9zOPIaUBuhf5sMHcAi4tEQPKq1m0MTu3.9W6zVnEYR.DGfknJmhRYSoNo1ls+XbT5xlcBoubQRptLwRJpt0BoMYfsSR4J6g7t59WDnqb8Ytch9CV9KvGdmIVs1JJ+ZbSIZfA2IXVZVZ3Bq64geYpKE+GrCpkF6+o0ct4xDd2W5pesfm2lljToDAKBHaatYhIhIxklSE+G8GHrpu3wk9YCVlHZpbgsujf2w7kCLR8N5w.sky8Fz1Z5.AzBnyJsO.DxgUCkJt8wckfAPDFm7WyEne4V2Ee6jNA8HmGK062SCzrOqAQYmxjFpzUrW7o0gtaQBi4oPRPhxBBGMf2Iaz8jjcLCBLXp7NTZrtNI0nGGtzycT71Zda.d0kbZvQ3nJ8N6kBbA7YCZRQ8rR7trPRy7r3sOmBBfFk0fDHs+jEiTP8KZg7py3zRNN1eLQ0Ifpdqk73DVWL868JvC9YO9ewVeMCmjFI+ABPr6rywGLZvG86gtn8oE5dIg8.Sage.BPhjCM6gWLnLpCX28yDQh4BrMjyV7kEvFzp8sE.H1dmTz.zu+V4NKnQnQbk4dyZensvxjBKkCeFc8vQaDkGImX0buvR6KifNAEYzV8kzJBDEDj+D3YIJHz5bm4VHVy00GR3Vli4mqhzCa0Jf.J3AkznB2v3Q83JD+zggOn5RO+iXWe8MCQBFOCdF8M3FMxdlGLn.Of7ZDKs80X79VZJTFgvCDi6EUHk76xsjuQIJ0PujEuRtK49v9vQB.hC7wi41cqSkfDTYZWR5K3k+GOOchxrrtacwpcdYvBNiBUKcP13Ipye8krQBNw8DT2Qmg8WWMKYl1SPOsMtIHodqUxQK7bxGRWqypeiwd1qz3hADcML18DmAKAKXOpnfuIpEQ8oiZUefQXuPhhpPyFp2cPUEebjbUycK6UOquiZhlhLNXVfcEZ.aoO7WOBY5uHIk5SIQ58nA4.oEBK.Xla5K7IDLoyR50spWZU610Ai0sf2m4AvCGFvBW+1bYCvHsB3VhGrqwaf.t3.lJUMayx8SyDsZWuKtgJ6kQixvIrNSAe4YORAqWQC4baxZeaA7v0HfBykvzT5RB1sTjOFVHy2k6LmvmhSHDWVkKed5Mn4DoFUOgdDCPhJWhP2VRKAkS+0tpw2KBTl+tbUVRGZiu055Gxiz5FqsS1I2204KO253r2j3zM2ZF7iWfmwH6Eb8nuFjUhFp3L0vWcPh8.YTonkjuKJgcPqDc1sIZYRij+rGJqf6eYpj2phNH+IO+74BFF1hnS2HTfNg3tNuvnep3WyOGKfWjG3hHCH85DysutK+6J6NVw.H1d9.Mg2XtRR+gHKOODJmIfWYz0j2uvVKK8GdS3V4G0JfQIwXPgYO5dD.sMZTsEzv3w5yNeKo97DjBQmy+cqKGtNHu9HQAfg.k1uabwBUAZ2meoXg5+TARVY+.O+1jyRVeN2+R6V4pO+5FREXEXcI60HBxq1TvL6lIL84M1R+yG3qrH0asaJh93p9tJE8CLfZia+t7atOI8KiMU6XyNhGpZMQ52Idnk+37ilhXcvY4LGxMqk0Y1d9oBBG7FCqmDJLLtGKjXSNI.KWy5Sn04JOlBU6qToSVWYZ0.rV248Fhbh5xMW1hPfPObDE8r6UDHfcmaoj0uSpBejzgeJoAK7K2Id21COHJ9OJeIb0dAq2MGsvQ6OTTqXwqkIL3b5a+k24kJkqdd2txJhxv9CdVgKtsVHynL8jLldQU9f3.s+j97jIjKk1i31Y2hl7xwAvDHw3Ssof2C03SB27q6i7c+nmsp9noABFD1KeKm4WQCgpwMkqSzX3Ltts7L+H9pk4I5o06uBcCmPqcfAGbMzjksGsyO6ApacE0T8+iopmnrv41UVPUyPxz6HJZiZBEjkQKktA99.Rgrb4b3G+keXq6OcIEF1RB4G0L2d8ja+V7vYfUOKOSPS+IP9hRPipRaMniXGa9vxIqmRVlNiWXCDNNpSN7aEAZSg7sflz5L882Isrn0LoY8on6YXgzAJrcGQVEtdNGrgnxX6jYr5jtTg+jVLkirt4B9.ul0kzMRTBb9qvOClNJ3lqtJ4SOrojhjAesDeRLW5eits2kgoNzgBJ5BbArEtcRcJDCxp742lcnVDl4zlx9quLI8cIzYaSxK1Q0zRpnJMaanAVe.yYzYD749bvtCKTo5PIkM8MMw4lNWBfWt7vNkhWUYNX4R+wVQG9UBOVRpzcbe72PihwMTQnGh7Sd3uplh3YDux+Zzj3++maY0hMxe1p5BRDjvwHAV0cW88NWJUswxhOYGBZAm+wkvRTDMg+zWCalGzTP4gnHtGiG44bbBKSy3S0C2q24qX2+P3yVYk0ZTpXuK.nFqSgvcw+1aY.dOZcJCPrZWyHGV.s.ydUZhkFgU28ILJ6o..mPmINrC2HDvWjz6LFPrgIwtwyWRYBQaFnf3wWKnEPcBRjehy6fZYul2sMR7wNmOoFN+nOudmhpfsE45FSmY1kR9gkxE8tdwWSQ9t1A.yVKY.3DjOLnATsTvuvX0MsHGtRGHjzbPTR3gga9nWfoafwGsJhNKaXl6IkoeF0l5HCIHdA35Qo9eXDiz62brXVXvpJMNZrxIwFo+CVyzfOiAuTV6FSc5qrJg6qFXm0JblbygLbw+epEFJHSkf9DGu4irADFotF.NPypbmkQOD4FM55wffQ31xS88QRUvdROVgNdFXr++ZpbvA8FB+GuQY1eyTPNX9N0i40UHlJNm0pGg8WrhQclyOpTzM+LkYu5wSmnuUR6V1fRRf8o9H1EL4IjLsgZ1rVcbXcZ+9FT3FzkN9CZs.Qf2iSHzRaud4GpYpMt8ogfH5ZEiGNu5.qWoeTGbTOjW8jsRRd7vAbVu2Sk8jkPwbGu1DqjbGonBL1dCgv9uUargpTcr4O6yLe3UY1HNQYqGORfQxqYJKvu4Iw8nVzS1+D3CVkcEcEgJOr5i2lm+8DsUPh2S+ndESft+SxRpsuhf7VcT5sX.o2DXbSPKsNBQK+LtJAyWg6FeZRVWKzbHF.jhCoagiijvaBQNlwFqZUCvj3VpZZYRozI6LB0rjbUpLOVARWGMkcIN2pqXuedMqlTgfvMTUUXLBC3zRiG.q4qJ2O1RseOInbIQEbi.GY33.HHKk9eiQCaEeBDKFQ7bsPtG9bPjYnEu091EZIjmhwrVdt5RgFRdejRtkL0hrbSgYze66uAouKzc0FwPCHye.vFglcG+NQkhXrBYg+K5yuOWwVUMLZrMnvqNurh.Ti77KlG46LvRQgpnduQXF2uu5X+CHc+Le+NXfqpjId03HNok0GcofdrJG993045DzR8p95zbV.wKu+.yNwOCVu.J1h8sP1IBOx+r0w7pkg1ecrLWOiGc8+4oDQdupsMFR8ZA0U5ADokXjpfVOnx+qQq5hNE8HLnOzsdYWmw3k166QCEog0RM5zapRjswohWYJ67XttwqL4+YkfYCJOblZL9MNKocsaphBW2BfeIeWPks0nWdnb1g.l08bcOzJ+puDgcNobShY4l.cruggU6GwsmNhJVgWmiWibBF1k++H.LR5h0nNQ5xAsCC2VNVXMlBCCEDrrjlYVcvUwJiSmyA7qCxiV5cYzzi5UBacW5su6A2Ufk1MPTFCzrPhYetbFYJCMDTEHPDTWG.Pn0OClPN.ItgnB1xyTU7O1ct9mfQ7aF3axjkDWxSJgnWb9wS+5Fj3ZxW3WHunJNgM4+nxbvSKlOb5tncDtrmc6obpBKqQB5fDaS3qiWNHdvwKOkFgFkX34C9MgjXB+jwgxthDIaPuvFZCVH1+mrzNONgiXDk87FTNhSPIWV2VAmhXtClfq22GkZ617W5PbQf760XCEBdHnFpvkQtOIdDKtXCDJksIuFhnZNvJP7vTJSt14.m0UprkNZwljpRSanehJDJyTpNS5ilCjGG59uNCMBua6L7BDSvuZxdqWs4NCc0YaYfkNId3QmNGJeznlRNbH2UcUDlx5tiH.I+y+JN7zyg.1YzomBtwXeGYVDlPIh59j5YmsCLGAxhlLo9EW6IQjBQQOz78+UaBebXMpPwejEwbqUbk.V+W2USY1VDpQ61dBuJTzk2GgUXUU1m2Gq8skL+rN.Ped5M1.kBo3AXixYzG6aJo7r5RaYf1SPIUlpuyNCgOTmqO4gCtjrpJfY1G0mR0m.Id8qAmm6Iup6fj+wtLUCrWvqxajvpMZWYzY5xSz1VwpnjBC0LcKJ.irVEtKUl6J0oxOhsYwTsoffrQwSNpPVbLy8WHb8kuCNECzc6pogVUyS0NrlJMNLieWGea5ydvhJBrsj.sQ969RMi6pz0kXT0JiEsnAj6Fyi0FoOuUN+F7xuKtDhuFmqHixpbNwD4JKI4YIItoN00Z5C8edSADHAWe7uMSO9Q9ytaYHfiBUGLplc6P5sGQ+Iw7afDuay3+ZUAu7v7Z9VH9qZ1Rj15tSHrZlPnk.bG.4IkL0+P.qq40zIMZsfNiH2Gc5NO5Al2AvNhgaRSKWdfQWx96GC2KQHqaH3bztLJ9OQhj5KGo4i5oesjJUB+gP27gUogDYMNsIULNeOyFqNtjmln9u99jJk1g1EL4kpJUOBbRxY7u5fCYzgj19E0wQTP8.HtiO1PPKJ13e47v.XVQdqdxNyFhZR29JGHnrLN8FjgozMibSBnXZ+0JjwYbVYLDshnerDbw2yf6wD5uNimz+agKwiTOr9C1PSll8vJNLJddV6p.aOpOliwZCVgbQxkxAn7Ues+36nEolZm4jvx8UAh3Bcr8XIo8kCASEOjgHGzFsMJYkXMPWhedvsftzETcv5Lwcev4+naSJRJyA7gxES2EyYtUZ7beedWP21mJ88ijgVAWURwvvNBqrMKFv+gO90dqKHgiyULPQOEwIVTEK0WteheEY+95lqxb.8apUKIcLQyYfA4O+bFN0zDz5Qhz7MbDALkoQU2IqPps5ZURzUD9AcAcEtvIX0uxJTqVpoCC6No1H2B7tuPNmMj7YTZSmyd2kFF6BepNAOrAJI4pVvxMk6oSAQTzp60ltAiQeFi0IrEOU8496BzAOQeUj4C7pgLjd2+G9HdvjMrp0FxlFcXFpSULfyA5huQsN.Z..6Y69YR8DmXXhuOvOLMiB6vyUkq+ObRs0gIq4V1CgYiTBc2P349Q9.c7Oqw1JE54GvA5rG0Z5C.ZIs91+NcWlYMBGJe65YPSxb3ga2nTKORUnvYRHfyqIH+YyyvL53n2kl6h6dPgXy8Xf+MobxnnQIbmYg8sC0+N+28qtClEBD1utZqI7tFhuz5iJ0d7pIxuYCoOV4O89fiVGSypdSn5w9McG.1tnTU+CZAXpBRvfOKQqerJjtHVi94Mum1xmuk9sIoDNbqJBNH6.v7lYWglOa.tz9VIR3va5VBYy3fCAH6r6qZt3L7JFIvFWlR7fSNaEMlAYYbxrlizJjyeDBoLmkEUHvTbUpzCVZJltZaoN8vDTztWV4zMR448dHCVLrPfa6vnYaYbRFUCb3FovaVYfDnXzyHG3iWGUqYa2O3YbGSV2D9CElZcjRvdNDosSvi5UjTcVxqkEBqx+XC42bmDW7N6b2djySpxAd8kgTKUSh9YPwXMXElaS3xa+Ltz.ZoZR2sUMjVU0PTHyodnD42mcugUNdDACuBQBs8Nx.vWA8VeIkZanxRkRrQiSBylk8YOBPhuCrvOqCv.0aZJmzsdjOGuZfl.ZM6mhFcKwvNFVWUWg7w9NSDrzpPK61uUdQVqWaIyxKkWM7NMXeoJEpVW4A5TAh5xCK8TZOMV3jITk9pWCfcO8pFMkE+jEuivHLy68c33xNdNCZa3x.61DbzfK9zqT3tf5h3i1T1eAMMIZu3+YIL2yH4XP8A+mIsPAvMGT8.d7M+nyX7zrBep4liZ1vVm2D9e1qxbxoBVD6OywdruM4HJXJnAtGJlrKWvqcFHhXei82SIBH+0RtVZHrgX318+RSWNXmg.0UG+GPZkr1ku3BOIaYj0zt.f21QZEKrOTlEFyc2Sf2S+ukFETYRfkuFHyH0JU88ASqyTyLzNyqweCqSkd+yqSHQjuXngR.OyMyqC7xRyK3APdkK6a9O6kdiU0iGw0khe+ZpWqad4qOkd42LU3z+1j9eV+LxXj.gk+jwR2Qqc72PH1Bl2rV9mJd9UlPYdrYvkRw.mEUQluCo3UCCLxKB7pe7xDX.XbU+zKIT0c5LRGFNHRCZ1EDTUhNMqx2yTvXd7lDakOcsAYg0EYwfgZaissIWAJp0elsNhshSPUFIfr+KXHcduiOBKg5UiVBZgp2oLeNmz+6fx2CFbE.ybcwzweyr29OB.BBmGVpr8Egka1cZvzWNRsJVYsLTCjXPCq+2yTv.YHi7ZELYJkUcGjDC6EJEVou8rMVGYY6qaXwYz.4ORIb8tfHJlKmD8sJt46X.47BmX6CGrl5CgTGm4M6lrsdZYTsltgFwn9kAeTqRksEomwIkdM6NxRgijqUlwSLLJVGn.bOjpWUJAggj4BfeBYZTZyh.UpkCKFVpBUZySCL2BISLibU8vKGe5VYOywGYlu0JLqz8dKZOPVkKJHvjVuvnAixM3sHWJUgPMve78Olu2lWfODhmVrogRiE75P+jJHJhaDDqWeVjhLJpybMUZ8hsxSELyUimQsLCKfLQzEwxAWZvSgZRxuJG9fDOna3N0pjw6ZLfAVxMVk7P3IlkXZUbK9srbx6jskKvTFHt6FnWHyc5fARadgiiHnOkrcIogN9XB6uRa5R+WK1PTUryk8DZl8yBp5+wMVMBDWJAVgGD29DG7562u2uEXtTN7c4kOjL9WgQIeaYmMmqKhuNR1HGVbVi9iZtxXfA1ZHDSOIht+5e.igwojkPK8P5SqsxKkUbuSumabia4heZ.0vepinuU6LyiAxd.R2ov8MXYua1VHQGwI3zt3qCDoFrr7VieQa9e67U47rVE2Mu0XoNH+nBw.xxYn3Rta3UVIHnhTlgEZI3kE13O98T4z84j0eedX4cL33MkELr3BgFZrno4Y6nPMwjXjQsU4d.YZmLoOjvIn3uHzpbN5Q4u2XKkeVLJpLiz+XrETlgynij.GLLv1o5a1PIDXTmy0L4CmYptFKvn97CrtpshWlL+JY7cdb2yWQsvngV2Dk5qhNfdLPsfV4v7Z5Ebz8whJ8WC.HnaNiaGQ6SGOkALnu0hfouzcmSDAswFWjiSEnNXnco7Lcl75ZcTsElRrhENFw3P.DOrfQ5bfpXxv6k9nYfxF29VM+44R.TK20gyjqozwhA+XlRv++ZmuPhanD6usocKZMaE6787tIDXfKpBAjv92cPGFTWqGqV5STA9B9NJA.4kXWWv5U.GfEIBrEMYTYo2W0UYbf9UOuYj5E2QQrMKTNIB3rmeG0z7s+4vSO6B3qI6OkgihSxjNAhfYP3pyUWYxUkmT9sKYrbxfkqDTRPFk4Pq6FuZXtvaou4AJf5omnpjB1ZZujl6jj8z7SW8Ss49IQI+J+nYbdVpVVolrjVQZ07dmjSZIAR9mLcpCI0uiCGJzGN4wliwQSNLvVN7mV0fsLp942bDXWKtm1msBJQQMoje+2iX8ZwnCd1CUoEUPPhC41.I55zgzCnqfCmsMym6VzL69ew0xxOem14MV37+8KuYa.Uladwr.VqCch3QaFoK8cwF.yVectr7NnYImf7e3G9X7a8aIloYzeMBuTZ9B09GdFWeARVgUcZmOIREM+wqUgMX5hnUSjCdzxx1GRQgE1I83kBUzbb89QGQDLi5jVY1xDCZCTTLHPIl58uIqORzI1qyA10A6nM9uFEnGoKooOHXxNdXMS6O2hYv4pfb1EIABWyrYNTCUCnEAAd1cdf+F5accKUeqMfWGMArklJSHBlP23zZOojKUR61ZmxqCHurDx3ZPW10WN6vhRzhCKFJYEad02JFdIgOqQ+P2hA2DCM2YQWAS50rHKyZhMcquDYmQzERLq5KCDswUmZpb8Zz8pdqptHiNOJGtC4UK.KLmXRsZSc.BcllEW9G30yhNfBCPEiQ7C9Gh.i.BglmhnXdA3zAfcNeXbgnUwrIBcg9aYRVwgrw.q1pXO6UL7nvbpD3WpQbHrK4Lhk87VeUVJIC+sT.5SMHQz7YpBXOXT39QrjdXQJ.rHOoZeVpb5uM3Mf1JWozzSpo14Hc1rAg+2EF49YZaQX2IqDWePARO4FLkWcvrctapnckkxMI5KveXmhs+qh7oay3a1f6rqQQFkM8UrcanIA9mrkvG1aZJgUMYMDRl0Gskb5.Gcd0u+Woas0pkyIhSPh3V7DWCjejqFoMLf09rchl1+r7Dsz0knOSAZrVQDRrOaeLvufMgYYNzXUIHLCS+uyKyMMw0v6BZGej5LsUDitcfWIyy3DF9d8TnoY8mG.YgjokJtfcwKigM2dXUHWD0FkwQWvGmd2fuuPybR5jtPGXGiItYtaGEkRaiIrenBvfoEFDUlhBkLoxjBQMJ6U8snB0VDeca22zLR48tyIZpAMEC93+6C9gzFbF8iK.byaPSh7goPvLpfrm+LNYbhlo2nBreIr63vPKgp3gUerZTm4iZkdrCEvD.vNNV.Xv0sogco8+mTvDzGToRy+5e9Yli+mlpSqS5h2TAf3ZPAnXHVIhX4nhSO1qC5S7epeukVJONMKYfsk+nldsz4Gt2KUZGZQdUnt18S6azbsU7zf31U6MmKTmWvBVH5uLxOwblyRUeR9fN0zG4C9Frq5UUGAonuil08nOzRDx2oT1lgGLBCAHx+57QoQzKEdwIKpeDoBhTV.Xwzt6xsaIxnbMetMT1Mo45lOU8s1uiUBBeicM+lSS4bPx6LdxBtWf3MhoV6afv0Uo0d1pwpLfnMuIL7Q..PE+f2iFY0f1RfNmTql.8jRfsgk5.5BW5Qwi.lqFCusHkeuABW1UAkzP8IseB2yGV4pzv.4gdpLAAkzzhca72mGyo.OdxUfkSo+eOt+e.jL61w8DKAx42LuKtWEtRaNqkRJPQFCa8B4jOH.g87DpUdcqwUKVgoArIdwJlMfeNYb6IBonn5i0udu.yOaGvS6MJEl+8I2VuM0wAnFOc9zmKgXZQMPYcsUnGsn0kCpAqSryvPtgEFtxs08VQzaK3C0CdL1tBdGOLnO7.IXC2VfgXL1QX4aXlOJdD6X58dnBBNjn28eUejezE0zoMTZsGjaPoN4ur7TkuEqMA6EwmlghIS.gqBN5GKk2CPJ9js5eHHxyYprhBrHTopprBkGc0aOu94nyTmS2xuV7jYNxlhNxRD0iQ7Mxq9Er8bfG6u9Bf5AeJ4Gm5eOk+6UXnY1H4BNcfPGw1l7VHtKqmxQjVIfF9YH3SsNs1L3GKrwaH9sBRtQ.llwA.R4JNbX7Py8hmB9soamHR7Hx0A60BXXTuplZAc9xNMrulNezkirIxXGnSpyu2DdfxzrQ6OMee22uiVzg9EzpLRGKVc6dlWspUbsD8JM8PyRh6GC9.Lm2b2k6NtQa2N8MeVMyo.Ru9q5SZTuDAO3ykmd7z56ebKOclbAqugfLzLGhb0AhWql+UF.jvXiwf7JvQckurPb1wczOgmAM7EvISX2vGwm4jlY5I1GXtZLenetBOo0678ZkvmnxF7k3S8d6TzIW+z68NCGz4ghLwqwgYXajofoICkBsGSkBRE87prY0ZPMzcbKyFcOPiPrDmu048NzV3QF7ZpyQwSJVf8IlaXcVEXU8.jtZc.K0SEnitRbDPxzQf5Sa2nZJ3oPFYdlgk5yHNba0zb09.xO5guA5u6ZZH0pf28qu3yw+44t7nbKw8..oHonKOerj1Ka6IFutu9WrVKnDq0WzVcsnY0I0lPPRfNXnZUChxpfy4dMmYKIOEn7Jwv2MWooNS4QDbv.U6Nyg.j.WK3QYQ93zrsRlBBxZGgUuUxA9R4a9FNcjYuJbAWu7gwV3y6Q8Uz2XJXBx4kGgrOwIXO740KevX5e1d8n6M7B+jrH59rhuHqIWY+UITa4dEg30chTAJeh1h3OyqD0VqE7suRtCjRkIvO2y56+buql5QSBWLeV9UwEEoCDYJ9ZGbdYZxYKyFjMvXS4OBhftWGl6BU2J3HoO62G7n24RZYZ7QvSclPMg4WMoqYAcym+QstbUku3ZbJL9gIQTaZOIN8jslZ77J89dR9+Ow4hE+wa+UN7aBPuGtkU8Fqmo2uiz4d5oApsck3xPC5hOqJrtSL8cDoIW.PzwhSKmMMoJZgqVqOoEJsZlLloDBQIbH+wK+EwazN+yjs.GiY2vbLjlyPEKc0iynOfWywMM6WM3wTXFauYaUq8jEswniMurzTSRlaoZGlbgbndc.SfyfZyOpXr04T0VopEQJqDF+KGHpc66Xh3YiRcUyQy+SUtVGBxTS1II6wjfa9ONqloi2dLlddZaP2TOWYrA.yzF8.zh71NtE8plgGqP0F3wp0gs5z1uka3p3lc99eKhC5OhUDvCWPj6ZY4KwWSrxwg42zL2705S+pdMq4hXHHHFbGXsp5ywc7s1vND0Ko0QWKpmJSTgoxr6J6LbqZMlaZCmw5.zEtXeiSqGwov3cnDEfbj9RD.w6dADAO97dXojOY8gtwpGfzJdehVd3zKjnHs+bM1FAX.BxbqsXGPYiteKo3asvm9k2ayDLTFZllcVCmsUagkAlbarONrwUYGjyfDn1ytOwqv3XsK71Yvk3UI4.RUhLKuPhvfp4cpnSv0tfMd2+CR2yNiBS1I0YLDKJUwOU7LGfi6BKArn.zzeWLaaLzAKlfyc3S.uw+Dedjz+hkAXJYkijTxe6FihAymd7LJYe+oGxQSN+wFzx0eCusU4LN7lmXJ1SAvYaSeChtG5kedUDtFupptcQc3UsQpDoL0+q6AH7lR1vqtbqt7.8uaqmH5UDyGqBXke2qRRuhwVkGDiZdoWYJdbRCJuT3PtjO7.CevFDM+OsfBOkwZ9Qal5iaJfX9+t1cL5gkE3CWQvlD4hhHoK5nGgZepEVKc3u9R9r9HX0nQMBjEQnVTJPP01xdIsFjwEHUJWfmH6bg5QpFelx1JfhKDzPVyFO6ZlK698Z9G09X0yCPtjHPbCDND7haH91tksZut0CX1iMMt5+3m7P4R3dJfwYoXmaEjJpPllp0VSoJTEPsXAPpmMNrMbrHHU4YoFBANhEE6ZymxQEmj+uprjipDce+sk+BjawnQu5DPEOHlwq7nVRut.8S1.tpfTC+ZpCc+pu33SM5US3dfRQ+jqIV3q71Yix5IyjF23TT2Fl1FsnZxlvaRpJkm81yzOTYLLi8FDy8O814BFgk0ot8rMoTe7ZO7R9kxgizN8KNsQhULbikevHkcJLcfhgOeRUGyz.3ZmHqydpMkfaWZ5fm1ems6WCeS2Vl2peqK7iItJN7NTzsKTcdyfmo890iQ5CIi07M7Juw7m1X3uQ3mpJDKHaYkPfv+OWo99VgS3bNhPJ+M1qdt1PA3FRwL1gWvxFlrIEX05YeJ9ntiWVCqqgG3cJof3UcYv8FqQpGcmmlw3xBUfZ9G1opqTCTNT4exhEBXImCXizX3CsprCW88bNeKgGhBosZjl.9bGZinBc4nZx29P7qlCtcyfbBJ.Xrz02UOhB0y+s4FwJ4raLdCh2YN2bhzpvTstAAXeQ4Hsn2zuN0kTBzFFYhBmfgFzFsBqxC4wd0ziSoG0REgS5.L+hIcSIfMgLL+A5.ZB0b1mErp30VcnPXsPrrJidvKuBnVcDvBbtTH6DNzOSELcjtcNv2xfNFEpLc2z4AQ+hVgzIW1cCHOO5PZ1e7c5.I1N7XQtUggrVfbBht0jKQ0wM.bWEzHtxv+n.UMvfcD25jg9+b+rTXAtM3pivn4MOyElGAojcYgZ2zMPM4SvbGbVVbxMMWoXdIqUlCAMx70o8Lz4OwteWb6tWM8XG5pm9UmHi.k.g2mF1NHzLzPLT6hkRQKqTQ8yI7K6xTzSTvg5LYKOnzFrUxm435aFM2DAYJXeJmobnKN8zdM2ZXL1whNt+hIaTBhVzDxEPm8qqS2HcOJ69i0XJiv0MUw0nTBhZRThPGblTtlomrM5PRG.khQ.J7YXq5zjlyGZLYbQXT2SbLxG78eqD6fbhd3vrA5OJ08ohuF8l2F2W1o1paeM+5q18+8.nAkUWpNPX0tHbw8cpZiZA07mFtOK6GrIRo4ixTeW0ai+VsXBIxT0pxGDgCV7YrCxpVu6g5iExPv9gwpfsZQ6Rh7Bx5H1s5A20LIvwycVuQkCajEpGiz+qYpvuDuXVnU1E8PyHxYneBbp47OFPhpzmR7XxqtF1Wj.6peCuNJmgatj6NDixtw3N37pH95okCvgEYYxuttqLAQ8SV9.eiMCDVmDhpkUKRNDYw9a5iZgwlDM8FO23bW0DTnLbYZQLcqzH9ljIkZHNJgf9LOdVx6.Up8cSXvGDbNIpNK+ELHnC+fIrfvANRHpn4ZayFnyLXoxmmu9T6qHn1U10710uWEYgyGzyUdaG5WJaVW5TJXhXUf.XW4wTrFrQlNLI6DU27.54VJSwSQsfZRfI6SClkKL4n1LC2aldRC.dP5Ryor8hPXG2.3DROlYIUHEq4ZcP+CovZ9q6RyLhFaVAPuUIzq6DifJCOtXsUTcGdNPOhBfsIBzfITQ2lIUsVrnSn3+Yv5KpOrbPniKdjSrWUk.Yjs0vS2+HW1kSdbbQpdGuxlstXk7oui4lPCTY0MIVUS7tDrsMn2CTzUPIS8XSQSE2iq8iA3qIOYvuPBsocgvFv5ciLw6bfFTsYXc7+NB4mP6bPfwonfk4URCeDFdgKQgcaye40htkS+L51acxpu3Ktxo0rxpOS1j8mYJKxFfwV6QKALBWoQJrQ7VEgGLIv9FcHsQj+DZUREjGz+XNwJCLV0uzv8InjT3Pndmo.hgN7.iPiyVXdWey84v6pKe7niZAbcwAPnL+RnHKUU1+Ry7Y+VWmWFMtZYOcretHYSKoDfPwj4JoT+vHLTc0zPcvksuMg+vMB3Ai7NqJCpr2w3asdrzWxY9lsXyNFi+5mtx4G9S9stWVz1ZULGNazmmPrFCqSeHFQkM8jU5+qd0nIajkI2vw+kWNZEgSoPHAJ6kDyRYZNkG5Kg60ldKP8466AxGO0tgCLDTzEdoFX+WF3R6SIjEQPZrCmjtokO6+GHQ+eg91mh+9w9lD.w65cLBpZjSYmsfzXn32uOb8mjMOw0qPGKWlS3wfqdUYjqsyqPn.gNGOmcQ3vEkYl8sLpeSUugDCGoWiG4ZwlZmIXX2qKbUQYw5OdPEyt.JNmESVHAMD7dXRGhzfjzd49FnGK17m7UZHdV+OEQhFGgq5zjPfvul2JzGuM8uzyr658zqimNkMpre3o1Au3zDd5hhq5PhODQpOKr2fIeg7RKt5J.wDkh3okrSJLa+wGiBIJNPc5dYHn8aQ53p1+UioTTLUr.r+JJwL2y2YTNfuiwpOmp9zjDUhn.tJHx58f8cRVRfZcG4oFg6UBG3INr4MT37NL+2Vunswi0tQhcsB14boQAXTnbb9Ije6k5i8G62qcrOOeR6DualzGKRUX7BnvmWirDe9Op8UJlxvuoBZ8vA23GxSV.xyVXTIUMe4k2n0J5m0nlGDN+u78YEN4looWEZ949CqXxbFrl5psuocP42ktfPV3eDMuPbVjX2BACnMmn7LU0h8O6DHc2P1o7qlfrHeRK25bsVcD5sWZsKRULo8L+iOXI5up+LiE6gzp+Qzzqw3WJIWje4hXG1G5QKDG6qjQrPlr6vnxriiEoWSqFAmL4zpD8HhXpg5rte9oF24tAzdpXQDOzLbE4SuC.yFNuwwowYMj3DrbbSX+pjAZtVz6hY0DH7mUf0EHgUq+aJnA1sMhtKt3+cSc3UXZPVwRFn+jdazy89CfvYfpGgbEp1mjkqMIS3uYK6+Mb6j5XDU.fgmdL5zh+gB8V8iFP9X1+lKM1Tn7LIzpdK6tuNvqw17zjP+VuZy4rz4PMmY6s.Z1gUs+MxVsEPxJwjVDxZYTfOzvDciNAQye8jSizqGIM.8Cc+T3CrNJ3yTfXmXHbJsRintTX0Dp3QRtrZ+HEYGl5++8zIP1y4diEiWlZxrRuag2.o5IAQHKmmqx6GNtILToQDZUajveI+Ctye4njmLTjUeIrU1leG8HmFphScTi3tb0NcoQw3GbEyoDeuWDPSsqOy6t4B3YLKwmIt1Ye7lV0RaTy90aKaTmI5SbT13C3Gm6USpFNMnbRLFze.VmO5BcArzyJLs++oOCGjkdGfnio3cry93vVMlg4m8ijjxKGTD5HXCGE91Z8qAKDo5QsoSZNm3QrC1S69DLjLbu6J51dC1I8Q+.PXsHPnSUqLXXvXJtrhbb1dL0hHgTtWtnKlsxYOER33YUIUtpQYo2wwYmB2FCE7inYFV12py9WrZ8oGEOXoX.RBb12wubtOCj7Z6YpgokcicIblpMj0A1hQtkyam8kc9vTDq.x0ZDlCZCDzLAzKq3gni67ob1Y9EkpW1gfcAEHKoJEHrW6nrfeHlG2UMBbTVlYprO0z5TTGZuyoWBjM.n1sQW0kiB5ljNQROWWjBb6JEN3DBmoJPpSSPtY.yaGBGn3MpbwM1fsEwkLbubnjjvLxfyqEXJ21QyutfDxehvaZOGqf0hGT5l..ujLmDTh1caRnH2n6B2USHvtxHBP4Ch1.XisDFkT8gD2em05HSoFwTTYJViXEpC2b6OLQIuqfIIhNCNlEnKO1FOdLiKHW6+9r8BWDomG6gAIybNNtsXW9JoeW1zAxtk4UwyowcIwMuDpx.wMDrPSkIvL0pHuIrkuDXIfuqH.MdauWE4jePE39aipfzsj2DURiFVFVPHY9kaVmnQbR51AF9QbTKz4ZC3N8rqbu7eAaL9iNVnrq+GW96Yc+RlSedXLpZM1BwMgkYpaAPAhTWC7kcTeamVR5U70Kh7TLcjKjglKHvpDuuJ4qtfWqfzIoIHtTocRpuTe5lI13uJgg1zE4Y0Q0vnza0Ig7qTEJE4N6I3I+6LRRDxPH2M51B8CbJEXR52JFFlIiBweycf8YGNP1oH44Fe2sF36oHHTZDkekXz0Y5JHZcsLUsUXgamX02yON0xtqJSbBpOmV+gjyWoazwZ7eGdA1UDuNuzJ.sBlczt2bBr5baqk8EgvxAzVDKrmugaPScYDLGqIwCB.bsv3wuYULFvHMmNQYwue6Fq67qFwkkiKI95UhQv2ynKNBDoJ0QIXXq6PdWiRk0qTYehOahvqMsW6fGht+Z.NDg95JSpXa23q46+VxAXi9QZFcITmSGU66l+EQVnvxkPjrLEdH.Rq9.VzZ3rCmg8V4ZVWuqY+7BNEV95B6DEUAf.kY5U3OoJAjHhmAv16T+JankG0u4OLM++3DmaHm9TCYcR4yM+MOUa1H27sM5teIHMNkEz+zOmBUeK4GjYcYgkK4kixELrdyQhNWdvxP3p2WV8gRwkxiKgy0vsMYXsWVfuQaR+I5q+Gfk1TcZ.VKpFeDQUBiVIihuXIe9ossbZbD5ejzvcJas6Rgk9YTWovzg8YUCzS88b9N+YkDpWDjpeSdm8SZc25CJ90jKbUK8R59Gxig67YahmsGNvXdzt8rY3T8wVTcdGgjC6nGv961NTZFmOX+QJswiCkypYWU8bh1hFj6TOOH4ri0SKzHksSGdbeq5fgyOBT1582nwDXwiR9P3ZpZq.oN5PtOTDMi1XUd7guMA1IH1zlsaZ57YS6r.U9JsPArgVuM0bMrY6GQAx04VaN8YtVKmjty8P4BBmCwwZqcLJofcPOaUZcjMhymY6J1FiibND6b6WpjcrZs7EtVqq90Cx6dEevb.Gsu94OsDeH1EepbM0Rgu1g.EP8z5YHyzHDNQJq17FtJFpjTtCenJZ.oBHP.089.bjsZyx2wVC3gVdC.2gu93oudQyUXcZ5GdsJOSs82O2VCCmIuEJBW0hh.FegmsxAIMy85dD713dwIwGhYbf.mGs0W2etAPD04ZyGjRLvXEqKemz6mxYLUCcyUkR2D8f9CYdqXMYDr0CfrXCMeOoDFPpZlxC0CLSVejoLSC.AfhLwgDQPT5TvpjJUDNL3pQ7MbFIN3F80SwzaVW8xZwAXLNtXm4.JuxG0Kt9lusZQMlONQIvGTOAUdSdcC6bHOnl9YymYOrLT8dyvRLaRfm0wb4l1Nv8QSe+HPRBP5bZ+j2BbPrB.AQxQ083EYJvVPmZ8lr8soZJgSs8LwIskHiSpMcmW7EL5rHq9HH5BBHFD6fpcPXsl9uJPlSgevX6vupujgH+3SuZeCQptGA1dc1vu6n7gAN.U.DJxasV5nC2tSZtIRW9br07q9RtqS4tQ8Lj8LYNtAFsioqGkbLusOsXkZtkYWEvFdFXsO6LIjDUjYaax3KJIrbBEFz+JChbF8Q9IAve3HvMCUKKaMgGfut2I9YogsM.c2spLmE6t1nEWebNWX7slCKqMAQgPrnfIUbwtK2tH284WnLkobHiQKRSZ9feCWgkAPJOo4HB38BhuvgoIyY9ACw2Y17absmcrizbjts3zQSzwHup9CCXa6Ezlp8LutdZ1I.sRLgbBCKj+FvhYUUa0BojCyTHKboFBpcQ9y7Z2bfjeHV5+TVNLOTLo9FPTPfONjDXhzYJdgXbbdh2.ZldirQDWq+88lkeOAnRmJMv2oPBgRXPN3e785om78AYHG14RcpZpFFsKjq8iZl9sHGufS1.yytRT7XEEPr14RlpxB+2MuVmHL4kX1wH+DQzJs5iQfIDpPoCNbneDhuEs5h8mlEer+mxvXbudaCDbvBSXrDKscjQF9N0RBPu4x48pcNqncr5mxuIDGnbezz2D5AjtCF6DmYhLFKmcl7JFAO8GR8WbbqqCDCnqhIQTQBe8y5mFx0yRm2DdzHWAc2+6sDkTiG.kZx5pZGe7qtidKp6UWuqPyJMXJZ46kiGDbELtFLt98wcGS1kKVZG.X5nx6WTrmjpVR60f80eNv1ep6ASQBaTzYntBrBauzUAGehujIi5LakGfTXC.WeDAFmJ1Dk2lRqTp.rk7oXqynIjW5H.I5IN7DDX9woIHMwdRITGaTP+Eb4b4naw1HeiK209frgNwZQBSx5.ggAra.8Njn4thiuD2bxDe5THJIx9Fl3C2YEr8+dPNEu2E91ndSKejIslHj2230XKfGfbJ+laqpldcHD.VG+ILO9xWA.9z3tw8U6GYwLVC1fTXIkf9him1bzf+5dCcxD2Tv5wAHp9k2Saw3xDXiKNKlCx.oOtEhfhL7nNPlz7LqZzbWD+BAg4chskXJkHSguMg9DEfXA+4ErThrFPRbomQSirFEEdLD1rDiw3AJ5MwVsGEyTUBNVoW9yq5G5azIw.isx+Ybyds3DmnSZsWaajQAb2rt9pYkFFmSRJWLe+HE7BUhDq02WgauE2gf7AmqKbB.J4.5UGOaB2dcvhGjEG.dhkvTNk683KUg3YRIsx4u6vfYF9cWKNrbEtjig4aPFGioHmF8+syiN0G1ukUiZ4n0lV0yJEIHwXQoaefm1OkGmf61oyw7H4mtwEGUxrK4yFziIduUIcSM3KLhR1BFen5dE6h4Yjt9EPK9R8abJDW1D2R0nzl4xnp3KhH93+l0zLrKE5ToQxldqh4+Q9Nz9Ewn3GyTnKn3Arb9IQ6YtZuffJ2uNyfac95zIfjAM0B2i4yrjxcMJVB14ylyshfC4HgTTSC9s6GOp4iaPG1vyAJvkJ3hSZ4Hx0oyPUctX+tiSUtKTbGllAv1zbhC7wkIzTjPx83re5IGJZSU7eITMD0CyTaHJ1LrCnl.32JExTi0GUHPyTBXCa0cb.819VLfv8O9zW9z64pMrvNTmlQjWHZzR+DT.NsH4T8iezrnlA9qDX0aGqq8LH2hVF5EKL+3.U0ALyOevAeLly1zMd1ANVjKGWpR3hRIM3jFlfiYhbvgGYMu.vCZIIlJHnIh9pXaC6ltVGaCByqEmXMfEZgwg9yO6OWbFZDTRz2laGCpqKEtzItPwX1vLSKtQhnNl+Jn9R47S2KPCPzHQABW0aPi8jrq+Igg5M7alPYJq8xXIFjlW5JXCU+ad18dnGJ+i1owIqr3OV0EKtZzNM4zltc4Y8JqySu5ECLchgZyJ3uh92GZlg73GS6FvCmd3dSdaKDcEBuVSzxOlnTCgppWmarPGm01+rNHSMF52sAJWQRTBviWzcj6b25b01aBrO40dylRoRx0d0kcHhpOhCA2h0APgVvmSPH2SKy7W+hH5sdS5jtR5+gFbNMI116IUGpRP61OgzEFH.wta5sIa+u3U7fUbBupcOBAbMWVFmRrCj1LGKUpMun2KiTpCFTmLz71X3q8EZ28F7RPm6uz6qzYkLXFweTAQ23wruG+tm7JFJiKPthoM1KIRmfqyz62ObnJav55QPqXkU3ZrwhV4m59rcHdrsWtBDx8j+2dGbC1mlHw1C.B8w2ZtVZaUYMBHDfL0Cp7qRY0DQRv6a.6luC5297Ho+KZH+0mhpz78z1HP2g2Vh6v2O96YmyMj6MRd12QonH9tOF2dTTSO7+V1+gJ29eDHSVadiU6MPJWhZZHDIbiy7JQGk48gpJaLNO5uuCEDmeEK7wnr10Mc8AqZnSoEC.5NYmo.PRV5.7Gmn6ZsWr0qEIAVuBZcHfNe276dv8y3XRznL0MHWA9Vs3l1EdRjNPvtNQ+0KVEyh1ji98Rl8+zvJae5mIAf6JLJQ3tLvREGEYzf5msB6ydPNshNzVHlkzwFs4tjvvHWNTn1LGszBkmWcfhi0Mt71blcM6SD676Fq37qD8FmrV.YTrmEJnLOYc6X.srElIrQmvMo1i.8QVlD5BWRQhMt4xg3gqZeBgYah80hE7yKl6.2TbQN7sfFnTSkBhF3ksuCHTK3o97HKXGcugs8q.i0i91Q7574v9CHG7Abfgxo6J3kIqMtuVK6CGeq6CeITm0JIJbIlfnYgEgrBZTGq3AVBxK6TOOHIe7VRE6pSToot9a.RvqOQg4m4vFAuycwxvspr2xr5PZKmGF+u+nfyNhxIYFGrCYZ4Spp07MLD4I59ztiIcCfRNxPHAXQWxkMRwaa+Yp9RRqSUTodpKZ7eLGYjkeAfeavFu8vOOBsK+sNN2ocxOanZrmhcBkk2qMwkHTSLIgn0BMno0s8tCr+PAxxJTlg8.jWbnRI8BzbJUAX8Yh2hYT1ua7Y4RQNIOeZLOQQUh+DA7iTQFnEaZ5fNKMu1uK40sFfbu6.MfDDxvLtZSRpjxkFUzT87l85WO7.4EKzLRk9.1dZas9bXZ5lFhNzHP4S4a5ScdhQ9TNxtOjWGZqApOYk8uTQY89RLmPTPzvJXVp6x6gJQVhgJGAUlnWEHb1BtTR7lUiCrF15Jo0LvagvmvlIGJ+xohPhhWloWzU2Whh41ZZJaDYZNOvmbdV6cyV4Bbn16GJIyYYKUsX9.1gzk4GRDUWXyrxrRV1N8WTsd0MUOyRCfB4gCwTy4AH0Fmi4CJuWo3sp3jKnpOrI2RqRlfSdGACCF520Os39WaMzXJXpLp4qc6n29uPu8jIlRgwlw0HCBkRjJdFm+vgxr80ex.mc1HuK2SkIhPS2VmFzW.KPUSGm619gDWD3EmzwKhWyFvS.YVotJwpg2JVEFShCeVl1ui.5p6ca59KP0YXtzrdteqQ0SfFGqpa5PGWRjq+faB2OzoL75yFc3r9KdywyZR1sHIe7pm1ISsbqWrCA2x4PskxgiRYy0ChenODE5iQoqxk4dDbHDZAPC8sxvqLBxgRcv9nVT.1Fo3j18TO8AEICBHtOjP2xNgjnDRehQMJJuBYzU6zYRx3Cr2WhtTtGGi7R8SHdgMnggWvPUsHsMCA8dHk7YiOD9aG95I0epVdieioMjMW1Fek9zvOZFsy4jhiWw+fZuCZSdQkb5TkWCh6t4s2XWWYoanghKiFDQTHlGciS8nE6G2zjfo+V7zCrGku9MAlGskZ5hnuS02VSM.7nJNU5eCNVBNn3hWHUzagLRvpcq3VV2BOV8DxCcfoKy2XdGUJW6d3qruNW9CXOliuAHONjaDNTLP5oZbyaOBbpf.U0s2WA0sQZkc7g6SkuWRr9R0VZHmLT3.BJ.oL6bGZxb9YHOl5AlXIdkmsP2mUtWbq5uJSdVbBwOIbv+ssXArQOH+iemEtL+Oa9Dbl+gRREe6P2pfmx2sAUxn6yT+xekkYq1amOkDx0nvtK9siei1jpuzqHp8yI7lyMB2YqR0bW3x1w9UC0QZOIwMxwAV9lFTK4I7OMvxuQ7DhPdSv0Dvp4QBJRZyr.sqNhw0CjiWI9XyPOuua+dtVsMCnXqovItjoUrPP8pbMx9bjUFUwyi82wqlnNDSMKAq.DhToOvgmMJbshQ1U4pr.go7x67.g7WbDEMxmnApkaSnzDnkiiPaXdj89RQcfzhyYJu.vd1IOQqBFE19Xtp48C4tIH6mOkGW.vP6spcRKzSo9GzXB+x6GcykJfevT9s3vMFDB8nTWCWTeFY8quuZfJLaL5hNyr7JtutWOqU94pN9ahGBHgPtk0lG1SyJJ2apNEWXgkgj+oB1SEP9QwZO5k1Muns16RP1gxGF2aInoBSH6AOyPZaNTyVWECRAuNx7tkIufBIZI6nOtQ20+hY0qFSwnW56s18j6smBxM.7Sk.n1+YC2h9C1ho5UofPcqly5zhT2.JCDi7uqKXyEEKXM1EhQHZQdeW8Oj2ifFJDmq2UWJ6..nFXX5onIIkAZqpl9l05OwG5rkioK9gP3kHggYrIxjbvQbttgSNwYEg1QONuR37MHofGW5N3IQEto8aRQuX+gHE1vOjFL7GvMDIsSk01mUxwDU1WTWJ0TugKqhZK4Xv+ADoTxt7r+zkjQjgrjnvFG4xBJaprgeQHA7HSQzQwVGVi0laAKmxxdkU4QTxOacvt+zySqZvsGSbKFNQ8v4+5aEDT88SX0C918DbjPw1I+gRTpVWn2.Cgj1fYg45OqSqOkTAHJzhWfayaxK.T+mEaakVvf6UzK77tTvi+aEupwQ+VzebwKQQAvOXjchObg1YG.kF04nznGTdro04iA3Fq1VLB7Xy6an3USe+sBDJR5MP+XpvthZDeY8HWcy4MqUr3FZaVjCTXUvEGO6.2Bvw6jiVvjc3atVUHQsE4PNoU+VJPZyirSGNZ9WlMeQCE2.Mur.TDzoe+Hd2tuFxKT3f.Xw5eM+VublXrrjTzevr0K58D18IUrXZDdW8zjqLb5mW+BnfSvVB4B27xuvRO1GaBO+2X+CyTzMUllS.pvMge8ytKUue09Nuv.xDgo215WzP3Fyogv9VCNhGrrVRlU.SZU0Grd1.g7vIaJ4BzjD2o1PpU6R1PArvadbwayGaOj1PK5VZl5zOMt9DbOjTaCU8DEdjMZMzY8.J.VWsDdPUkerk0ARxZaN9XmBXfEkON.CDU1uFHbinX4aAwPRLe+CYYR9mKzboobKou2QiRflT1gkqvSX.fLhWq6ukg8RGsVepVamXK60UdcGQ+7S6NStw7AeZouO9hNq.Q14FZDvnlPaRxAaZad1zSZG8i09nksbRjtuFCVFBTUSFPshGJaneXSOraUCCN5r8NGl3y9r2oMVkYxtYC7Ys9MLqN.e1IBjUwQ6Ry6irKFC0G0DQbPv50Y3Naare42rCOdZN+yJ4fWMR36dZXh7UP2Zyj7GH3mIhtIuud94uhX0mVo153rc559ZN2VRiGoTOLufd7fOS4J3S4Y.auMcqi+uqT8yQHQMT5Y2xqTwDa2Ih+UcmkrpUqQZ6nDmO+MCbormTMf7bSQRka1LZM0XsBF4744I9rMk0z4RWJ.QEcQtW8FXMqVBjUTQSDMBW6RUmGGVZMExLK1Mqlj1+1CizpZcz5dNZLs8VUsIDSNqKFxDh3h8sSpOn3wkxSqYjWA6Pjxs6jSFRiur9jOcTN7krJd7makWOlDqx7kSyj9BA3BDoFjAXs8txLTD0BS9GTlqf6WJa8iVFeaSmCj0wxMB4ysE61jOCZQAXeyvUA61vPr+sKz7eWOxy5nrP36MKnuR+riY57mszy6HOu41XhOLXMx7BFVUTXV0sYpmKJLSBaB33RUtkOS3ZwaD6AH75C3vY2M1frRev5t4eJW1yRDp1OY3XsZcrbmuD68LzlvABXZEoxpcNfSG1ZdwC+Lq6Kw8aAeGymgT6hx4wtArJpaRxTeJxQCHpvkdLYykCDZkRpPmfBwBhXRqVh0Z1VunYTOmCg7WXj.hUEISi.ehkknj7Bn30KiTlWys0kCy4I93iS.duRN8DhkIj3GUfJHARlMBZP1ZpapSvFoa25a+1wZKFkwnwBKDK5BCCgTKWdaA1HoOGLi6tmYCRAQCgYgf7cgrItlpnqFhxCC4DS2kkdHlFsS0J+SK9H2X2KxQwzbPo3QQFbolmrAQAn.EdYhv0w+u2PNbJXI2F.frVdDfH5K1ICyXmTWeaMiI.An1EVyupiv8MO0OWebhQhXibpJ++EsGkZrO+MD+vWeNbSRt2kYnTBa.yu4zxR..YKHCSCdvyjGymicecBWBIiCBHM1JjlofnwhSQmdnwV5mHccS+wirE41cyOiXvSjYmVXFucU1ZjgdHIuaftIxRzlxfVEPnrJuO1sbxwsbX7pRPq2XnMOsIPHEHz4pvh783g0hUHW8j53WmBYknRJp6jldYvt0dBqqPKK2wtTn+KH+J0tkues3s3fnCdOztinMCli7V2gWULUIcQiUy2qQMlAWAvu8+1uuZN5HeFhutHrJS6Ebu7o+PVdICsMxbqxXNCoYUMMXix7V+GVEzR7nO3x8Q7jNiNJCcpBMWiGIJyZy0PDznXvMP30UJA9ZaZJ.FdNTVjuwpuBFqK0c80hOfbevN9t20HLfJ0m2cc0tiRNrsgZuCqSyjdaM8uaE+wXpwaPdT0Vy.cMGJmgSkIUwKRr+x07EhsTM4SRA.8CnMjoGXnX5EBhHgw2X7JSZDa42PUEgNCju2VqIAgMYT8UIJVfMcZxBA3dAcXwAioLixzlL.EDbTgdcX.kG4qqzVZurZNH3GLZ8S581kjNPDIEIXEq+Q7rcv9gm8m.dmahv3ZObWy9d+ef7vt1D5rzyonxPxUaHjBfkK0L3QnOcY8myqR4BVHgEix5Eu9LaZQm4e3SwduIESpVSeMpE05ssqMjp5cgHxU8q1uEN+xqHUBBe8foDP5iVGCg9KaYRFf3BtFlbXviyguOJk8AJjsT9TCvqw8QYZ6kPZnmZv6yuYHjGlcwJoI0pTDsY8wCowCTH8QJx+LFU4S41OIYwGkE.cHiO6rgl3LXDtl51ENOdpNlSSAGXRelnruJ+8+hBzQ6.zN5r5zBd059xg.3NFR77vF7Ixgdm.0IR5gKuaHpBYlXXAmozMi0sCHJIVuNjUml.W8qp15KHwmzlmXkbR+UG0f2zRUTNJ91h9FjI1rS1Ibd6lTP2OeBEcSHl5Hes92yuF+nOsDk9qwtDM85F6LX2Ait6tLjQhmYbgq0IGRZhMPTdflI4J0xtIDiXtdcyH3KX2O4I99YwWEW5XJky4TDJkRCikG3fYSoMEqC5P0YA6ySaqIIpoB1AqwiBggdELb5tFDcdBROreHD3c5BBMnUmgOQd3v0+SVpELeJzmkZRftoIYSvBO4g5bk2IKU+DXBAx6phlt8.7KZWZYv1WVkiBPvDuv93MWVIWrw11Ao0x8K1rLHJgak+f79jz5lrWF4BG8vsIamBJBhHjBR2cPJcG.Tuw1GpOmVyZ5rC7iCdoB2LsdruqgDtssq9rEmr..amkr3nPAHJq6J3SjhUmSWfP9+Zi+AeJVSO690PawHup3Quat.J3JT.VnPOCvX3qCs8JS59lHRfD+NPVGHA+3ySka9tTrtw+4qlOl0RtYQSOSNtvoTlb4D3AcjZgSZno85rn.7h2LSsAJFbfgx2lfkrp8VR3+pvT9ynUPv8rCn2LrtzG7KQlCKRun7XZC4kBwuEVKSi01Eh245fH49IOnyhswCU0OAX9WhvDFjgAExt45D8OT1SW0tEHIarTflIrw3A.UelGoNccDi38U.EeOYnktkdh2n9MUdyvoNbcQyWzdojpjZAYEAqeGOWsdA2u+PhTeE5MTQrZYX.GWShh5N0IlEhfxWb9J6wUwhhmn6vexJ1MDGaaZx6FCU7dqFIB4H1Cyb0trui3kkdvvRyHk8QPB21J8PYC2WsJtSPJ3rOTMJok7p3YVj+UnaEspWlSBK9CNZyisXl2jIhJ.Xe8GllFVIBjhrFE6OnoZk3uZlsmtvmHMm88FuwftH2QvMX5vy2FdRbHMnoBB1BGqZuaFTQo6hq9vkt3qVqHqsVqBYoipXCqTUca9HiG0wPTlN+8XkjYXS14KN0.8hFyUZJ7dRtftIAkuKuOO40hthDFrofe5VOH16KcLAnWY7gxJgVa3GjLXq9niU7IJnbqJEikCHUOYraTrOVSn9CzlAhDPILuMG2lNVw3Ngpvzw65IfLAPbrwve20iTbpcYQT8g9pBuzXSk1+8s44cC6YfxGELMV7IjJPYNmZEIv1zaesriH89PzMxooxiF25jJL2yajS29Ecxy7CKq5GDEDPaa6YmWn5d16.GVNXbubbzIOrVSH68HfCpitRr+4nGfw6hsy30z9TucW3YL8.YUGhFBbtmzfYVGaHV23SQwl+YZCTZB67c2pqTeq.09ExAAULkjBkCwcyEnqwLoffk.Y+Y7VOOPEk1XrrVQx2mv2c2t23I49bOlKxjGlmonaHXN5aFzIf62bgAIxVCJEELLgajL3lcNjPa3JRw0QNN1GhQQYC3dG6zeXZtkQax5BafU7KBiObs2t9tNhGlcDRA13EZ2VCOcEsttbQdI7h3QTXDiZ9ax6M6xr35PzBpbShE9fxB7YKYz61WId4lLnhpjUaQeYsl7fjAd0xNnjmVppdBDg6UbxG4w1bLEFNsFvGtCLmxwV8P.PkfTLHTyzi9tbr.tysDuW82IBYwIQBP2MyYgo5S3lj0CP.r.ShcclDeu0riTW3WYwZgjU0n9AWxEKq2nfa2HyHm8qVhSaFWCd9haNOsvSLmVq7FwM9tLLV3ArYNk0J2rai5trEDMlmIBpDQmpAkVkI.HIW4YA920DyutGEsxM6rb+uWh0yFOK+i86Ma.xPMSD1zNeTUd4qbAe7ZYueJV.upH45mgc+yf57AAvnXO4QKh5NRcI0eKWzhgn5KeWOEALcqanQGtt9p7wv.6pSzIAleMs8DArxxeERZDC2RLMqfazpS84R1a47osrHScFg5dbAZ90G9peMsrQORh2QSUcKs1C5ecZsQpca40M7E889dItQvFME5puopySbIY6HQSezfW6I.ARJwa1QMTGS7TpTN789FD0.3eXdc.tPvUsVsaSRmmGejlTpyt6B73+ow9pta2YEjJn3frZCs5eTHipm1SfWe+vALXU24Psqc.s7gc5TWq8DUU.c+O8nLA.TZr0hr9T93yohxw2DE2fkExuEl7w90r1dXQEh4XKLhx.U8G4zx2FthcemaUwqnBJrH05DdM.jxmE.juUR15Tjt36dul8u19lODtrhx1k0WSsiKSWyTtmjDY3GmL83YgD9wnT28pGK9eZkYdnvrcPU1mihXoA8.DLa05KUw+jtiTeWhP299phIIOaogQ2J6gfwxPSXQOC+Vc3OkBuIxdF+dFEFFoAXgB4.+rViTWd1D13bqCtyEWPik0h1o.msx1BRCICy+w4+HVS9qyu8SFVchDStWt5852YiX6dh6HUt++ZFIOQIpIa62a2FrhhrHjVcXc.+4Ag1efSmH0001t+91S.BIZRbYYIY.mpqEvUWtnnFq.3klENrzRKTTEOLuEpQuQ2O9jDo0Shv5bP95hGZzLmQ7gtCBj3H1ycCAmJWOEHgGqYWFqIoVKo9XTNJ6dPMtAm6RiAQUhiJS5vBsIlcHx1ae7cD4FirpgEJo.woraM94hw5.h9cqhEpL4gPNHaK2wnIBA.UnSxtYnC.uTe9O9yd7lWeKurFHIlUpJzW3JAH22Lbql2I..v3NzK8fk5QTS6ZnR7grB9N1phygSbUf2mS2MWr8rPt9k36bqZkPmeVa7wOso0DuxU3ZZ.2F6CjF2vhgxdwloB99UTzL9n8CzQKGrV9MPY7kejtJueyZvpZe+c7aWE9O.fpq.mCSqIpHjy5V0Fswcf94sif9G4msu39pyonMFnqDjgPO8X2KJ7+DGGgDHEpyZXb0gPAkF.kuKkg3KDIGcXxky8pfRhPL.LQNJyuxYR6WOXIALy0T0kQJDXYxaEj+xS6+voxmRP9G8KGKMidzeZ5uR1XcwtKk0IZw6G0qGNpnIJ79uLMx6oa2OKOlH0WvmXmTzksUahtHyaCyb01ID7TsAgxRWpObJxAwXHvLTn0MTGRbJbnMOcffIobh6VOYimN0PyR8Yvdu0Mxq1F6a0MoejZQ3z0RzrOd6FV3Ls9ybHpO34ZbrMROaEmU7RinwntB8wGi74lH+C6xijl84j0+tQI9iAROOvWqpahkqeEymsykaetyOZhUAsCvJRtFPEwD+hc5hjErZhFphWhjC5TQ+xGU8TFApPTzi0gPGPshsLUapOj2f+6yb7ifFqcDkLBmWK0Di1mkf7hJQyQcPSQB8pRRhfPkJI0h30n9NivLFtvmybuWxzXBw1Ou0F0QXLKfmgO3ULOWn3ScJHrvXcQWhNC0HjmcBmXJmlB.SC.AwKhZFYODs63pQsgKtVlqljVcyIk410bgAyAFFKssQ8Qa5UdmwV1Qgu8c8GjDYPQ0+qBAarmNRv9dxormEVdaMZgBK7Q1ZcHlxkfNqAcM5R8axnKXHKBp5X9vDK4GqAlpZuPg1UvVrxsB15GrVlDUAub8KZPEGGm5TeKEbHTJlj0Oj4n.AzFFJT+v4EDkI.7r5h.vRgNUGR2vTBskBFMZ4vpV1ynBkfQXsHGEiD7xjcPB3GPZc86N+IMZDww39w1mBsXOOuKaqU8Ye6rA5BxoBEOSpHD462MlLLZJugrfOu17Ycj3VbP0eeZfy7hb1nDCSXwvQ1H.c0iEKxXU8LT0mQ7YUyGZD208M6zzM3qjlaKL9ors.VBBQTFi4LrLf5elJZQ.Ka8j2+2z0MgSnpex6U40.KAvVXQWr+nGay63rS23G.1yQjzpiG2ENx80n4gCre5.DohNiShFvUeoPl1TngYsJ+5pClmynK21XfNcSkNqMMUDZcrh3iijRm.o+xR.B1ZzFyHrNi03detdrG+B1WIakG3WGXKYsPZiczGh8d.1smh6JNL9SPegcd6MqWh0rGqJ6yw1d90BMf2yN7UOf14+zsQcS203H3gA7vku0vMzcQMs9N77S7BdrekFEej2KtIdGcLe9pMttMsK+xCqpjU87lqOrHUqF.ExzUM53kI2RUoAgaGVjkyVLo5.ET.HY0lbQf5GRib4CbsWwZJAaMB8B6RvN1.afhQTRfM7rO3kooUM31KateTz5FjKUQt0FdLYMiLp.+wJzpaQqVWvGnN65SKA3c4w93jhC7g5LGHiYNCNIorU6b9ZfqBh3cFoV4QLTu7d46nDxlP+FlhWJ7Ohc9MPs0bCrxlq.DG8wuuzr5.AJuYWehXGk0CTEb0YjIfsMn7PH7cDhzd1NP8xG1egqe8Xkm6xMtAApGSZQrmnY29U5Rctk4hHX271kdsa9Hndx0nbi74drTatuIIE9dWT75EKLJktz68r3AW10fDeoooQWaSwkT.iOA42vXdgyJ2NEI3xr1dwa.rhpQtsDSy3o513cXMxNSvC1boMcl0cAZjJ9EIaVDAvL0NOueqOaUoh+P+ig0SAO8T95Oop6MgSSq2+tB.YjErk5DcvH.EmXetG6f20qPT7hiy.iFlswqQvtgpxZmAYyCpSqcy58z2lrsO7IolD8DXreMkuwRO+tYqj0hud+TpAqhkjN.qqPACNjGdsj6QHdl4MV1k+EQFsZbtBQXi6HtolXrnw5VICQ6DdNxebsIxkEsOSIrscGOZ6P5mY83Ffc9+Guq9uhNCHFzoHgG7pnQC+Pa+.7v2ie2rLo0EbTJzUKuSMDP+6svaZXAnUsnWEaYC.8+HCbLGeVvCgTsOQIgk6EWGeAIHUVSrIdazSz3+QqrHPYMazkWZanyTVyNfMSNkOtnzaJZZwsJblMd62gk4BBw4LcsDg4uh1ToIrPrW2skYjg21Sm2+BqzAi.cZDGVmgN3reH62kjVPtYqkmjGI285LNaw4kiVYSoRAuoReTMOzjxhKM.xO1wUInPl.VhJVFtkp1Nu99HEz.SeNn5x5K6I5ZgVBXWcrB0bR4F1GBXt6q+YAKxAd2XUyYeWNZM0YOIsRcv2dJjghGCgZlCvQ2vZbeas73x3OvXLkHywrHDSkCBGHmOrOtmrFvctT.Yt7gxYvnrPmlLQ9k+TzdMZpwN8Izk6D3O6uBIDbhmzqFNA6XrbeGq3F6A7sDEuIzsJn9jLyq0dBFiz6ZeIyDTVH25BhNRq98F9AFE7NwE8AAJRDNp7l5.WfXK72Ufz5JS53H8mLyLfHMz+5G7Oa0HkqSUfwrxaWZ5FAeye9HnCG0CmpRIMIV5K6KlfZMxBZHAvRlmC4lpGoGf8eMkfcLOS5Oti8Ibwemw852KGwhgzGs042uAELcWpIi1hVgkmD3+Oxl+SnuYUS4n0DxuuuKFkf9AjLroTW9lQlOHGNZsxQa8Y9QiWdXzGUN.0vecdmHVtK8PGGv0Y5mouV4U0MHqtw8u6xU.ZD9UQih0l3gxYXwykD4095W6oP8FMSHWueHlKV.eMpskXX7wOxL3iFfEkUPurhXRa2ESC8b94LczkUHzrX21HjXlWKX9.JPCxYLyabDWDVnYNhjYCKfUSgOR9+Wn96WriUP7ju6tKLEjzCWNMdBB5L5Pgl2bCc4OgWHfoOmSBGSVpZWGTzwzLkTgc2sHRefAs60ANoVmCoVJJE.rZppVX0pINlGcTkGzLdoDKQFhxzCIBspeO2cFJD0u2hyMk7iKgfA6r4lSCYzECN.eJX8jz+SJDWZfxjWE.0QNHmuPtRRS6TGOBp7gJJTihWEiutssSxjIU7p.iwzlntx6919VB.kE5ldAuLwkDIeWWDaapCWVtWJgTOeDcWsZY7XQDCeTCkVmJHMyJBJs8eVPBzAus32H7yY4ORejfvtW.t6G1QKKRMs5fN5GR+jdmVlzObwakxc4maE6ld9wvyu0m1QeozCdBUJuLr9.Z+UR3UYpsg2hYvLMmj1VsBFB2KWJ3f2utcgQg7VYeiZZd.5Loo7IGk.73JoWo12DBuyLbUGer+9H87yrnupqVVm1JBtkPnm5OA+L8xaYkUgN36AdoLG.zD59DQKeVnfJwMHHRf9R7Tlmp0y4rG4liGHhIK9C45Fgan+pQZxqpI43PSaizfApSuumFfjoWHO+LEjYyULPCRxfArFTKJNXZ1u13Cs7lEToO17vpg1WkUHiXJL.SRVgI2pYeeUZO0m0bjQ0AoxqfgRcU5sgBiOugFxN21lwKb+frUZAUZ4a3PK850IEDRg2OzfdeeTyoQEojn0j6fxM3OOjBCCPkOGFIQSSzwQ.2sAIrLSjV4vmLmlCEvGdj6TCKya7SyL8zVLOC6ADlOJaTK5I4RpjL.FMk.X25958nymQhf4NtXc1GAYHA3JSTHYAKzMsZ.QYdL1gtAZv2PZP4+jxJLxr+v23uR4XzHQVe47jUR3meuCCyKQIZvM+FdAreAlj34WSDvKezZjhokyqmFfFrnT3jgx7YxUUisI5EKKMjU1qhMoqVZJg9B9RmdNqixg6GzXFZBzv4N7qmbPHAVEHaGRIHEj5gBPz8.JkBTBpSDOeNVK1vbViK+njSvJYL+M5Z7em4PsJQOTDEgFn4t3fiIepAqT6UD43FBtQ5v19HUUnZ9nfcgLKQNl2+aDGKCxxYh0b25E8vMmfz6pACFAEiOOA4Y4CwCfdC+xe0EmF0Q1D7INMrrxiwmjJ7UKaMBhMG+gaLG4D9WKtYIVcEKNiGg5IfTpkbKxI9TkTIcmCB2fUK9VXgC1A.nnjlDp6z50WZm2MIxc6UZMzRGj4eynwse9PICQbG4wxuq9Z8mfsVlE6go.zkva9kBuPT3VIAwyf1ghXDsSQyzA+BN55Bao27UifwgF4uMkuF5afsFSpfoV0dptHf+C7OkV2cRPVCgkU+z5kwOvKmFBToMAXlFAA0HUZ4ZVurCmtqMmgporc2SPYSWpSDXO5UgtgWzL6BAzroDaGHyiB+xK7d40ULqe0w6IXuX5U1DUGKj45xSriq.kqoxIIiEToY.nqm8ke3lK2acf9FPkKXBmq5bItNS+QwORM4+8P8jOK0.gFB2Q2UkQxkPoFQf21TaUZJ6l0ItQJR9FVO3Ab35g1dl7ayNI9ky1bw3c5NBblhwB4qGRLjqL+.z.MoBOQ1ogkivTvWMp.sYKlg4bA3Jmn6FebB3LoSIrYJ0VpsCv31R7ZB2IiVORhhfvvIxXlOtbars1n4y1YeJUtPQtv5RzV1bYRqFy+lRfJtMBeaBkFfRHu41VcgvCQghFfABujjsutoRaoeSkkTfjAExvqHqMv4RZX6L2NT9uGltDPYIlJd.gG4eGJYw9R256oOdWosN38zMQapKNy7N.acdf6tOWbPdKYou7CzhEYdkws5ubPp99c.0n+1TskviQFk3g+tnMaSSdOVYnsDGQZCK3b3AcNdvgkto9JyHbKgkeBiPA2eK30ORdvr0iJ35uuBHSh6.GpKZguhvexFGMZRmfGA7nxYzrOTbB30AHuhHui4A1JT7UIOyp18GTPk8pP6+Pp57Gng7+vkZ3AxByMScHvnvCJkd1Cmh9Fc2rpQHakOujx68czPMDZkFCN8AHndE.qAhoKXjragWWI05ubXptI+ccjYArttuRGw8wCdF+E89CVr4kJgERuq+V6K417d9UrRiJKFsQQg2+Yd5IJWjmopy8zPjChamL2iRgitC4eOMeXpRjpI61iAaPcxlD5C1TkqTADDe96RyO5VCA.6iknr5FIsxd9pLwvRyMQXk11f855t5JnAlCHl63aFXyR1hrgzeyu2NnMHxu5lAo5sOe3ACw1g3Z9kj35r7n8JRW0UDzGjHvrJDL8m8bWVAsry38HkdByhUPU.yt9MKYg8kki1UArRZyVL6KNKy7JS.nNa5B5rJNqiORhS5fupsbUod9N1as59eprqHz1.zK1P+IIdiOhiu29Xv0CGphv6eX8KrDMcCZz.PEe1NqBgZNfUaJkxZ2XVZ7mGtaXFRDqATxZPy9Ly183EOJzrr4N7qaWDvtNsKxCwqClOvCXIc6VpBop8Yob9O0qTSfVL0dGXBN30XQYm0N65CijYm3g5bbDmrfA3reysCdh7On8A3UXnU+Cbp3CnMjk2AmDeaUE7Vaw4CLhzD1slPHSrsRxzTSQOtrRhCzWxy4yfdvpwgLxKXeWJac206oFBTSAHtUsxHFH.Dlbz+Ro2QyWOnNEaLHdmjBmPf+IUZHeO3RxI4ogVC1BA4L1SYVxBeRjQfBEU1AUmWTphmRbEUj+8JhkFAP8DC11ImvTgfUzx7usV6V2JE+QCbrFnCqEo5PqnCibzDvKeaneVWY8dybBbzEn9r7jvypnyH4s3Gfc71eNL8x854wH.3jHc5faUMOuSuWck4siw6aetWnywP41KDBuWw9muCnJTDqF1qBve.k2wwQYLUrH+k90.l42prmYIbQWlLECXbvcy.f8xgkH9EVKpRdct4HxxsnHK8Q9ik5eCnp0pwGKiCCIYkB55INre3p0vLxBv60YBO7E2J1ZI86SL8StSWyiOHB4tkAY8yR0yQRtl8m117.dIxmYKRw9.Deqr5.cZDaEMAHnzwuPMqBzuNo1xhGPQJKSGaBsdknBktSaKNbwA4hr30v1NBXHzqCyXz+g7VsRP3xDmlk1gdBbmyc4pdsV7sMDofL6Mvb18l9HJqswZMIhvFrOt.Z4rR7B.cGA3fiZlR5DZqhlOZHC6Kb5mfEHLUNSQtVz5fMvlNOyc3+KowWbzeSgb3byniLk9+HBRsGFKgkvMFKiQbygWIVUvaWlLR23V0QVT8y4qtaZhe+Rx65g30S6G3LfaieLzRtcr6Xiayl+mG0SnTveIG2FR.hcEEHxnZv7grP8c9SilYe+Hr7hZjVWHsx6Nj9lqVNqbd7BQImQcv83V.tTDzkdUWvQzn+az0UJ4HOLXZURsb25j3mIMty4lzWoQgK4Bd+lgD2T6M.d1NZKzjZeG3eY98HwzCr19sz01qE7AtwYeRDnfKjtSBYcLKzQdiD6bfmnH1UaRy81lCs4gMXa8VNbVXr8SWP0g1PJDylKXVnZja8G0BuWV4rPlHLXwf.xJkmUiHiTLnTJkkHlxT9gW7zkegUQu1tACBi73kiObUTGtI9ge5u+iux7Tkj2vcwVEX+2FVad+hbEw8m9KfJ5ANPSCDVT9yXcuTNrQIgFv4iwm5+Z0ufmID7AjtaKh7Iu+EViIUELz+8zikqJNc9NfnAVtMxZQMCr0nSauhvxSUEB.YVx5LqIr+BXHIvhjbe+FUEObkX2NjUHj+KX3qGJk2roIZuGRVljfmxo0UvfGEg3KEXlbzLbLOHyhY20BFeef1NgFO6EmHVQLnxWYyuXMrJ0eg1pNVvXITAflV6wxW6HuSs7FnyDUPbbiqkpZ76I.Ror8YrTKLiqQzge.9YkksrSQSYzC+ynCGP+172+DGFGHZtNI3K.RNCrIcOtOchHt04ifPTe9YcZW1.+uuHDmfSnw97AE+egLcHaIyNHdfU0Pn0FFkuQXQtImlZiEsgRJb7i5BPa.L4.XYUBgkXhQip8eAoPdQIYpLj91T5Rq42p5sd3Xmh2NGRrqhvw6ze+NxEBuIMjNpVaLi9pz99o54NJjUZR33ZlQRJWOvhzGimgIu+HIeHb+4O4zXxz.DmIIouq50s2G9uEsZzZMX8PcE17OXNuD3DfyGazbkRtrYrJsApmhYAFiursXScjFr82Ce4ORZgyZyjlCFU.atG9FvqC8VvpH9XYLtvP7JRBFd3BrX8nQYk4yqTkTyQcuR6YIhsJJ2MMDzVVRICYLGXCxvEvT2Uu+8AzSgd.8XJM24bUHkGCVy.rDN84y5G9EndyARzP3R1pSa8JRrpZgRxUI433yLROQTsvmAeGnL1NHfb8HyjMbtszqG22SFA1stv3CtV4V1NSTXAIJ4nnXn7yP4Wgt+YAEIAZQJrkvh4cg4midclqYe7mx3NGhegaujBHBxZ1AVBPwVGLghwVUgYIjU5rVyOBLhdS+.uj7EnJDRgvx54cHLUvhzy1NnH20O8.wthPSS2P2AjhSrv.mpJTF7UcP5qI1ZLNuBhh6LvqK56zJYsoTB5tVFBbXIESVH8fAwfZl91ifu7oRkjiihiVZlJVVeWfIxNosKuSgCXUB9VqSTynXVPLbjCis7BgfTH.r09.34fvIeD436cnOtloltpbxUYPLjjk+.g8r2OAap5g.U+mmp.gD0o5eny0hyRt3e15WGNAYs5IC0rvLHKRv1eEFR3y1tbzeOPfpCwSlVLDIxJoLpG2wZv1.sExcE0VXRL95WTTDmp6GgZXfbSM0Rnhe8iER1S9wAgKvYwW0HtYgxZE8rfIzaaqH4WVFsWEcI5p.iywjC69KP1455.4AQfyjt8vPyPfSbBsJAR2VNdGKT59.aOBBNrEE5zgtI7UPUo9a9qXJxjJG86jo+c9hlJDkXgwTBk3eJk.u38laXRo2b1gKDnNZ8OnBL0LzhblBczALlGTYMVzty1uo29EDyLSFrWNP7d9Lw0070JKsHBarPtmKt0ouIuhE....P.A.........P5C...zrTRNQ....fNA........D.....ZyklaA..........65Op+EHVPwRJlmff0naN4JD.........MKkjSD....D.....F.........PzTI4T.....A....D....fDPh5e......Q.ZL1MpC..+ifAETiausjkRasV..........P..............bfAE...........................................................................................................................................jdXIDPB...f54feYE8cqgj8OdBu58cxaY.........................................................P..........D....f.....H....TC.t.fM.3B.3.fK.HC.0.P..........."
									}
,
									"fileref" : 									{
										"name" : "Kontakt 5",
										"filename" : "Kontakt 5_20180208.maxsnap",
										"filepath" : "~/Documents/Max 7/Snapshots",
										"filepos" : -1,
										"snapshotfileid" : "0305a9048ed4dbee942b9b85a72531e1"
									}

								}
 ]
						}

					}
,
					"style" : "",
					"text" : "vst~",
					"varname" : "vst~[1]",
					"viewvisibility" : 0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 396.0, 501.0, 108.0, 22.0 ],
					"style" : "",
					"text" : "Port @track organ"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 11.0, 513.666626, 115.0, 22.0 ],
					"style" : "",
					"text" : "midievent 144 48 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 247.0, 501.0, 107.0, 22.0 ],
					"style" : "",
					"text" : "Port @track piano",
					"varname" : "vstPort"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 94.0, 215.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 32.0, 215.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "65"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 218.0, 235.0, 39.0, 22.0 ],
					"style" : "",
					"text" : "Hub7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "int", "int" ],
					"patching_rect" : [ 217.0, 141.0, 43.0, 22.0 ],
					"style" : "",
					"text" : "notein"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 9,
					"outlettype" : [ "int", "int", "float", "float", "float", "", "int", "float", "" ],
					"patching_rect" : [ 76.0, 92.0, 112.0, 22.0 ],
					"style" : "",
					"text" : "transport"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 309.0, 774.0, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"autosave" : 1,
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 8,
					"offset" : [ 0.0, 0.0 ],
					"outlettype" : [ "signal", "signal", "", "list", "int", "", "", "" ],
					"patching_rect" : [ 173.5, 653.0, 92.5, 22.0 ],
					"save" : [ "#N", "vst~", "loaduniqueid", 0, ";" ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_invisible" : 1,
							"parameter_longname" : "vst~",
							"parameter_shortname" : "vst~",
							"parameter_type" : 3
						}

					}
,
					"saved_object_attributes" : 					{
						"annotation_name" : "",
						"parameter_enable" : 1
					}
,
					"snapshot" : 					{
						"filetype" : "C74Snapshot",
						"version" : 2,
						"minorversion" : 0,
						"name" : "snapshotlist",
						"origin" : "vst~",
						"type" : "list",
						"subtype" : "Undefined",
						"embed" : 1,
						"snapshot" : 						{
							"pluginname" : "Pianoteq 5 STAGE.vst",
							"plugindisplayname" : "Pianoteq 5 STAGE VST",
							"pluginsavedname" : "Pianoteq 5 STAGE VST",
							"pluginsaveduniqueid" : 0,
							"version" : 1,
							"isbank" : 0,
							"isbase64" : 1,
							"blob" : "7146.CMlaKA....fQPMDZ....A.Ec0zF...P.....fPDMfPTXowVdf.kbgMFcoMVY.................rgqPImUKQA..H.VFQETdtA..n....fLvDCNu.iLu.SNc.....UZg41azUVbfLEUAcTQfTiKx3RLuHCLwTCLzHCN9TXWLnjVLzVfs.tiB3A4VSFarE1Ua...zQFcMImA..PD....DQCHDEVZrkGHPIWXiQWZiUF.....Z....LzavkmbocFZzABJikBHx.SLz.RSuQVXxQGcGB...PEZoMGHvIWYyUFcf7lYlUlbyARXfLFakElafL2a04FYr.RduUGHsEVdfvVZqUFHz8FH0MWYfjFcfX1axARduUmbfPVXowVdf.mbgMFcoMVYt.RPrM2afDFHm81ajAxbzElbzklamABbuklazAhYuIGHvIWYvElbo41Yf3VY2ABbxU1bkQ2bt.....fQ....Q....PDMfPTXowVdf.kbgMFcoMVY.....rXA..vQRUUU....F....Dv..2DUxsF..TPc.7u.O.BToUFcfPTYfHUZjQVYxA.jpjBd.pRUF.4JjLXL.tRCnAIIpH3A.RBGx.4MsDXB.dySBZFj7DSfNAHOEYEjqnRA+rSfLA3OrYEjC8hJ2.RfX.3PRQvMqnzJkDXDP9CMHTRIxA3Oa0SIMIEjBsBBlHRf5.nPJEHKPlSHBRAf4nTffXxFz.oOvLHSsHTfh.XKJInPPJSOAdEfxriPPthLBAnOrMXIPJSKBxwK7.BfqjlBxzReu7TQPpySJTiRAVEf5L1FPtiOI.XMhHnI6.DAPxCNAtBf7j1QPFTPTHSNAJBfxXFVPhCTB1DIJI3U.hCXAZBj23iA+7zM.FTQCZAIIfBjvDTfxA3M.4AjqDjJ.BiMm8SW7AIL3HEfqT.GvHUf..IIPEHH.RxXsAIOEEHb.xiYG.4OwHXBAkkA.9ibT.ILBEHX.Fza4ASA9AoPlEXN.JjTt.4PTIELsbGfCklNPRzSA5Afv7TMDkVNPVjQDXRLDJALtfBfl7VfoA4PU8BfEskfBACMgAIQZw.fC0D.P1RPE.iMA1AfvzE.DwVUPVjWR.SGAZAfv.VKEkVKPZzVInxMPAXKzvgQiQiJfQEjGwTCqDSf3A3Qsj.jAARfvAXPa0AjBoRfHAnPakvJYvDjCUEBxXTfw.nLfUxPrEncPtTaAx.fKMlfkA4K8zfRdE3L.pTQa8RZF.IR7P.L4Dna.hTZv.SOAZCjj7RfCAHImbFjCMVfHA3PEIXJPJTUJ.SUxAnPlEHAPNTQpAHLgDHAPtRKRXTQg.3PiEnIFkl.qTzMPhhREfzVBl.fHMVFPZjPc.HJJE3BFgif9.IMMAfNGA.POkiHzDXV.pCaZQCaEADa8HhLX.IJFE3dt.0S.hBaANBj87Ufz.XOakfKlUDj9TzBoTTfgAnOfQBj73RfWAHOUEHYobDRPhyRb.iMC9Af3vVHPdSVApAfvjlL2rkKPVCTKvBUAxBfrf0K0.VCPdiQP.SOA9Df2.FBvnDJPZxSBfSQA9Bf371UPlyKBR.Or.Bf4vQRlTUfm.4OKg.f7j1CPBCTAtBfvTjKPJDXR.SBO.3OowlPusCLJoCjEgVKvHwX.VDaR.iYWAIQVYhJFEHVCA0L.RTSfLzXenhYAV.jBozDqHTfd.nPoAEjCkSf0.3PfYDjD8ze.RTZFsBVNAYQnYvKSE3e.VDaH8hMAlAjxnE.FcVf6.nQrsBjGwDO.JCFAJDjunTfu.3KcQvQi0CjHs0AvXVfeAHRr0.LaIAjK81FyfFT.tDaAdvLaEnTPhTU..CYAF.fHAVYvHDJPNTZQrBSABBfCA1NqXFTPdBND7SQAdCfmzSC+XVf0.4PVAvJqEHH.NzXtA4IKIvO7TAfqTUe+bjGmXlSPZRSB3COANCf9zxNPpBN.HDPtAnIRQgP8ThJaQEjEQ1DsTE.uPQfG.XQoYzKrQQKlE3ePxhZDPjZANDfDkVKrjVfbAoJgcfPmEXL.JDagnxay.4JZIvPVEXL.txaSLjYBpAjFEFAA8EAqfUNG8kF.ZjbyEjY8rRUebDXANEjxbVBJol.AklfO.XPmfjLBUgRiQ3FPBiNAB2L9TBfv.PfvA4MqDHG.dC.uLC.c.IOSE3e.xC.J.4OSEHaCIED.9C.AJzP.3AjHoTfQ.HR.nGjKsifb.3R.L.jOAUfTA3S.H3SPB0XHrBWGnjXBbCYDLEXABEfJAPDPA..SAvX2.f.q.ffUAIImI.LjgvShM.RWQ.UiIwReAvJfUPTbE3B.tB.SPE.DPB.KDE.mrD.w.C.Q7D.A1.I.AvJ.A.L.AvL.AvM.A.O.AvO.AvP.A.R.AfR.AvR.AvS.A.T.APT.AvT.A.U.Av+u..TxMWUUSA..nB...f.....jQC.....H....bjbg4FYfPDM.....L....v........pAA..vID..fsPC..............................P.....D..........b+mH9L....fB.......pAA..nGD..fgP...HBA..jHD..vhP...XBA..RJD..PoP..fsBo....PXllzOHHsS+j.yo8Cd7y0OYMDU+LiCf8SGH.3OO5yr+7nOy9yi9L6O........1JD.....C....D........mPA...............................A..................n.C..fBD.....C....H.......fZP...1BI....................v.....B.......nFD..fsPB........9C...3O......H.........RS.......9y.....A.......vIT...............v.....oA......PDD...RP...LAA...ED...UP...XAA..vED...XP...hAA..PFD..fYP...nAA..nFD...aP...tAA...GD..fbP...zAA..XGD...dP...5AA..vGD..feP....BA..DHD..ffP...CBA..PHD..PgP...FBA..bHD...hP...IBA..nHD..vhP...LBA..zHD..fiP...OBA...ID..PjP...RBA..LID...kP...UBA..XID..vkP...XBA..jID..flP...aBA..vID..PmP...dBA..7ID...nP..ffBA..DJD..XnP...hBA..JJD..vnP..fiBA..PJD..HoP...kBA..VJD..foP..flBA..bJD..3oP...nBA..hJD..PpP..foBA..nJD..npP...qBA..tJD...qP..frBA..zJD..XqP...tBA..5JD..vqP..fuBA...KD..HrP...wBA..FKD..frP..fxBA..LKD..3rP...zBA..RKD..PsP..f0BA..XKD..nsP...2BA..dKD...tP..f3BkF........v...f+B...AL...Dv...P.A....D...LP...f+....9C...LP...P.A...BD....v...P.C...BD...HP...n.A...CD...HP.....B...9C....v...f+....AL...Dv...P.A...BD...JP...n.A...AL...JP.....B....D...Dv...n.A..fBD...DP...f.A....D....v...f+....BD....P...n.A...AD...Dv.....B...BD...Dv.....B...9C...3u...P.C..fBD...Dv.....C....H....f...n.A...AL....v...f+B...AL...Dv...n.A....L...Dv...P.C...BD...3O...P.C...BD........f.A...9K....P...n.A...AL...3u.....C...CD...JP...P.C...AL....v...f+....AL...Dv...f+B...9K...LP...f.A...AL..............9C...Dv.....C...CD...Dv...v.A...AL...Dv...P.C....D.....C....H.......fZP...1BI........3O...f+........v8P.....D..........G....PTYlEVcrQGC.......xBA..HMD..X4P...xCA..5OD..XAQ..vKDA..HQD..DFQ..fdDA.fIRD..XIQA.......bODO....EA..............G....PTYlEVcrQ2.....D........GD...gP...PBA..XKDA.......n.C...9K..............................9C...3OC....H.......fZP...1BI........3O...f+.....v.....B.......nFD..fsPB........9C...3O..........v.....A.......vIT...................3OC....D........mPA...............A...............MyLy81LyL2S...................vu....+....9y.....C.......nFD...mP...1BM........3O...f+....9C..........L....f........pAA..XKj........................f+L....f........pAA..XKj........f+....9C........HBM....vA.......pAA..PJD..fpP...sBA...KD..frP...1Bc...................AD...LP...DAA..fDD...SP.........9y.....C.......nFD...mP...1BM........3O...f+....9C.....C.........P...............P.....C....H.............f+H.............f+.....v.....B.............3OB........9C...3O.....L.....A.........XxjI4i+98yO...f+P...................9C...3O.....L....f..............9i.....................MyLK.M....f........pAA..XKj........f+....9C........f+B...7y..........D........3O.....D....P.....A....n....vTsEFarABRgwFaK....zVYjkVcsgVXrwVL........fFD...3OlYlY+.....fPfUVO..................fpCA...9C...3OE........9C...3OC....zE......fZP...rAA..3FD...bP...xAA..PGD..fcP...3AA..nGD...eP...9AA...HD..PfP...BBA..LHD...gP...EBA..XHD..vgP...HBA..jHD..fhP...KBA..vHD..PiP...NBA..7HD...jP...QBA..HID..vjP...TBA..TID..fkP...WBA..fID..PlP...ZBA..rID...mP...cBA..3ID..vmP...fBA..BJD..PnP..fgBA..HJD..nnP...iBA..NJD...oP..fjBA..TJD..XoP...lBA..ZJD..voP..fmBA..fJD..HpP...oBA..lJD..fpP..fpBA..rJD..3pP...rBA..xJD..PqP..fsBA..3JD..nqP...uBA..9JD...rP..fvBA..DKD..XrP...xBA..JKD..vrP..fyBA..PKD..HsP...0BA..VKD..fsP..f1BA..bKD..3sP...3BA..hKTW.......f+....9C...3O...f+....9C...3O...f+....9Sb8n3OEtdj+XOJb9C6Qg4OOJbk+DWOJ9ilYl4OOJbk+rGEN9yiBW4OZlYl+fqGk9SyLy3OJb8n+HEtd9ilYl4OWOJj+b8nP9CtdT5Oov0i+DtdT9SOJb4O6Qgi+7nvU9CRgq4O6Qgq+35Qg9C...3Oov0i+HEtd9C...3OgqGk+v0ih9C6Qg4Ob8nn+7Qgq9Cov04OyLyr+rGEt9iqGE5OHEtl+DWOJ9CWOJ5OCWOh+vdTX9SyLy3OT35g+7QgK9C6Qg4ORgqm+rGEN9iqGE5Oov0i+nYlY9CWOJ5OJb8n+XlYl9Cov04OyLyj+7nv09iT354OZlYl+nYl49CtdT5O...n+zLyr9ilYl6OjBWm+fT3Z9SyLy5O8nvk+jBWO9yv0i5O8nvk+PJbc9ilYl4Ow0ip+fT3Z9iT354ORgqm+fT3Z9ydT35OgqGk+XOJb9Cov04O.....L....v........pAA..vID..fsPC........9C...3O...f+...........C....zE......fZP...rAA..3FD...bP...xAA..PGD..fcP...3AA..nGD...eP...9AA...HD..PfP...BBA..LHD...gP...EBA..XHD..vgP...HBA..jHD..fhP...KBA..vHD..PiP...NBA..7HD...jP...QBA..HID..vjP...TBA..TID..fkP...WBA..fID..PlP...ZBA..rID...mP...cBA..3ID..vmP...fBA..BJD..PnP..fgBA..HJD..nnP...iBA..NJD...oP..fjBA..TJD..XoP...lBA..ZJD..voP..fmBA..fJD..HpP...oBA..lJD..fpP..fpBA..rJD..3pP...rBA..xJD..PqP..fsBA..3JD..nqP...uBA..9JD...rP..fvBA..DKD..XrP...xBA..JKD..vrP..fyBA..PKD..HsP...0BA..VKD..fsP..f1BA..bKD..3sP...3BA..hKTW..............................................PLZVNuHENR8dQUGzKPYDFOPKDd89E1I0Cr1jTudmi34hcUp1qK3tVu3DxD5b8X.xqEaSXuDIUA8fZhOxifWBqttyqp8Ho301aswqaOZyVR8LzKg1C4Vr5t8hva8Rvef160b2ZuaWQm8b3fC0CuETYuxTiw7j8dw1aTg6JuLxn77P2+A2yVlaytlI1i5BQJ51C2mMaOf3hl8TJsRzqyeWHuMlrs7H0QnxiRznaOxQ9Y8lqF.1y+0zZuTWVm8jXGcwiMNtUOtxEj8pS5c0KXfEJO7cnQ8DwYJziiYMPOavu06XL0wx6UXrWOAfQY81AeByyLZRRuOAiT8lza5z68N4TOrMss8jrsmzaEKUZO83Um8TTK50qOjhWOUV9271Q3WxaIAyXO9oT14X18G2iVYEROUtjy7LvCb1q1ZtVurErj8fxLvySI+NausO5W8XD+N1Cr4CTu.....L........3O...f+....9y.....C.......nFD...mP...1BM........3O...f+....9C.....C....L.......fZP...bBA..XKz........f+....9C...3O.....L....v........pAA..vID..fsPC........9C...3O...f+.........3O...f+X........3OZlYl9zLyL8SyLy7OZlYl9f...............................................L....v........pAA..vID..fsPC........9C...3O...f+.....v.....C.......nFD...mP...1BM........3O...f+....9C.....C....L.......fZP...bBA..XKz........f+....9C...3O.....L....v........pAA..vID..fsPC........9C...3O...f+.....P.....A.......vIz.....A.........P...............fSifcOC....XA.......QP...pAA...GD...dP...5AA...HD..ffP...FBA..jHD...iP...PBA..LID...lP...bBA...JD..fnP...jBA..XJD...pP...pBA...KD..fsPV....fGcj7S5k+3OLDlj+fm7T9SSCR4OMMHk+zzfT9SSCR4OpqXj+zzfT9SSCR4OpqXj+jErN9i5JF4OYAqi+jErN9SVv53OmSHW+bNgb8iejnzOZOTK+Dijx6C.....A.........P.....yLyL+XlYl9S.....A....D....fYlY1OMyLi+D.............7BA....fC........+zLyL2SyLyjO....+P....f.....C....P....P.....B....b....P..........3.....D.........zLyL2C...3O.........7K...mP.....................................................H....................fC....P.........................................................................................f.....................N.....A.........................................................................................A....D........3O...PAC....f.....C....D....PA....D....D....v........v+...f9C...7O..PXCygaABL.....E.............Qv...vBC...KL...rvE.........viBWOO................E...............................A..........A....A....L........7O...P+....+C..PiPb3Vf.C....PA.......DAC........rv...vBC...KbA....Jb8H8X5lDqC...............PA..............................P..........P..........C....7nv0+SOJb0ueT3Z+...zJD..........T........Tv...PAC..vIL...mv...bBW...............................T...............................D..........D.........v.....yLyL+x0iB6iqGE1O................E........EL...Tv...bBC..vIL...mvE...............................E...............................A..........A.........L.....tdT7O8nvU+35Qg+C...............PA.......PAC...EL...mv...bBC..vIbA..............................PA..............................P..........D..........A....L....vLyLyO.....XlYl9C...YP................"
						}
,
						"snapshotlist" : 						{
							"current_snapshot" : 0,
							"entries" : [ 								{
									"filetype" : "C74Snapshot",
									"version" : 2,
									"minorversion" : 0,
									"name" : "Pianoteq 5 STAGE VST",
									"origin" : "Pianoteq 5 STAGE.vst",
									"type" : "VST",
									"subtype" : "Instrument",
									"embed" : 0,
									"snapshot" : 									{
										"pluginname" : "Pianoteq 5 STAGE.vst",
										"plugindisplayname" : "Pianoteq 5 STAGE VST",
										"pluginsavedname" : "Pianoteq 5 STAGE VST",
										"pluginsaveduniqueid" : 0,
										"version" : 1,
										"isbank" : 0,
										"isbase64" : 1,
										"blob" : "7146.CMlaKA....fQPMDZ....A.Ec0zF...P.....fPDMfPTXowVdf.kbgMFcoMVY.................rgqPImUKQA..H.VFQETdtA..n....fLvDCNu.iLu.SNc.....UZg41azUVbfLEUAcTQfTiKx3RLuHCLwTCLzHCN9TXWLnjVLzVfs.tiB3A4VSFarE1Ua...zQFcMImA..PD....DQCHDEVZrkGHPIWXiQWZiUF.....Z....LzavkmbocFZzABJikBHx.SLz.RSuQVXxQGcGB...PEZoMGHvIWYyUFcf7lYlUlbyARXfLFakElafL2a04FYr.RduUGHsEVdfvVZqUFHz8FH0MWYfjFcfX1axARduUmbfPVXowVdf.mbgMFcoMVYt.RPrM2afDFHm81ajAxbzElbzklamABbuklazAhYuIGHvIWYvElbo41Yf3VY2ABbxU1bkQ2bt.....fQ....Q....PDMfPTXowVdf.kbgMFcoMVY.....rXA..vQRUUU....F....Dv..2DUxsF..TPc.7u.O.BToUFcfPTYfHUZjQVYxA.jpjBd.pRUF.4JjLXL.tRCnAIIpH3A.RBGx.4MsDXB.dySBZFj7DSfNAHOEYEjqnRA+rSfLA3OrYEjC8hJ2.RfX.3PRQvMqnzJkDXDP9CMHTRIxA3Oa0SIMIEjBsBBlHRf5.nPJEHKPlSHBRAf4nTffXxFz.oOvLHSsHTfh.XKJInPPJSOAdEfxriPPthLBAnOrMXIPJSKBxwK7.BfqjlBxzReu7TQPpySJTiRAVEf5L1FPtiOI.XMhHnI6.DAPxCNAtBf7j1QPFTPTHSNAJBfxXFVPhCTB1DIJI3U.hCXAZBj23iA+7zM.FTQCZAIIfBjvDTfxA3M.4AjqDjJ.BiMm8SW7AIL3HEfqT.GvHUf..IIPEHH.RxXsAIOEEHb.xiYG.4OwHXBAkkA.9ibT.ILBEHX.Fza4ASA9AoPlEXN.JjTt.4PTIELsbGfCklNPRzSA5Afv7TMDkVNPVjQDXRLDJALtfBfl7VfoA4PU8BfEskfBACMgAIQZw.fC0D.P1RPE.iMA1AfvzE.DwVUPVjWR.SGAZAfv.VKEkVKPZzVInxMPAXKzvgQiQiJfQEjGwTCqDSf3A3Qsj.jAARfvAXPa0AjBoRfHAnPakvJYvDjCUEBxXTfw.nLfUxPrEncPtTaAx.fKMlfkA4K8zfRdE3L.pTQa8RZF.IR7P.L4Dna.hTZv.SOAZCjj7RfCAHImbFjCMVfHA3PEIXJPJTUJ.SUxAnPlEHAPNTQpAHLgDHAPtRKRXTQg.3PiEnIFkl.qTzMPhhREfzVBl.fHMVFPZjPc.HJJE3BFgif9.IMMAfNGA.POkiHzDXV.pCaZQCaEADa8HhLX.IJFE3dt.0S.hBaANBj87Ufz.XOakfKlUDj9TzBoTTfgAnOfQBj73RfWAHOUEHYobDRPhyRb.iMC9Af3vVHPdSVApAfvjlL2rkKPVCTKvBUAxBfrf0K0.VCPdiQP.SOA9Df2.FBvnDJPZxSBfSQA9Bf371UPlyKBR.Or.Bf4vQRlTUfm.4OKg.f7j1CPBCTAtBfvTjKPJDXR.SBO.3OowlPusCLJoCjEgVKvHwX.VDaR.iYWAIQVYhJFEHVCA0L.RTSfLzXenhYAV.jBozDqHTfd.nPoAEjCkSf0.3PfYDjD8ze.RTZFsBVNAYQnYvKSE3e.VDaH8hMAlAjxnE.FcVf6.nQrsBjGwDO.JCFAJDjunTfu.3KcQvQi0CjHs0AvXVfeAHRr0.LaIAjK81FyfFT.tDaAdvLaEnTPhTU..CYAF.fHAVYvHDJPNTZQrBSABBfCA1NqXFTPdBND7SQAdCfmzSC+XVf0.4PVAvJqEHH.NzXtA4IKIvO7TAfqTUe+bjGmXlSPZRSB3COANCf9zxNPpBN.HDPtAnIRQgP8ThJaQEjEQ1DsTE.uPQfG.XQoYzKrQQKlE3ePxhZDPjZANDfDkVKrjVfbAoJgcfPmEXL.JDagnxay.4JZIvPVEXL.txaSLjYBpAjFEFAA8EAqfUNG8kF.ZjbyEjY8rRUebDXANEjxbVBJol.AklfO.XPmfjLBUgRiQ3FPBiNAB2L9TBfv.PfvA4MqDHG.dC.uLC.c.IOSE3e.xC.J.4OSEHaCIED.9C.AJzP.3AjHoTfQ.HR.nGjKsifb.3R.L.jOAUfTA3S.H3SPB0XHrBWGnjXBbCYDLEXABEfJAPDPA..SAvX2.f.q.ffUAIImI.LjgvShM.RWQ.UiIwReAvJfUPTbE3B.tB.SPE.DPB.KDE.mrD.w.C.Q7D.A1.I.AvJ.A.L.AvL.AvM.A.O.AvO.AvP.A.R.AfR.AvR.AvS.A.T.APT.AvT.A.U.Av+u..TxMWUUSA..nB...f.....jQC.....H....bjbg4FYfPDM.....L....v........pAA..vID..fsPC..............................P.....D..........b+mH9L....fB.......pAA..nGD..fgP...HBA..jHD..vhP...XBA..RJD..PoP..fsBo....PXllzOHHsS+j.yo8Cd7y0OYMDU+LiCf8SGH.3OO5yr+7nOy9yi9L6O........1JD.....C....D........mPA...............................A..................n.C..fBD.....C....H.......fZP...1BI....................v.....B.......nFD..fsPB........9C...3O......H.........RS.......9y.....A.......vIT...............v.....oA......PDD...RP...LAA...ED...UP...XAA..vED...XP...hAA..PFD..fYP...nAA..nFD...aP...tAA...GD..fbP...zAA..XGD...dP...5AA..vGD..feP....BA..DHD..ffP...CBA..PHD..PgP...FBA..bHD...hP...IBA..nHD..vhP...LBA..zHD..fiP...OBA...ID..PjP...RBA..LID...kP...UBA..XID..vkP...XBA..jID..flP...aBA..vID..PmP...dBA..7ID...nP..ffBA..DJD..XnP...hBA..JJD..vnP..fiBA..PJD..HoP...kBA..VJD..foP..flBA..bJD..3oP...nBA..hJD..PpP..foBA..nJD..npP...qBA..tJD...qP..frBA..zJD..XqP...tBA..5JD..vqP..fuBA...KD..HrP...wBA..FKD..frP..fxBA..LKD..3rP...zBA..RKD..PsP..f0BA..XKD..nsP...2BA..dKD...tP..f3BkF........v...f+B...AL...Dv...P.A....D...LP...f+....9C...LP...P.A...BD....v...P.C...BD...HP...n.A...CD...HP.....B...9C....v...f+....AL...Dv...P.A...BD...JP...n.A...AL...JP.....B....D...Dv...n.A..fBD...DP...f.A....D....v...f+....BD....P...n.A...AD...Dv.....B...BD...Dv.....B...9C...3u...P.C..fBD...Dv.....C....H....f...n.A...AL....v...f+B...AL...Dv...n.A....L...Dv...P.C...BD...3O...P.C...BD........f.A...9K....P...n.A...AL...3u.....C...CD...JP...P.C...AL....v...f+....AL...Dv...f+B...9K...LP...f.A...AL..............9C...Dv.....C...CD...Dv...v.A...AL...Dv...P.C....D.....C....H.......fZP...1BI........3O...f+........v8P.....D..........G....PTYlEVcrQGC.......xBA..HMD..X4P...xCA..5OD..XAQ..vKDA..HQD..DFQ..fdDA.fIRD..XIQA.......bODO....EA..............G....PTYlEVcrQ2.....D........GD...gP...PBA..XKDA.......n.C...9K..............................9C...3OC....H.......fZP...1BI........3O...f+.....v.....B.......nFD..fsPB........9C...3O..........v.....A.......vIT...................3OC....D........mPA...............A...............MyLy81LyL2S...................vu....+....9y.....C.......nFD...mP...1BM........3O...f+....9C..........L....f........pAA..XKj........................f+L....f........pAA..XKj........f+....9C........HBM....vA.......pAA..PJD..fpP...sBA...KD..frP...1Bc...................AD...LP...DAA..fDD...SP.........9y.....C.......nFD...mP...1BM........3O...f+....9C.....C.........P...............P.....C....H.............f+H.............f+.....v.....B.............3OB........9C...3O.....L.....A.........XxjI4i+98yO...f+P...................9C...3O.....L....f..............9i.....................MyLK.M....f........pAA..XKj........f+....9C........f+B...7y..........D........3O.....D....P.....A....n....vTsEFarABRgwFaK....zVYjkVcsgVXrwVL........fFD...3OlYlY+.....fPfUVO..................fpCA...9C...3OE........9C...3OC....zE......fZP...rAA..3FD...bP...xAA..PGD..fcP...3AA..nGD...eP...9AA...HD..PfP...BBA..LHD...gP...EBA..XHD..vgP...HBA..jHD..fhP...KBA..vHD..PiP...NBA..7HD...jP...QBA..HID..vjP...TBA..TID..fkP...WBA..fID..PlP...ZBA..rID...mP...cBA..3ID..vmP...fBA..BJD..PnP..fgBA..HJD..nnP...iBA..NJD...oP..fjBA..TJD..XoP...lBA..ZJD..voP..fmBA..fJD..HpP...oBA..lJD..fpP..fpBA..rJD..3pP...rBA..xJD..PqP..fsBA..3JD..nqP...uBA..9JD...rP..fvBA..DKD..XrP...xBA..JKD..vrP..fyBA..PKD..HsP...0BA..VKD..fsP..f1BA..bKD..3sP...3BA..hKTW.......f+....9C...3O...f+....9C...3O...f+....9Sb8n3OEtdj+XOJb9C6Qg4OOJbk+DWOJ9ilYl4OOJbk+rGEN9yiBW4OZlYl+fqGk9SyLy3OJb8n+HEtd9ilYl4OWOJj+b8nP9CtdT5Oov0i+DtdT9SOJb4O6Qgi+7nvU9CRgq4O6Qgq+35Qg9C...3Oov0i+HEtd9C...3OgqGk+v0ih9C6Qg4Ob8nn+7Qgq9Cov04OyLyr+rGEt9iqGE5OHEtl+DWOJ9CWOJ5OCWOh+vdTX9SyLy3OT35g+7QgK9C6Qg4ORgqm+rGEN9iqGE5Oov0i+nYlY9CWOJ5OJb8n+XlYl9Cov04OyLyj+7nv09iT354OZlYl+nYl49CtdT5O...n+zLyr9ilYl6OjBWm+fT3Z9SyLy5O8nvk+jBWO9yv0i5O8nvk+PJbc9ilYl4Ow0ip+fT3Z9iT354ORgqm+fT3Z9ydT35OgqGk+XOJb9Cov04O.....L....v........pAA..vID..fsPC........9C...3O...f+...........C....zE......fZP...rAA..3FD...bP...xAA..PGD..fcP...3AA..nGD...eP...9AA...HD..PfP...BBA..LHD...gP...EBA..XHD..vgP...HBA..jHD..fhP...KBA..vHD..PiP...NBA..7HD...jP...QBA..HID..vjP...TBA..TID..fkP...WBA..fID..PlP...ZBA..rID...mP...cBA..3ID..vmP...fBA..BJD..PnP..fgBA..HJD..nnP...iBA..NJD...oP..fjBA..TJD..XoP...lBA..ZJD..voP..fmBA..fJD..HpP...oBA..lJD..fpP..fpBA..rJD..3pP...rBA..xJD..PqP..fsBA..3JD..nqP...uBA..9JD...rP..fvBA..DKD..XrP...xBA..JKD..vrP..fyBA..PKD..HsP...0BA..VKD..fsP..f1BA..bKD..3sP...3BA..hKTW..............................................PLZVNuHENR8dQUGzKPYDFOPKDd89E1I0Cr1jTudmi34hcUp1qK3tVu3DxD5b8X.xqEaSXuDIUA8fZhOxifWBqttyqp8Ho301aswqaOZyVR8LzKg1C4Vr5t8hva8Rvef160b2ZuaWQm8b3fC0CuETYuxTiw7j8dw1aTg6JuLxn77P2+A2yVlaytlI1i5BQJ51C2mMaOf3hl8TJsRzqyeWHuMlrs7H0QnxiRznaOxQ9Y8lqF.1y+0zZuTWVm8jXGcwiMNtUOtxEj8pS5c0KXfEJO7cnQ8DwYJziiYMPOavu06XL0wx6UXrWOAfQY81AeByyLZRRuOAiT8lza5z68N4TOrMss8jrsmzaEKUZO83Um8TTK50qOjhWOUV9271Q3WxaIAyXO9oT14X18G2iVYEROUtjy7LvCb1q1ZtVurErj8fxLvySI+NausO5W8XD+N1Cr4CTu.....L........3O...f+....9y.....C.......nFD...mP...1BM........3O...f+....9C.....C....L.......fZP...bBA..XKz........f+....9C...3O.....L....v........pAA..vID..fsPC........9C...3O...f+.........3O...f+X........3OZlYl9zLyL8SyLy7OZlYl9f...............................................L....v........pAA..vID..fsPC........9C...3O...f+.....v.....C.......nFD...mP...1BM........3O...f+....9C.....C....L.......fZP...bBA..XKz........f+....9C...3O.....L....v........pAA..vID..fsPC........9C...3O...f+.....P.....A.......vIz.....A.........P...............fSifcOC....XA.......QP...pAA...GD...dP...5AA...HD..ffP...FBA..jHD...iP...PBA..LID...lP...bBA...JD..fnP...jBA..XJD...pP...pBA...KD..fsPV....fGcj7S5k+3OLDlj+fm7T9SSCR4OMMHk+zzfT9SSCR4OpqXj+zzfT9SSCR4OpqXj+jErN9i5JF4OYAqi+jErN9SVv53OmSHW+bNgb8iejnzOZOTK+Dijx6C.....A.........P.....yLyL+XlYl9S.....A....D....fYlY1OMyLi+D.............7BA....fC........+zLyL2SyLyjO....+P....f.....C....P....P.....B....b....P..........3.....D.........zLyL2C...3O.........7K...mP.....................................................H....................fC....P.........................................................................................f.....................N.....A.........................................................................................A....D........3O...PAC....f.....C....D....PA....D....D....v........v+...f9C...7O..PXCygaABL.....E.............Qv...vBC...KL...rvE.........viBWOO................E...............................A..........A....A....L........7O...P+....+C..PiPb3Vf.C....PA.......DAC........rv...vBC...KbA....Jb8H8X5lDqC...............PA..............................P..........P..........C....7nv0+SOJb0ueT3Z+...zJD..........T........Tv...PAC..vIL...mv...bBW...............................T...............................D..........D.........v.....yLyL+x0iB6iqGE1O................E........EL...Tv...bBC..vIL...mvE...............................E...............................A..........A.........L.....tdT7O8nvU+35Qg+C...............PA.......PAC...EL...mv...bBC..vIbA..............................PA..............................P..........D..........A....L....vLyLyO.....XlYl9C...YP................"
									}
,
									"fileref" : 									{
										"name" : "Pianoteq 5 STAGE VST",
										"filename" : "Pianoteq 5 STAGE VST.maxsnap",
										"filepath" : "~/Documents/Max 7/Snapshots",
										"filepos" : -1,
										"snapshotfileid" : "198fa369ca2ef2eb2996589fee6acfd2"
									}

								}
, 								{
									"filetype" : "C74Snapshot",
									"version" : 2,
									"minorversion" : 0,
									"name" : "Pianoteq 5 STAGE VST",
									"origin" : "Pianoteq 5 STAGE.vst",
									"type" : "VST",
									"subtype" : "Instrument",
									"embed" : 0,
									"fileref" : 									{
										"name" : "Pianoteq 5 STAGE VST",
										"filename" : "Pianoteq 5 STAGE VST_20171226.maxsnap",
										"filepath" : "~/Documents/Max 7/Snapshots",
										"filepos" : -1,
										"snapshotfileid" : "c85066f9e6fd13afbe247fbca8381ae1"
									}

								}
 ]
						}

					}
,
					"style" : "",
					"text" : "vst~",
					"varname" : "vst~",
					"viewvisibility" : 0
				}

			}
, 			{
				"box" : 				{
					"border" : 12.0,
					"bordercolor" : [ 0.784314, 0.145098, 0.023529, 1.0 ],
					"id" : "obj-11",
					"maxclass" : "dropfile",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 1227.800049, 486.600006, 157.0, 89.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 1227.800049, 486.600006, 157.0, 89.0 ]
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.525038,
					"background" : 1,
					"bgcolor" : [ 0.960784, 0.827451, 0.156863, 1.0 ],
					"id" : "obj-19",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 16.0, 29.0, 416.0, 305.0 ],
					"proportion" : 0.99,
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"background" : 1,
					"bgcolor" : [ 0.439216, 0.74902, 0.254902, 1.0 ],
					"id" : "obj-20",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 6.0, 399.0, 740.0, 454.0 ],
					"proportion" : 0.39,
					"style" : ""
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1237.300049, 597.0, 892.700073, 597.0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-77", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2198.5, 570.0, 1588.5, 570.0 ],
					"source" : [ "obj-112", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-114", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2198.5, 648.0, 1695.0, 648.0, 1695.0, 654.0, 1588.5, 654.0 ],
					"source" : [ "obj-115", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-122", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2198.5, 714.0, 1689.0, 714.0, 1689.0, 738.0, 1341.0, 738.0, 1341.0, 660.0, 1241.300049, 660.0 ],
					"source" : [ "obj-126", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.65, 0.65, 0.65, 0.198787 ],
					"destination" : [ "obj-72", 0 ],
					"midpoints" : [ 361.5, 969.0, 849.0, 969.0, 849.0, 864.0, 956.5, 864.0 ],
					"source" : [ "obj-127", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.65, 0.65, 0.65, 0.198787 ],
					"destination" : [ "obj-81", 0 ],
					"midpoints" : [ 381.833333, 969.0, 849.0, 969.0, 849.0, 915.0, 956.5, 915.0 ],
					"source" : [ "obj-127", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.65, 0.65, 0.65, 0.198787 ],
					"destination" : [ "obj-82", 0 ],
					"midpoints" : [ 402.166667, 969.0, 849.0, 969.0, 849.0, 957.0, 956.5, 957.0 ],
					"source" : [ "obj-127", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.65, 0.65, 0.65, 0.198787 ],
					"destination" : [ "obj-83", 0 ],
					"midpoints" : [ 422.5, 990.0, 933.0, 990.0, 933.0, 999.0, 956.5, 999.0 ],
					"source" : [ "obj-127", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 1 ],
					"midpoints" : [ 193.5, 759.0, 344.5, 759.0 ],
					"source" : [ "obj-13", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"midpoints" : [ 183.0, 759.0, 318.5, 759.0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2205.5, 765.0, 1341.0, 765.0, 1341.0, 693.0, 1241.300049, 693.0 ],
					"order" : 2,
					"source" : [ "obj-132", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-129", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2205.5, 765.0, 1341.0, 765.0, 1341.0, 729.0, 1241.300049, 729.0 ],
					"order" : 1,
					"source" : [ "obj-132", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-130", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2205.5, 765.0, 1332.0, 765.0, 1332.0, 762.0, 1241.300049, 762.0 ],
					"order" : 0,
					"source" : [ "obj-132", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-55", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1150.5, 267.0, 1185.0, 267.0, 1185.0, 318.0, 1052.699951, 318.0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 1 ],
					"midpoints" : [ 2013.5, 411.0, 1967.5, 411.0 ],
					"order" : 0,
					"source" : [ "obj-144", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1805.5, 318.0, 1588.5, 318.0 ],
					"source" : [ "obj-144", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1909.5, 360.0, 1588.5, 360.0 ],
					"source" : [ "obj-144", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2013.5, 399.0, 1588.5, 399.0 ],
					"order" : 1,
					"source" : [ "obj-144", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1270.800049, 267.0, 1188.0, 267.0, 1188.0, 360.0, 1052.699951, 360.0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"midpoints" : [ 892.700073, 669.0, 891.5, 669.0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1397.900024, 267.0, 1206.0, 267.0, 1206.0, 474.0, 1052.699951, 474.0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 1 ],
					"midpoints" : [ 256.5, 525.0, 138.0, 525.0, 138.0, 507.0, 116.5, 507.0 ],
					"order" : 1,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 1 ],
					"midpoints" : [ 256.5, 525.0, 256.5, 525.0 ],
					"order" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1515.5, 267.0, 1206.0, 267.0, 1206.0, 516.0, 1052.699951, 516.0 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1646.5, 267.0, 1416.0, 267.0, 1416.0, 597.0, 1038.0, 597.0, 1038.0, 558.0, 1052.699951, 558.0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"midpoints" : [ 624.5, 567.0, 405.5, 567.0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 1 ],
					"midpoints" : [ 238.5, 222.0, 247.5, 222.0 ],
					"order" : 0,
					"source" : [ "obj-31", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"midpoints" : [ 226.5, 165.0, 227.5, 165.0 ],
					"order" : 0,
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 1 ],
					"midpoints" : [ 226.5, 201.0, 72.5, 201.0 ],
					"order" : 1,
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 1 ],
					"midpoints" : [ 238.5, 201.0, 134.5, 201.0 ],
					"order" : 1,
					"source" : [ "obj-31", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"midpoints" : [ 702.5, 639.0, 405.5, 639.0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 1 ],
					"midpoints" : [ 405.5, 639.0, 479.0, 639.0 ],
					"order" : 1,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 1 ],
					"midpoints" : [ 405.5, 567.0, 673.5, 567.0 ],
					"order" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1588.5, 348.0, 1782.0, 348.0, 1782.0, 282.0, 1805.5, 282.0 ],
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 1 ],
					"hidden" : 1,
					"midpoints" : [ 1588.5, 387.0, 1782.0, 387.0, 1782.0, 273.0, 1909.5, 273.0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 2 ],
					"hidden" : 1,
					"midpoints" : [ 1588.5, 438.0, 1782.0, 438.0, 1782.0, 273.0, 2013.5, 273.0 ],
					"source" : [ "obj-46", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2204.5, 246.0, 1572.0, 246.0, 1572.0, 318.0, 1588.5, 318.0 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-117", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2203.5, 330.0, 1695.0, 330.0, 1695.0, 612.0, 1392.0, 612.0, 1392.0, 654.0, 1420.600098, 654.0 ],
					"order" : 1,
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2203.5, 330.0, 1689.0, 330.0, 1689.0, 360.0, 1588.5, 360.0 ],
					"order" : 0,
					"source" : [ "obj-52", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2200.5, 396.0, 1588.5, 396.0 ],
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"hidden" : 1,
					"midpoints" : [ 2200.5, 486.0, 1588.5, 486.0 ],
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1262.300049, 348.0, 1188.0, 348.0, 1188.0, 435.0, 870.0, 435.0, 870.0, 726.0, 891.5, 726.0 ],
					"source" : [ "obj-65", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1262.300049, 435.0, 870.0, 435.0, 870.0, 726.0, 891.5, 726.0 ],
					"source" : [ "obj-67", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 1 ],
					"midpoints" : [ 416.0, 759.0, 344.5, 759.0 ],
					"source" : [ "obj-7", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"midpoints" : [ 405.5, 759.0, 318.5, 759.0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"hidden" : 1,
					"midpoints" : [ 1052.699951, 726.0, 891.5, 726.0 ],
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.608524, 0.608524, 0.608524, 0.2 ],
					"destination" : [ "obj-127", 0 ],
					"midpoints" : [ 956.5, 903.0, 361.5, 903.0 ],
					"order" : 1,
					"source" : [ "obj-72", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 1 ],
					"midpoints" : [ 956.5, 903.0, 933.0, 903.0, 933.0, 1080.0, 996.400024, 1080.0 ],
					"order" : 0,
					"source" : [ "obj-72", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.608524, 0.608524, 0.608524, 0.2 ],
					"destination" : [ "obj-127", 1 ],
					"midpoints" : [ 956.5, 942.0, 444.0, 942.0, 444.0, 921.0, 381.833333, 921.0 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.608524, 0.608524, 0.608524, 0.2 ],
					"destination" : [ "obj-127", 2 ],
					"midpoints" : [ 956.5, 984.0, 924.0, 984.0, 924.0, 942.0, 444.0, 942.0, 444.0, 921.0, 402.166667, 921.0 ],
					"source" : [ "obj-82", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"color" : [ 0.65, 0.65, 0.65, 0.198787 ],
					"destination" : [ "obj-127", 3 ],
					"midpoints" : [ 956.5, 1035.0, 444.0, 1035.0, 444.0, 930.0, 422.5, 930.0 ],
					"source" : [ "obj-83", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-7" : [ "vst~[1]", "vst~[1]", 0 ],
			"obj-13" : [ "vst~", "vst~", 0 ]
		}
,
		"dependency_cache" : [ 			{
				"name" : "Pianoteq 5 STAGE VST.maxsnap",
				"bootpath" : "~/Documents/Max 7/Snapshots",
				"patcherrelativepath" : "../../Documents/Max 7/Snapshots",
				"type" : "mx@s",
				"implicit" : 1
			}
, 			{
				"name" : "Pianoteq 5 STAGE VST_20171226.maxsnap",
				"bootpath" : "~/Documents/Max 7/Snapshots",
				"patcherrelativepath" : "../../Documents/Max 7/Snapshots",
				"type" : "mx@s",
				"implicit" : 1
			}
, 			{
				"name" : "Kontakt 5_20180208.maxsnap",
				"bootpath" : "~/Documents/Max 7/Snapshots",
				"patcherrelativepath" : "../../Documents/Max 7/Snapshots",
				"type" : "mx@s",
				"implicit" : 1
			}
, 			{
				"name" : "Hub7.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "Port.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
