/**
 * 
 * The Priority Queue is an Abstract Data Type that in this case is implemented 
 * with the BinaryHeap data structure, there are better ways to implement it however
 * the standard libraries already have it perfectly implemented so I certainly won't 
 * be using this in my code (bad software engineering practice --> re-inventing the wheel)
 * 
 * The PriorityQueue, implemented with the Binary Heap ds has a slightly higher
 * computational complexity compared to the implementation that used Fibonacci Heaps.
 * 
 * 
 * Also we can use the Data Structure to implement the HeapSort, in-place, 
 * comparrison based, unstable sorting algorithm which has O(n log n) complexity
 * 
 * 
 * 
 */ 
#include <iostream>

template <class T> class MaxPriorityQueue
{
    public:

        virtual MaxPriorityQueue<T>* enqueue(T node) = 0;
        virtual MaxPriorityQueue<T>* dequeue() = 0;
        virtual int extractMax() = 0;
        virtual void increaseKey(int i) = 0;
};

template <class T> class MaxBinaryHeap : public MaxPriorityQueue<T>
{
    private:

        T* heap;
        int heapsize;
        int queuesize;
        int total_nodes;

        int parent(int i)
        {
            if(i % 2 == 0)
                return (i >> 1) - 1;
            return (i >> 1);    
        }

        int left(int i)
        {
            return (i << 1) + 1;
        }

        int right(int i)
        {
            return (i << 1) + 2;
        }

        void swap(T& a, T& b)
        {
            T tmp = a;
            a = b;
            b = tmp;
        }
        

        void maxHeapify(int i)
        {
            int l = left(i);
            int r = right(i);
            
            
            int largest = i;

            if(l < heapsize && heap[i] < heap[l])
            {
                largest = l;
            }
            if(r < heapsize && heap[largest] < heap[r])
            {
                largest = r;
            }
            if(largest != i)
            {
                swap(heap[largest],heap[i]);
                maxHeapify(largest);
            } 
        }

            void increaseKey(int i)
            {
                while(i > 0 && heap[i] > heap[parent(i)])
                {
                    swap(heap[i],heap[parent(i)]);
                    i = parent(i);
                }
            }

    public:

            
            MaxBinaryHeap<T>(T* array, int size)
            {
                heapsize = size;
                heap = array;
            }    

            
            MaxBinaryHeap<T>(int size)
            {
                queuesize = 0;
                heapsize = size;
                heap = new T[heapsize];
            }

            int public_left(int i)
            {
                return left(i);
            }

            int public_right(int i)
            {
                return right(i);
            }

            int public_parent(int i)
            {
                return parent(i);
            }

            void printHeap()
            {
                for(int i = 0; i < heapsize; i++)
                {
                    std::cout << heap[i] << " ";
                }
                std::cout << std::endl;
            }

            void printQueue()
            {
                for(int i = 0; i < queuesize; i++)
                {
                    std::cout << heap[i] << " ";
                }
                std::cout << std::endl;
            }

            void buildMaxHeap()
            {
                for(int i = heapsize / 2; i >= 0; i--)
                {
                    maxHeapify(i);
                }
            }

            MaxBinaryHeap<T>* enqueue(T node)
            {
                queuesize += 1;
                heap[total_nodes] = node;
                increaseKey(total_nodes);
                total_nodes += 1;
                return this;
            }

            MaxBinaryHeap<T>* dequeue()
            {
                swap(heap[queuesize-1],heap[0]);
                maxHeapify(heap[0]);
                queuesize -= 1;
                return this;
            }

            int extractMax()
            {
                return heap[0];
            }

};


int main(int argc, char** argv)
{

    int Array[7] = {25,2,8,11,15,19,7};
    MaxBinaryHeap<int>* queue = new MaxBinaryHeap<int>(Array,7);
    std::cout << "un-heapifyed array: "; queue->printHeap();
    std::cout << "heapifyed array: "; queue->buildMaxHeap();
    queue->printHeap();

    MaxBinaryHeap<int>* pQueue = new MaxBinaryHeap<int>(7);
    std::cout << "empty queue created" << std::endl;
    pQueue->enqueue(25)->enqueue(2)->enqueue(8)->enqueue(11)->enqueue(15)->enqueue(19)->enqueue(7);
    std::cout << "after enqueuing: "; pQueue->printQueue();
    std::cout << "dequeueing ..." << std::endl;
    pQueue->dequeue()->dequeue()->dequeue();
    std::cout << "Priority Queue after 3 dequeuing operations: "; pQueue->printQueue();
    

    return 0;
}