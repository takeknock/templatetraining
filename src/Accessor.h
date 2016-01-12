
//reference1 : https://gist.github.com/dabrahams/1528856
//reference2 : http://d.hatena.ne.jp/redboltz/20120111/1326292284
template <class Tag>
class Accessor {
public:
    static typename Tag::type value;
};

template <class Tag>
typename Tag::type Accessor<Tag>::value;

template <class Tag, typename Tag::type p>
class Initializer {
public:
    Initializer() 
    {
        Accessor<Tag>::value = p;
    }
    static Initializer instance;
};

template <class Tag, typename Tag::type p>
Initializer<Tag, p> Initializer<Tag, p>::instance;



