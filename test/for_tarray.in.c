@type
	{
		"typeName": "Foo",
		"fields": [
			{"name": "i", "type": "int"},
			{"name": "d", "type": "double"}
		],
		"containers": [
     		{
     			"type": "array",
				"typeName": "FooAr", 
				"elemName": "Foo *", 
			 	"binarySearch": [
					{"compare": "Foo_cmpReverseI", "tag": "ReverseI"}, 
					{"compare": "Foo_cmpD"} 
				]
			}
	    ]
	}
@end

APIF IntAr *IntAr_new10()
{
	IntAr *ia = IntAr_new();
	for (int i = 0; i < 10; i++) {
		IntAr_push(ia, i);
	}
	return ia;
}

#define IntAr_cap(arr) ((Array*)arr)->cap

APIF FooAr *FooAr_new25()
{
	FooAr *self = FooAr_new();
	for (int i = 0; i < 5; i++) {
		for (int d = 0; d < 5; d++) {
			FooAr_push(self, Foo_newBuild(i, (double)d));
		}
	}
	return self;
}

APIF FooAr *FooAr_new10()
{
	FooAr *self = FooAr_new();
	for (int i = 0; i < 10; i++) {
		FooAr_push(self, Foo_newBuild(i, (double)i));
	}
	return self;
}

APIF Foo *Foo_newBuild(int i, double d)
{
	Foo *self = Foo_new();
	self->i = i;
	self->d = d;
	return self;
}

APIF int Foo_cmpReverseI(Foo *left, Foo *right) 
{
	if (left->i > right->i) {
		return -1;
	} else if (left->i < right->i) {
		return 1;
	}
	return 0;
}

APIF int Foo_cmpD(Foo *left, Foo *right) 
{
	if (left->d < right->d) {
		return -1;
	} else if (left->d > right->d) {
		return 1;
	}

	return 0;
}



