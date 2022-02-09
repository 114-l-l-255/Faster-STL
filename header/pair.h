#ifndef FSTLPairH
	#define FSTLPairH
	
	template<typename T1, typename T2, typename T3 = void, typename T4 = void, typename T5 = void> struct pair {
		T1 first;
		T2 second;
		T3 third;
		T4 fourth;
		T5 fifth;
		pair() {}
		pair(T1 t1) { first = t1; }
		pair(T1 t1, T2 t2) { first = t1; second = t2;}
		pair(T1 t1, T2 t2, T3 t3) { first = t1; second = t2; third = t3; }
		pair(T1 t1, T2 t2, T3 t3, T4 t4) { first = t1; second = t2; third = t3; fourth = t4; }
		pair(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) { first = t1; second = t2; third = t3; fourth = t4; fifth = t5; }
		bool operator < (const pair<T1, T2, T3, T4, T5>& sec) const {
			return first == sec.first ? second == sec.second ? third == sec.third ? fourth == sec.fourth ? fifth < sec.fifth : fourth < sec.fourth : third < sec.third : second < sec.second : first < sec.first;
		}
	};
	template<typename T1, typename T2, typename T3, typename T4> struct pair<T1, T2, T3, T4, void> {
		T1 first;
		T2 second;
		T3 third;
		T4 fourth;
		pair() {}
		pair(T1 t1) { first = t1; }
		pair(T1 t1, T2 t2) { first = t1; second = t2;}
		pair(T1 t1, T2 t2, T3 t3) { first = t1; second = t2; third = t3; }
		pair(T1 t1, T2 t2, T3 t3, T4 t4) { first = t1; second = t2; third = t3; fourth = t4; }
		bool operator < (const pair<T1, T2, T3, T4>& sec) const {
			return first == sec.first ? second == sec.second ? third == sec.third ? fourth < sec.fourth : third < sec.third : second < sec.second : first < sec.first;
		}
	};
	template<typename T1, typename T2, typename T3> struct pair<T1, T2, T3, void, void> {
		T1 first;
		T2 second;
		T3 third;
		pair() {}
		pair(T1 t1) { first = t1; }
		pair(T1 t1, T2 t2) { first = t1; second = t2;}
		pair(T1 t1, T2 t2, T3 t3) { first = t1; second = t2; third = t3; }
		bool operator < (const pair<T1, T2, T3>& sec) const {
			return first == sec.first ? second == sec.second ? third < sec.third : second < sec.second : first < sec.first;
		}
	};
	template<typename T1, typename T2> struct pair<T1, T2, void, void, void> {
		T1 first;
		T2 second;
		pair() {}
		pair(T1 t1) { first = t1; }
		pair(T1 t1, T2 t2) { first = t1; second = t2;}
		bool operator < (const pair<T1, T2>& sec) const {
			return first == sec.first ? second < sec.second : first < sec.first;
		}
	};
	
	template<typename T1, typename T2, typename T3, typename T4, typename T5> pair<T1, T2, T3, T4, T5> make_pair(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) {
		return pair<T1, T2, T3, T4, T5>(t1, t2, t3, t4, t5);
	}
//	template<typename T1, typename T2, typename T3 = void> struct pair {
//		T1 first;
//		T2 second;
//		bool operator < (const pair<T1, T2>& sec) const {
//			return first == sec.first ? second < sec.second : first < sec.first;
//		}
//	};
//	template<typename T1, typename T2> struct pair<T1, T2, typename T3> {
//		T1 first;
//		T2 second;
//		T3 third;
//		bool operator < (const pair<T1, T2, T3>& sec) const {
//			return first == sec.first ? second == sec.second ? third < sec.third : second < sec.second : first < sec.first;
//		}
//	};
#endif
