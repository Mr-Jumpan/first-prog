#define N 3
#define pi 3.1415926535

using namespace std;

class CVectR2;
class CVect;
class CAngl;

class CVectR2
{
private:
  double x, y;
public:
  CVectR2();
  CVectR2 (double x0, double y0);

  operator double()const;
  double Angl()const;

  friend ostream &operator<< (ostream &os, const CVectR2 &v);
  friend double operator* (const CVectR2 &v1, const CVectR2 &v2);
  friend double operator-(const CVectR2 &v1, const CVectR2 &v2);
  friend const CVectR2 operator+(const CVectR2 &v, double a);
  friend const CVectR2 operator+(double a, const CVectR2 &v);
  friend const CVectR2 operator+(const CVectR2 &v, int a);
  friend const CVectR2 operator+(int a, const CVectR2 &v);
};

class CVect
{
   friend CAngl;
private:
  CVectR2 v[N];
public:
  CVect (CVectR2 v0=CVectR2(0,0));
  CVect (double x0, double y0);
  CVect (CVectR2* v0);

  friend ostream &operator<< (ostream &os, const CVect &m);
  friend const CVect operator+(const CVect &mv, const CAngl &ma);
  friend const CVect operator+(const CAngl &ma, const CVect &mv);
};

class CAngl
{
  friend CVect;
private:
  double a[N];
public:
  CAngl (double a0=0);
  CAngl (const CVect &m1, const CVect &m2);
  CAngl (double* a0);
  
  friend ostream &operator<< (ostream &os, const CAngl &m);
  friend const CVect operator+(const CVect &mv, const CAngl &ma);
  friend const CVect operator+(const CAngl &ma, const CVect &mv);
}; 

ostream &operator<< (ostream &os, const CVectR2 &v);
double operator* (const CVectR2 &v1, const CVectR2 &v2);
double operator-(const CVectR2 &v1, const CVectR2 &v2);
const CVectR2 operator+(const CVectR2 &v, double a);
const CVectR2 operator+(double a, const CVectR2 &v);
const CVectR2 operator+(const CVectR2 &v, int a);
const CVectR2 operator+(int a, const CVectR2 &v);

ostream &operator<< (ostream &os, const CVect &m);
ostream &operator<< (ostream &os, const CAngl &m);
const CAngl operator-(const CVect &mv1, const CVect &mv2);
const CVect operator+(const CVect &mv, const CAngl &ma);
const CVect operator+(const CAngl &ma, const CVect &mv);

