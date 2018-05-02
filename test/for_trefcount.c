
@type
{
	"typeName": "Bar",
	"fields": [
		{"name": "i", "type": "int"},
		{"name": "s", "type": "String *"}
	],
	"containers": [
		{
			"type": "array", 
			"typeName": "BarAr", 
			"elemName": "Bar *",
			"binarySearch": [
				{"compare": "Bar_cmp"} 
			]
		},
    ]
}
@end

APIF int Bar_cmp(Bar *left, Bar *right)
{
	if (left->i < right->i) {
		return -1;
	} else if (left->i > right->i) {
		return 1;
	}
	return 0;
}

@type
{
	"typeName": "Bar2",
	"fields": [
		{"name": "i", "type": "int"},
		{"name": "s", "type": "String *"},
		{"name": "r", "type": "Bar *"}
	]
}
@end

@type
{
	"typeName": "StdValue",
	"valueType": true,
	"fields": [
		{"name": "i", "type": "int"},
		{"name": "s", "type": "String *"}
	]
}
@end

