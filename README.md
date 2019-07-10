# Solver Alpha

## not yet ready to use


***

let's define a function

$$f(x) : \mathbb{R} \rightarrow \mathbb{R}$$

We now the Taylor-Series is defined as:

$$ T(x) := \sum_{n=0}^{\infty} \frac{d^nf}{dx^n} \vert_{x=x_0}^{} \frac{(x-x_0)^n}{n!}$$

or short

$$T(x) = f(x_0)+\frac{df}{dx}\vert_{x=x_0}^{} (x-x_0) + \frac{d^2f}{dx^2}\vert_{x=x_0}^{} \frac{(x-x_0)}{2}^2 \dots$$

let's define $$x := x_0 + h \Rightarrow x_0 = x-h$$


$$T(x_0+h) = f(x_0)+\frac{df}{dx}\vert_{x=x_0}^{} h + \frac{d^2f}{dx^2}\vert_{x=x_0}^{} \frac{h^2}{2} \dots$$

this means

$$f(x_0+h) \approx f(x_0)+ f'(x_0)h$$

define  $$x_0+h := x_{n+1}$$ and $$x_0 := x_n \Rightarrow h= x_{n+1}-x_n$$

$$f(x_{n+1}) \approx f(x_n)+ f'(x_n) (x_{n+1}-x_n)$$

we are interested in $$f(x)=0$$ 

than the above equations becomes to:

$$f(x_n)+ f'(x_n)x_{n+1} -f'(x_n)x_n = 0 \Rightarrow$$

$$x_{n+1}  = - \frac{f(x_n)}{f'(x_n)} + x_n$$

***

### Newton solver in : $$\mathbb{R}^n$$

let's define a function

$$g(x) : \mathbb{R}^n \rightarrow \mathbb{R}^m$$

for $$g(x)=0 \Rightarrow$$

$$g(x_n)+ Jg(x_n) (x_{n+1}-x_n) = 0$$

we define $$\Delta x := x_{n+1}-x_n$$

$$\Rightarrow$$

$$Jg(x_n)\Delta x = -g(x_n)$$

$$\begin{pmatrix}
\frac{\partial g_1}{\partial x_1}&\frac{\partial g_1}{\partial x_2} &\dots&\frac{\partial g_1}{\partial x_n}\\
\frac{\partial g_2}{\partial x_1}&\frac{\partial g_2}{\partial x_2}&\dots&\vdots\\
\vdots&\vdots&\ddots&\vdots\\
\frac{\partial g_n}{\partial x_1}&\dots&\dots&\frac{\partial g_n}{\partial x_n}
\end{pmatrix}\Bvert_{x=x_n}^{}  \begin{pmatrix}
\Delta x_1\\
\Delta x_2\\
\vdots\\
\Delta x_n
\end{pmatrix} = \begin{pmatrix}
g_1\\
g_2\\
\vdots\\
g_n
\end{pmatrix}$$


$$\frac{\partial g}{\partial x_n} \vert_{x=\xi}^{} = \lim_{\Delta x \to 0} \frac{g(\dots,\xi_{n-1},\xi_{n}+\Delta x,\xi_{n+1},\dots ) - g(\dots,\xi_{n-1},\xi_{n},\xi_{n+1},\dots )}{\Delta x}$$

to calculate the derivative numerically
we just say:

$$\frac{\partial g}{\partial x_n} \vert_{x=\xi}^{} \approx  \frac{g(\dots,\xi_{n-1},\xi_{n}+10^{-10},\xi_{n+1},\dots ) - g(\dots,\xi_{n-1},\xi_{n},\xi_{n+1},\dots )}{10^{-10}$$






