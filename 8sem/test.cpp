3
#include <utility>

template <typename InputType, typename FirstCallable, typename... RestCallable>
struct CompositeCallable final {
    FirstCallable callfirst;
    CompositeCallable<decltype(callfirst(std::declval<InputType>())),RestCallable...> callrest;
    
    CompositeCallable(FirstCallable const &callfirst, RestCallable... rest): callfirst(callfirst), callrest(rest...) { }

    auto operator()(InputType x) const {
        return callrest(callfirst(x));
    }
};

template <typename InputType, typename Callable>
struct CompositeCallable<InputType, Callable> final {
    Callable callable;

    CompositeCallable(Callable const &callable): callable(callable) { }

    auto operator()(InputType x) const {
        return callable(x);
    }
};

--------------------------
1.
template <typename T, unsigned N>
struct Vector final {
	T a;
	Vector<T, N - 1> p;
	template <typename Head, typename ...Tail>
	explicit Vector(Head a_, Tail... tail) : a(a_), p(Vector<T, N-1>(tail...)) {}
};

template <typename T>
struct Vector<T, 1> final {
	T a;
	Vector(T a_) : a(a_) {}
};
--------------------------
2.
template <typename Head>
Head accumulate(Head head)
{
    return head;
}

template <typename Head, typename ...Tail>
Head accumulate(Head head, Tail... tail) 
{
    Head sum = head;
    sum += accumulate(tail...);
    return sum;
}