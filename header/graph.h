#include "pair.h"
#include <cstdio>
#ifndef FSTLGraphH
	#define FSTLGraphH
	/*
	iterator
	|-itera* it
	| |-pair<int, int>* d
	| | |-int first
	| | |-int second
	| | =
	| |-itera* nxt
	| =
	=
	*/
	template<int n> class unvaluable_graph {
			int tp;
			struct itera {
				pair<int, int>* d;
				itera* nxt;
				itera() {
					d = new pair<int, int>;
					nxt = NULL;
				}
				~itera() {
					delete d;
				}
			};
			void cleard(itera* v) {
				if (v) {
					cleard(v->nxt);
					delete v;
				}
			}
			itera* head[n + 1];
			itera* tail[n + 1];
		public:
			class iterator {
					itera* it;
				public:
					iterator() {
						it = NULL;
					}
					iterator(const itera* x) {
						it = x;
					}
					iterator(itera* x) {
						it = x;
					}
					iterator& operator = (const itera*& x) {
						it = x;
						return (*this);
					}
					iterator& operator = (itera*& x) {
						it = x;
						return (*this);
					}
					iterator& operator ++ () {
						if (it) it = it->nxt;
						return (*this);
					}
					const iterator operator ++ (int) {
						iterator tmp = *this;
						if (it) it = it->nxt;
						return tmp;
					}
					const pair<int, int>* operator -> () {
						if (it) return it->d;
						else return (pair<int, int>*)0;
					}
					bool operator == (const iterator& x) {
						return it == x.it;
					}
					template<typename T> bool operator != (const T& x) {
						return !((*this) == x);
					}
			};
			void clear() {
				for (int i = 0; i <= n; i++) {
					cleard(head[i]);
					head[i] = tail[i] = new itera;
				}
				tp = 0;
			}
			unvaluable_graph() {
				clear();
			}
			~unvaluable_graph() {
				clear();
			}
			void add(int u, int v) {
				itera* x = new itera;
				x->d->first = u;
				x->d->second = v;
				x->nxt = head[u];
				head[u] = x;
			}
			const iterator begin(int nd) {
				return (iterator)head[nd];
			}
			const iterator end(int nd) {
				return (iterator)tail[nd];
			}
	};
	template<int n, typename Valtype> class valuable_graph {
			int tp;
			struct itera {
				pair<int, int, Valtype>* d;
				itera* nxt;
				itera() {
					d = new pair<int, int, Valtype>;
					nxt = NULL;
				}
				~itera() {
					delete d;
				}
			};
			void cleard(itera* v) {
				if (v) {
					cleard(v->nxt);
					delete v;
				}
			}
			itera* head[n + 1];
			itera* tail[n + 1];
		public:
			class iterator {
					itera* it;
				public:
					iterator() {
						it = NULL;
					}
					iterator(const itera* x) {
						it = x;
					}
					iterator(itera* x) {
						it = x;
					}
					iterator& operator = (const itera*& x) {
						it = x;
						return (*this);
					}
					iterator& operator = (itera*& x) {
						it = x;
						return (*this);
					}
					iterator& operator ++ () {
						if (it) it = it->nxt;
						return (*this);
					}
					const iterator operator ++ (int) {
						iterator tmp = *this;
						if (it) it = it->nxt;
						return tmp;
					}
					const pair<int, int, Valtype>* operator -> () {
						if (it) return it->d;
						else return (pair<int, int, Valtype>*)0;
					}
					bool operator == (const iterator& x) {
						return it == x.it;
					}
					template<typename T> bool operator != (const T& x) {
						return !((*this) == x);
					}
			};
			void clear() {
				for (int i = 0; i <= n; i++) {
					cleard(head[i]);
					head[i] = tail[i] = new itera;
				}
				tp = 0;
			}
			valuable_graph() {
				clear();
			}
			~valuable_graph() {
				clear();
			}
			void add(int u, int v, Valtype w) {
				itera* x = new itera;
				x->d->first = u;
				x->d->second = v;
				x->d->third = w;
				x->nxt = head[u];
				head[u] = x;
			}
			const iterator begin(int nd) {
				return (iterator)head[nd];
			}
			const iterator end(int nd) {
				return (iterator)tail[nd];
			}
	};
#endif
