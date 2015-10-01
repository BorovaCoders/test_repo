function [X_norm, mu, sigma] = featureNormalize(X)
%FEATURENORMALIZE Normalizes the features in X 
%   FEATURENORMALIZE(X) returns a normalized version of X where
%   the mean value of each feature is 0 and the standard deviation
%   is 1. This is often a good preprocessing step to do when
%   working with learning algorithms.

% You need to set these values correctly

mu = mean(X);
sigma = std(X);

m = size(X, 1);
X_norm = X - ones(m,1) * mu; % zero mean
X_norm = X_norm ./ (ones(m,1) * sigma); % zero std

end
