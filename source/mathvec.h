#ifndef MATHVEC_H
#define MATHVEC_H


class Vector2 {
public:
    double x;
    double y;

    Vector2( double xc = 0, double yc = 0 );

    Vector2 operator+( const Vector2& vec2 ) const;

    Vector2& operator+=( const Vector2& vec2 );

    Vector2 operator-( const Vector2& vec2 ) const;

    Vector2& operator-=( const Vector2& vec2 );

    Vector2 operator*( double k ) const;

    friend Vector2 operator*( double k, const Vector2& vec2 );

    Vector2& operator*=( double k );

    double length() const;

};




#endif