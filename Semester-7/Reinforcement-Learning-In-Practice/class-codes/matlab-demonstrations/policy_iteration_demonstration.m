%% MDP parameters
state_space = [1,2,3];
action_space = [1,2];
reward = repmat(state_space', 1, 2) + repmat(action_space .^ 2, 3, 1);
discount_factor = 0.7;
P = zeros(3,3,2);
P(:,:,1) = [0.1, 0.1, 0.8;
    0.2, 0.3, 0.5;
    0.8, 0.1, 0.1];
P(:,:,2) = [0.8, 0.1, 0.1;
    0.6, 0.2, 0.2;
    0.2, 0.1, 0.7];

%% Policy initialization
policy_old = [1, 1, 1];

%% Policy iteration
while 1
    % Policy evaluation
    % for a particular policy (policy_old) we need to solve the functional equation 
    % v(s) = r(s, policy_old(s)) + \gamma \sum_{j} P(policy_old(s))(s, j) v(j)
    % This can be put in the matrix form Av = b, where 
    % b = r(s, policy_old(s))
    % A = I - \gamma * P(policy_old(s))(s, :) - refer the more precise notation used in class
    b = [];
    A = [];
    for i = 1:length(state_space)
        b(i) = reward(state_space(i), policy_old(i));
        A_row = discount_factor * P(state_space(i), :, policy_old(i));
        A = [A; A_row];
    end
    A = eye(length(state_space)) - A;
    v = linsolve(A, b');
    
    % Policy improvement
    policy_new = zeros(1, length(state_space));
    for i = 1:length(state_space)
        action_rewards = zeros(1, length(action_space));
        for a = 1:length(action_space)
            action_rewards(a) = reward(state_space(i), action_space(a)) + discount_factor * sum(P(state_space(i), :, a) * v);
        end
        [~, policy_new(i)] = max(action_rewards); % does this require any change?
    end
    if sum(policy_new == policy_old) == length(state_space)
        break;
    end
    policy_old = policy_new;
end
