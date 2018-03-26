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
				"clearer": "record_clearer", 
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