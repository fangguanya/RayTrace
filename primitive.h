#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "all.h"

namespace HYF
{

class Material
{
public:
	Material();
	inline void setColor( Color& p_Color ) { m_Color = p_Color; }
	inline Color getColor() { return m_Color; }
	inline void setSpecular( double p_Spec ) { m_Spec = p_Spec; }//高光
	inline void setDiffuse( double p_Diff ) { m_Diff = p_Diff; }
	inline void setReflection( double p_Refl ) { m_Refl = p_Refl; }
	inline void setDiffRefl(double p_DiffRefl ) { m_DiffRefl = p_DiffRefl; }
	inline void setRefraction( double p_Refr ) { m_Refr = p_Refr; }
	inline void setRefr_Rate( double p_Refr_Rate ) { m_Refr_Rate = p_Refr_Rate; }
	inline double getSpecular() { return m_Spec; }//高光
	inline double getDiffuse() { return m_Diff; }//漫反射
	inline double getReflection() { return m_Refl;}
	inline double getDiffRefl() { return m_DiffRefl;}
	inline double getRefraction() { return m_Refr;}
	inline double getRefr_Rate() { return m_Refr_Rate;}
private:
	Color m_Color;//材质颜色
	double m_Refl;//反射系数
	double m_DiffRefl;//漫镜面反射系数
	double m_Diff;//漫反射系数
	double m_Spec;//高光
	double m_Refr;//透射率
	double m_Refr_Rate;//折射率
};

class Primitive
{
public:
	enum
	{
		SPHERE = 1,
		PLANE = 2,
		BOX = 3
	};
	Primitive() : m_Name( 0 ), m_Light( false ) {};
	inline Material* getMaterial() { return &m_Material; }
	inline void setMaterial( Material& p_Mat ) { m_Material = p_Mat; }

	virtual int getType() = 0;
	virtual int Intersect( Ray& p_Ray, double& p_Dist ) = 0;
	virtual bool H_IntersectBox( BoundingBox& ) = 0;
	virtual vector3 getNormal( vector3& p_Pos ) = 0;
	virtual Color getColor() { return m_Material.getColor(); }
	virtual void Light( bool p_Light ) { m_Light = p_Light; }
	virtual BoundingBox getBoundingBox() = 0;
	
	inline bool IsLight() { return m_Light; }
	void setName( char* p_Name );
	inline char* getName() { return m_Name; }
protected:
	Material m_Material;
	char* m_Name;
	bool m_Light;
};

class Round
{
	//to be added
};

}

#endif