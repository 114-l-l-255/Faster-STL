#ifndef FSTLQueueH
	#define FSTLQueueH
//	#include <vector.h>
	template<typename T> class queue {
			struct nddata {
				T* x;
				nddata* linker;
			};
			//empty
			nddata *header;
			nddata *tailer;
			int sz;
		public:
			queue() {
				tailer = header = new nddata;
				sz = 0;
			}
			~queue() {
				while (header != tailer) {
					nddata* tmp = header->linker;
					delete header;
					header = tmp;
				}
				delete header;
			}
			bool empty() {
				return header == tailer;
			}
			void size() {
				return sz;
			}
			const T& front() {
				return header->linker->x;
			}
			const T& back() {
				return tailer->x;
			}
			void push(const T &x) {
				tailer = tailer->linker = new nddata;
				tailer->x = x; sz++;
			}
			void pop() {
				nddata* nxt = header->linker;
				delete header;
				header = nxt; sz--;
			}
			void swap(queue<T> &x) {
	//			int tp = this->sz;
	//			while (x.empty() == 0) this->push(x.front()), x.pop();
	//			while (tp--) x.push(this->front()), this->pop();
				nddata *xhead = x.header, *xtail = x.tailer; int s = x.sz;
				x.header = this->header, x.tailer = this->tailer, x.sz = this->sz;
				this->header = xhead, this->tailer = xtail, this->sz = s;
			}
	};
	template<typename t> class visitable_queue {
		// gugugugugugugugugugu
		// I'll back to write this class after <vector>
	};
#endif
