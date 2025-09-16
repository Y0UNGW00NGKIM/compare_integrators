Updated Readme here!
bab6cw, Youngwoong Kim, David

1. Used cpp. Found that integ is defined twice in python file, so deleted it.
2. errtable.cpp and errors_even.gnuplo can be used to plot two graphs. Errors.png is from N = even numbers, so Simpson = 0 and does not show. Errors_OddSimpson.png is from N = 3, 11, 21... so Simpson is visible.
3. .tsv files show the actual errors and corresponding N values.

4. For BadError, I used the following function: A high frequency oscillatory integrand f(x) = sin(wx) on [0,1] with a large angular frequency (Used w = 5000 for the graph). The exact integral is [1-cos(w)]/w, so the ground truth is available for error calculations. I did mind about choosing w not too close to integer multiples of 2 pi, because that will just make I(w) close to 0 and can inflate relative error metrics for reasons unrelated to quadrature rule.

   All three rules that we have - trapezoid, simpson, Gauss - use fixed nodes, so when the point spacing h ~ 1 / (N-1) is larger than the signal's period T = 2pi/w, sampling undershoots oscillations and aliasing occurs. Although Gauss-Legendre should perform better, when w is large, there are simply too few to resolve all sign changes, so integral goes wildly wrong until N grows roughly in proportion to w.

   To improve this using the tools provided, I think we can partition the [0,1] into many panels, say P, and apply our existing tools on each panel then sum them all. We can make the panel width smaller to have like 4-8 Gauss points per panel, I think the error should drop.
   Or we can also place the panel boundaries at known zeros, so we integrate over half-waves.
