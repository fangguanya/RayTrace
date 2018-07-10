﻿#ifndef RAY_H
#define RAY_H

#include "vector3.h"

namespace HYF{

class Ray
{
public:
	Ray() : m_Origin( vector3( 0, 0, 0 ) ), m_Direction( vector3( 0, 0, 0 ) ) {};
	Ray( const vector3& p_Origin, const vector3& p_Dir ): m_Origin( p_Origin ), m_Direction( p_Dir ){}
	inline void setOrigin( vector3& p_Origin ) { m_Origin = p_Origin; }
	inline void setDirection( vector3& p_Direction ) { m_Direction = p_Direction; }
	inline vector3& getOrigin() { return m_Origin; }
	inline vector3& getDirection() { return m_Direction; }
private:
	vector3 m_Origin;
	vector3 m_Direction;
};

}
#endif