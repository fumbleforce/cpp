#pragma once



class Vector2
{
private:
	double v[2];

public:
	double dot(const Vector2 &rhs) const;
	double lengthSquared() const;
	double length() const;

	double get(int i) const { return v[i]; }
	double set(int i, double val) { v[i] = val; }
	double getX() const { return v[0]; }
	double getY() const { return v[1]; }
	double setX(double val) { v[0] = val; }
	double setY(double val) { v[1] = val; }

	std::ostream& operator<<(std::ostream &os);
};