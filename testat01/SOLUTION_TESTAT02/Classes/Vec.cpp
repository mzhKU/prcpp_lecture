

class Vec2 {
public:                                                          // 'public'
	double m_xy[2];
	Vec2() {}                                                    // Standard constructor
	Vec2(double x, double y) : m_xy{ x, y } {}
	virtual size_t length() const { return 2; }                  // 'virtual'
};

class Vec3 : public Vec2 {
protected:
public:
	double m_z;                                                  // 'public' m_z
	Vec3() : m_z{ 0 } {}                                         // Standard constructor
	Vec3(double x, double y, double z=0) : Vec2(x, y), m_z{ z } {}
	size_t length() const override { return 3; }
	Vec3 product(const Vec2& other) {                // Don't return reference
		Vec3 r;
		const double* in1 = m_xy; // , in2 = other.m_xy;         
		const double* in2 = other.m_xy;                          // '*' needed
		double* out = r.m_xy;

		for (size_t i = 0; i < length(); i++) {
			*out++ = *in1++ * *in2++;
		}

		return r;
	}
};