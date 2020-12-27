#pragma once


class Vec2 {
public:
	double m_xy[2];
	Vec2();
	Vec2(double x, double y);
	virtual size_t length() const;
};

class Vec3 : public Vec2 {
protected:
	double m_z;
public:
	Vec3();
	Vec3(double x, double y, double z);
	size_t length() const override;
	void product(const Vec2& other);
};