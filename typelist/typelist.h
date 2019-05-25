template <typename... Element>
class TypeList {};

template <typename List>
class FrontT;

// 偏特化
template <typename Head, typename... Tail>
class FrontT<TypeList<Head, Tail...>> {
public:
    using Type = Head;
};

template <typename List>
using Front = typename FrontT<List>::Type;

template <typename List>
class PopFrontT;

template <typename Head, typename... Tail>
class PopFrontT<TypeList<Head, Tail...>> {
public:
    using Type = Tail;
};

template <typename List>
using PopFront = typename PopFrontT<List>::Type;

template <typename NewEelement, typename List>
class PushFrontT;

// TODO
template <typename NewElement, typename... Elements>
class PushFrontT<TypeList<Elements...>, NewElement> {
public:
    using Type = TypeList<NewElement, Elements...>;
};

template <typename NewElement, typename List>
using PushFront = typename PushFrontT<NewElement, List>::Type;