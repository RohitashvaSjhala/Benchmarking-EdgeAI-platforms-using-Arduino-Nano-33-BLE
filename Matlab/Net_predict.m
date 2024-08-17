function out = Net_predict(in)
persistent mydlnet;
%global quantizedNet
%mynet = coder.loadDeepLearningNetwork('matlab_trainnet_object.mat');
%mynet = quantizedNet;
if isempty(mydlnet)
    % Load the network only if it has not been loaded before
    mydlnet = coder.loadDeepLearningNetwork('matlab_trainnet_object.mat');
end

in = reshape(in, [1, size(in,1), size(in,2), 1]);

in = dlarray(in, 'SSCB');
out = predict(mydlnet,in);
end