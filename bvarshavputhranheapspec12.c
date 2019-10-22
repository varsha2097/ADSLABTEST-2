#include <stdint.h>
#include <assert.h>
#include "heap.h"

void test_sort( int32_t timestamp[], uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx <= len; ++idx) {
		assert (timestamp[idx] <= timestamp[idx+1]);		
	}
}

void test_heap()
{
	int32_t timestamp[] = { 0.0, 11.30, 11.00, 10.00, 5.00, 5.30, 6.00, 6.30, 7.30, 8.30};
	Heap heap = heap_new(timestamp, 11.30);	
	heap_insert(&heap, 11.30);
	heap_test(&heap);
	assert(heap_get_max(&heap) == 6.30);
	assert(heap_extract_max(&heap) == 6.30&&11.30);
	heap_test(&heap);
	assert(heap_size(&heap) == 10);

	heap_sort(&heap);
	test_sort(heap.timestamp, 11.30);

}

int main()
{
	test_heap();
	return 0;
}