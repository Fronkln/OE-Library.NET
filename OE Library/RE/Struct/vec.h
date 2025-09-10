#include <xmmintrin.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <algorithm>

#include <xmmintrin.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <algorithm>

#ifndef VECTOR4F
#define VECTOR4F
struct vec4f
{

public:
    float x;
    float y;
    float z;
    float w;

public:
    operator __m128() const
    {
        __m128 m;
        m.m128_f32[0] = x;
        m.m128_f32[1] = y;
        m.m128_f32[2] = z;
        m.m128_f32[3] = w;

        return m;
    }

    vec4f(const vec4f& p1)
    {
        x = p1.x;
        y = p1.y;
        z = p1.z;
        w = p1.w;
    }

    static vec4f movetowards(vec4f current, vec4f target, float maxDistanceDelta)
    {
        // avoid vector ops because current scripting backends are terrible at inlining
        float toVector_x = target.x - current.x;
        float toVector_y = target.y - current.y;
        float toVector_z = target.z - current.z;

        float sqdist = toVector_x * toVector_x + toVector_y * toVector_y + toVector_z * toVector_z;

        if (sqdist == 0 || (maxDistanceDelta >= 0 && sqdist <= maxDistanceDelta * maxDistanceDelta))
            return target;

        float dist = sqrt(sqdist);

        return vec4f(current.x + toVector_x / dist * maxDistanceDelta,
            current.y + toVector_y / dist * maxDistanceDelta,
            current.z + toVector_z / dist * maxDistanceDelta);
    }

    static vec4f lerp(vec4f a, vec4f b, float t)
    {
        return vec4f(
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t
        );
    }

    /*
    //lerping done unity style
    static vec4f lerp(vec4f a, vec4f b, float t)
    {
        vec4f result;


        result.x = lerp(a.x, a.x, t);
        result.y = lerp(a.y, a.y, t);
        result.z = lerp(a.z, a.z, t);
        result.z = lerp(a.w, a.w, t);


        return result;
    }
    */

    vec4f operator+(vec4f vecB)
    {
        vec4f result;

        result.x = x + vecB.x;
        result.y = y + vecB.y;
        result.z = z + vecB.z;
        result.w = w + vecB.w;

        return result;
    }

    vec4f operator-(vec4f vecB)
    {
        vec4f result;

        result.x = x - vecB.x;
        result.y = y - vecB.y;
        result.z = z - vecB.z;
        result.w = w - vecB.w;

        return result;
    }

    vec4f operator*(float mult)
    {
        vec4f result;

        result.x = x * mult;
        result.y = y * mult;
        result.z = z * mult;
        result.w = w * mult;

        return result;
    }



    vec4f(const __m128& vecm128)
    {
        vec4f vec;

        vec.x = vecm128.m128_f32[0];
        vec.y = vecm128.m128_f32[1];
        vec.z = vecm128.m128_f32[2];
        vec.w = vecm128.m128_f32[3];
    }

    friend std::ostream& operator<<(std::ostream& output, const vec4f& vec)
    {
        output << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;
        //output << "F : " << D.feet << " I : " << D.inches;
        return output;
    }

    vec4f()
    {
        x = 0;
        y = 0;
        z = 0;
        w = 0;
    }
    vec4f(float x, float y, float z, float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
    vec4f(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = 0;
    }

    static vec4f zero()
    {
        vec4f vec;
        return vec;
    }

    static vec4f one()
    {
        vec4f vec;
        vec.x = 1;
        vec.y = 1;
        vec.z = 1;
        vec.y = 1;
        return vec;
    }

};

#endif // ! VECTOR4F

#ifndef VECTOR3F
#define VECTOR3F
struct vec3f
{
public:
    float x;
    float y;
    float z;

public:

    vec3f(const vec3f& p1)
    {
        x = p1.x;
        y = p1.y;
        z = p1.z;
    }

    static vec3f movetowards(vec3f current, vec3f target, float maxDistanceDelta)
    {
        // avoid vector ops because current scripting backends are terrible at inlining
        float toVector_x = target.x - current.x;
        float toVector_y = target.y - current.y;
        float toVector_z = target.z - current.z;

        float sqdist = toVector_x * toVector_x + toVector_y * toVector_y + toVector_z * toVector_z;

        if (sqdist == 0 || (maxDistanceDelta >= 0 && sqdist <= maxDistanceDelta * maxDistanceDelta))
            return target;

        float dist = sqrt(sqdist);

        return vec3f(current.x + toVector_x / dist * maxDistanceDelta,
            current.y + toVector_y / dist * maxDistanceDelta,
            current.z + toVector_z / dist * maxDistanceDelta);
    }

    static vec3f lerp(vec3f a, vec3f b, float t)
    {
        return vec3f(
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t
        );
    }


    operator vec4f() const
    {
        vec4f vec;
        vec.x = x;
        vec.y = y;
        vec.z = z;

        vec.w = 0;

        return vec;
    }
    /*
    //lerping done unity style
    static vec4f lerp(vec4f a, vec4f b, float t)
    {
        vec4f result;


        result.x = lerp(a.x, a.x, t);
        result.y = lerp(a.y, a.y, t);
        result.z = lerp(a.z, a.z, t);
        result.z = lerp(a.w, a.w, t);


        return result;
    }
    */

    vec3f operator+(vec3f vecB)
    {
        vec3f result;

        result.x = x + vecB.x;
        result.y = y + vecB.y;
        result.z = z + vecB.z;

        return result;
    }

    vec3f operator-(vec3f vecB)
    {
        vec3f result;

        result.x = x - vecB.x;
        result.y = y - vecB.y;
        result.z = z - vecB.z;
        return result;
    }

    vec3f operator*(float mult)
    {
        vec3f result;

        result.x = x * mult;
        result.y = y * mult;
        result.z = z * mult;

        return result;
    }


    friend std::ostream& operator<<(std::ostream& output, const vec3f& vec)
    {
        output << vec.x << " " << vec.y << " " << vec.z;
        return output;
    }

    vec3f()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    vec3f(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    static vec3f zero()
    {
        vec3f vec;
        return vec;
    }

    static vec3f one()
    {
        vec3f vec;
        vec.x = 1;
        vec.y = 1;
        vec.z = 1;

        return vec;
    }

};

#endif // ! VECTOR4F