
struct Add {
	template<typename T> static T apply(T l, T r) {
		return l + r;
	}
};