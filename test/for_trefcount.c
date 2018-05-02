
@type
{
	"typeName": "Bar",
	"fields": [
		{"name": "i", "type": "int"},
		{"name": "s", "type": "String *"}
	],
	"containers": [
		{"type": "array", "typeName": "BarAr", "elemName": "Bar *"},
    ]
}
@end

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

