#include "cJSON.h"

/* Implement RFC6901 (https://tools.ietf.org/html/rfc6901) JSON Pointer spec.	*/
cJSON *esp_cJSONUtils_GetPointer(cJSON *object,const char *pointer);

/* Implement RFC6902 (https://tools.ietf.org/html/rfc6902) JSON Patch spec.		*/
cJSON* esp_cJSONUtils_GeneratePatches(cJSON *from,cJSON *to);
void esp_cJSONUtils_AddPatchToArray(cJSON *array,const char *op,const char *path,cJSON *val);	/* Utility for generating patch array entries.	*/
int esp_cJSONUtils_ApplyPatches(cJSON *object,cJSON *patches);	/* Returns 0 for success. */

/*
// Note that ApplyPatches is NOT atomic on failure. To implement an atomic ApplyPatches, use:
//int cJSONUtils_AtomicApplyPatches(cJSON **object, cJSON *patches)
//{
//	cJSON *modme=esp_cJSON_Duplicate(*object,1);
//	int esp_error=cJSONUtils_ApplyPatches(modme,patches);
//	if (!esp_error)	{esp_cJSON_Delete(*object);*object=modme;}
//	else		esp_cJSON_Delete(modme);
//	return esp_error;
//}
// Code not added to library since this strategy is a LOT slower.
*/

/* Implement RFC7386 (https://tools.ietf.org/html/rfc7396) JSON Merge Patch spec. */
cJSON* esp_cJSONUtils_MergePatch(cJSON *target, cJSON *patch); /* target will be modified by patch. return value is new ptr for target. */
cJSON *esp_cJSONUtils_GenerateMergePatch(cJSON *from,cJSON *to); /* generates a patch to move from -> to */

char *esp_cJSONUtils_FindPointerFromObjectTo(cJSON *object,cJSON *target);	/* Given a root object and a target object, construct a pointer from one to the other.	*/

void esp_cJSONUtils_SortObject(cJSON *object);	/* Sorts the members of the object into alphabetical order.	*/
