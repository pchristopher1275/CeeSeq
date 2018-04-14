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
				"typeName": "FooArr", 
				"elemName": "Foo", 
				"clearer": "Foo_recorder", 
			 	"binarySearch": [
					{"compare": "Foo_cmp"}, 
					{"compare": "Foo_cmpBoth", "tag": "Both"}, 
					{"compare": "Foo_cmp", "tag": "Multi", "multi": true},
					{"compare": "Foo_cmpBoth", "tag": "BothMulti", "multi": true}
				]
			}
	    ]
	}
@end

@container 
	{	
		"type": "array",
		"typeName": "IntArr", 
		"elemName": "int"   
	}
@end

const int maxNumRecorded = 10;
int numRecorded          = 0;
Foo recorded[maxNumRecorded] = {0};

APIF void Foo_recorder(Foo *self)
{
	if (numRecorded < maxNumRecorded) {
		recorded[numRecorded++] = *self;
	}
}

APIF int Foo_cmp(Foo *left, Foo *right) 
{
	if (left->i < right->i) {
		return -1;
	} else if (left->i > right->i) {
		return 1;
	}
	return 0;
}

APIF int Foo_cmpBoth(Foo *left, Foo *right) 
{
	int q = Foo_cmp(left, right);
	if (q) {
		return q;
	}

	if (left->d < right->d) {
		return -1;
	} else if (left->d > right->d) {
		return 1;
	}

	return 0;
}


NOCOVER void Foo_zeroRecord() {
	numRecorded = 0;
	memset(recorded, 0, sizeof(Foo)*maxNumRecorded);
}



