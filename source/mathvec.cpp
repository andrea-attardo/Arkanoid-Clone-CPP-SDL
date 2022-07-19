#include <math.h>
#include "mathvec.h"


Vector2::Vector2( double xc, double yc ) {

    x = xc;
    y = yc;

};


Vector2 Vector2::operator+( const Vector2& vec2 ) const {

    return Vector2( x + vec2.x, y + vec2.y );

}


Vector2& Vector2::operator+=( const Vector2& vec2 ) {

    x += vec2.x;
    y += vec2.y;

    return *this;

}

Vector2 Vector2::operator-( const Vector2& vec2 ) const {

    return Vector2( x - vec2.x, y - vec2.y );

}

Vector2& Vector2::operator-=( const Vector2& vec2 ) {

    x -= vec2.x;
    y -= vec2.y;

    return *this;

}

Vector2 Vector2::operator*( double k ) const {

    return Vector2( x * k, y * k );

}


Vector2 operator*( double k, const Vector2& vec2 ) {


    return Vector2( k * vec2.x , k * vec2.y );

}


Vector2& Vector2::operator*=( double k ) {

    x *= k;
    y *= k;

    return *this;

}


double Vector2::length() const {

    return sqrt( pow( x, 2 ) + pow( y, 2 ) );
}
