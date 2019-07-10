{::nomarkdown}
  
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"  
  "http://www.w3.org/TR/html4/loose.dtd">  
<html > 
<head><title>Newtonsolver !not yet ready to use</title> 
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1"> 
<meta name="generator" content="TeX4ht (http://www.tug.org/tex4ht/)"> 
<meta name="originator" content="TeX4ht (http://www.tug.org/tex4ht/)"> 
<!-- html --> 
<meta name="src" content="Readme.tex"> 
<link rel="stylesheet" type="text/css" href="Readme.css"> 
</head><body 
>
   <div class="maketitle">



<h2 class="titleHead">Newtonsolver !not yet ready to use</h2>
<div class="author" ><span 
class="cmr-12">Julian K</span><span 
class="cmr-12">öberle</span></div><br />
<div class="date" ><span 
class="cmr-12">July 10, 2019</span></div>
   </div>
<!--l. 16--><p class="indent" >   let&#8217;s define a function
<!--l. 18--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme0x.png" alt="f(x) : &#x211D; &#x2192; &#x211D;
" class="math-display" ></center>
<!--l. 20--><p class="indent" >   We now the Taylor-Series is defined as:
<!--l. 22--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme1x.png" alt="       &#x2211;&#x221E;  dnf     (x - x0)n
T (x) :=    dxn|x=x0---n!---
       n=0
" class="math-display" ></center>
<!--l. 24--><p class="indent" >   or short
<!--l. 26--><p class="indent" >

   <center class="math-display" >
<img 
src="Readme2x.png" alt="                              2             2
T(x) = f(x0)+ df-|x=x (x- x0)+ d-f|x=x (x--x0) ...
             dx    0         dx2    0   2
" class="math-display" ></center>
<!--l. 28--><p class="indent" >   let&#8217;s define
   <center class="math-display" >
<img 
src="Readme3x.png" alt="x := x + h &#x21D2; x  = x- h
     0       0
" class="math-display" ></center>
<!--l. 31--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme4x.png" alt="T (x  + h) = f(x )+ df|   h+ d2f |   h2 ...
   0          0   dx x=x0   dx2 x=x0 2
" class="math-display" ></center>
<!--l. 33--><p class="indent" >   this means
<!--l. 35--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme5x.png" alt="                  &#x2032;
f(x0 + h) &#x2248; f(x0)+ f (x0)h
" class="math-display" ></center>
<!--l. 37--><p class="indent" >   define

   <center class="math-display" >
<img 
src="Readme6x.png" alt="x0 + h := xn+1  " class="math-display" ></center>
and
   <center class="math-display" >
<img 
src="Readme7x.png" alt="x0 := xn &#x21D2; h = xn+1 - xn
" class="math-display" ></center>
<!--l. 39--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme8x.png" alt="f(xn+1) &#x2248; f(xn)+ f&#x2032;(xn)(xn+1 - xn)
" class="math-display" ></center>
<!--l. 41--><p class="indent" >   we are interested in
   <center class="math-display" >
<img 
src="Readme9x.png" alt="f(x) = 0
" class="math-display" ></center>
<!--l. 43--><p class="indent" >   than the above equations becomes to:
<!--l. 45--><p class="indent" >

   <center class="math-display" >
<img 
src="Readme10x.png" alt="        &#x2032;          &#x2032;
f(xn )+ f(xn)xn+1 - f (xn)xn = 0 &#x21D2;
" class="math-display" ></center>
<!--l. 47--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme11x.png" alt="        f(xn)
xn+1 = - f&#x2032;(x-)-+ xn
           n
" class="math-display" ></center>
<!--l. 49--><p class="indent" >   ***
<!--l. 51--><p class="indent" >   Newton solver in :
   <center class="math-display" >
<img 
src="Readme12x.png" alt="&#x211D;n
" class="math-display" ></center>
<!--l. 53--><p class="indent" >   let&#8217;s define a function
<!--l. 55--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme13x.png" alt="      n     m
g(x) : &#x211D; &#x2192; &#x211D;
" class="math-display" ></center>
<!--l. 57--><p class="indent" >   for

   <center class="math-display" >
<img 
src="Readme14x.png" alt="g(x) = 0 &#x21D2;
" class="math-display" ></center>
<!--l. 59--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme15x.png" alt="g(xn) +Jg (xn )(xn+1 - xn ) = 0
" class="math-display" ></center>
<!--l. 61--><p class="indent" >   we define
   <center class="math-display" >
<img 
src="Readme16x.png" alt="&#x0394;x := x    - x
      n+1    n
" class="math-display" ></center>
<!--l. 63--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme17x.png" alt="&#x21D2;
" class="math-display" ></center>
<!--l. 65--><p class="indent" >

   <center class="math-display" >
<img 
src="Readme18x.png" alt="Jg(xn)&#x0394;x = - g(xn)
" class="math-display" ></center>
<!--l. 67--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme19x.png" alt="( &#x2202;g1  &#x2202;g1  ...  -&#x2202;g1)      (    )    (  )
| &#x2202;x1  &#x2202;x2      &#x2202;xn.|        &#x0394;x1      g1
|| &#x2202;&#x2202;gx21  &#x2202;&#x2202;gx22  ...    ..||      || &#x0394;x2||    ||g2||
||  ..    ..   ..    ..|| |x=xn|(  ... |)  = |( ...|)
( &#x2202;.g    .     . &#x2202;g.)        &#x0394;x       g
  &#x2202;xn1  ...  ...  &#x2202;xnn           n       n
" class="math-display" ></center>
<!--l. 85--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme20x.png" alt=" &#x2202;g            g(...,&#x03BE;n-1,&#x03BE;n + &#x0394;x,&#x03BE;n+1,...) - g(...,&#x03BE;n- 1,&#x03BE;n,&#x03BE;n+1,...)
&#x2202;x--|x=&#x03BE; = &#x0394;lixm&#x2192;0 ----------------------&#x0394;x-------------------------
   n
" class="math-display" ></center>
<!--l. 87--><p class="indent" >   to calculate the derivative numerically we just say:
<!--l. 90--><p class="indent" >
   <center class="math-display" >
<img 
src="Readme21x.png" alt="&#x2202;g-|   &#x2248; g(...,&#x03BE;n-1,&#x03BE;n +-10-10,&#x03BE;n+1,...)--g(...,&#x03BE;n-1,&#x03BE;n,&#x03BE;n+1,...)
&#x2202;xn x=&#x03BE;                         10-10
" class="math-display" ></center>
    
</body></html> 
{:/}
