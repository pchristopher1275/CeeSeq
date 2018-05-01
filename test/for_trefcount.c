
@type
{
	"typeName": "StdRefCount",
	"fields": [
		{"name": "i", "type": "int"},
		{"name": "s", "type": "String *"}
	],
	"containers": [
		{"type": "array", "typeName": "StdRefCountAr", "elemName": "StdRefCount *"},
    ]
}
@end

@type
{
	"typeName": "StdRefCount2",
	"fields": [
		{"name": "i", "type": "int"},
		{"name": "s", "type": "String *"},
		{"name": "r", "type": "StdRefCount *"}
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

