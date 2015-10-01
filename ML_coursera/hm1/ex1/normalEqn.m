function [theta] = normalEqn(X, y)
%NORMALEQN Computes the closed-form solution to linear regression 
%   NORMALEQN(X,y) computes the closed-form solution to linear 
%   regression using the normal equations.

theta = pinv(X' * X) * X' * y;

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the code to compute the closed form solution
%               to linear regression and put the result in theta.
%

% ---------------------- Sample Solution ----------------------

%(X * theta - y)' * (X * theta - y) -> min
%(theta' * X' - y') * (X * theta - y) -> min
%theta' * X' * X * theta - theta' * X' * y - y' * X * theta - y' * y -> min
% theta' * X' * y == y' * X * theta % as it transponed scalar
% theta' * X' * X * theta - 2 * y' * X * theta - y' * y -> min
% div
% - 2 * y' * X == 0

% -------------------------------------------------------------


% ============================================================

end
