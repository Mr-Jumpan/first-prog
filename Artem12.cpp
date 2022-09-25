#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "ArtemLib12.h"

CVectR2::CVectR2(){x=0; y=0;}
CVectR2::CVectR2 (double x0, double y0){x=x0; y=y0;}
CVectR2::operator double()const{return sqrt(x*x + y*y);}
double CVectR2::Angl()const{double a=0; double r=(double)(*this); if(r > 1e-10){if(y<0){a=2.*pi-acos(x/r);}else{a=acos(x/r);}} return a;}

CVect::CVect (CVectR2 v0){for(int i=0; i<N; i++){v[i]=v0;}} 
CVect::CVect (double x0, double y0){CVectR2 v0(x0, y0); for(int i=0; i<N; i++){v[i]=v0;}}
CVect::CVect (CVectR2* v0){for(int i=0; i<N; i++){v[i]=v0[i];}}


CAngl::CAngl (double a0){for(int i=0; i<N; i++){a[i]=a0;}}
CAngl::CAngl (const CVect &m1, const CVect &m2){for(int i=0; i<N; i++){a[i]=m1.v[i]-m2.v[i];}}
CAngl::CAngl (double* a0){for(int i=0; i<N; i++){a[i]=a0[i];}}

ostream &operator<< (ostream &os, const CVectR2 &v){os<<"("<<v.x<<", "<<v.y<<")"; return os;}
double operator* (const CVectR2 &v1, const CVectR2 &v2){return v1.x*v2.x + v1.y*v2.y;}
double operator-(const CVectR2 &v1, const CVectR2 &v2){double a = 0; if(((double)v1)*((double)v2) > 1e-10){a=v1.Angl() - v2.Angl(); if(a<0){a=2.*pi+a;}} return a;}
const CVectR2 operator+(const CVectR2 &v, double a){CVectR2 r(v.x*cos(a) - v.y*sin(a), v.x*sin(a) + v.y*cos(a)); return r;}
const CVectR2 operator+(double a, const CVectR2 &v){CVectR2 r(v.x*cos(a) - v.y*sin(a), v.x*sin(a) + v.y*cos(a)); return r;}
const CVectR2 operator+(const CVectR2 &v, int a){CVectR2 r(v.x*cos(a) - v.y*sin(a), v.x*sin(a) + v.y*cos(a)); return r;}
const CVectR2 operator+(int a, const CVectR2 &v){CVectR2 r(v.x*cos(a) - v.y*sin(a), v.x*sin(a) + v.y*cos(a)); return r;}

ostream &operator<< (ostream &os, const CVect &m){for(int i=0; i<N; i++){os<<m.v[i]; os<<" ";} return os;}
ostream &operator<< (ostream &os, const CAngl &m){os<<"("; for(int i=0; i<N; i++){os<<180*m.a[i]/pi<<" deg"; if(i+1!=N){os<<", ";}} os<<")"; return os;}
const CAngl operator-(const CVect &mv1, const CVect &mv2){CAngl ma(mv1, mv2); return ma;}
const CVect operator+(const CVect &mv, const CAngl &ma){CVect mr; for(int i=0; i<N; i++){mr.v[i]=mv.v[i]+ma.a[i];} return mr;}
const CVect operator+(const CAngl &ma, const CVect &mv){CVect mr; for(int i=0; i<N; i++){mr.v[i]=ma.a[i]+mv.v[i];} return mr;}
