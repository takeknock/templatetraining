#ifndef FUNCTION_EXPRESSION_H_INCLUDED
#define FUNCTION_EXPRESSION_H_INCLUDED

template <typename E>
class FunctionExpression {
    const E& operator()() const
    {
        return static_cast<const E&> (*this);
    }
};

#endif // FUNCTION_EXPRESSION_H_INCLUDED
