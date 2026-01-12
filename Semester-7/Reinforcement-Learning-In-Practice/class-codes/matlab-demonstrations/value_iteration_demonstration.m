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

tolerance = 0.01;

%% Value function initialization
value_old = zeros(length(state_space), 1);
value_new = zeros(length(value_old), 1);
policy = zeros(1, length(value_old));

%% Value iteration
while 1
    for i = 1:length(state_space)
        action_rewards = zeros(1, length(action_space));
        for a = 1:length(action_space)
            action_rewards(a) = reward(state_space(i), action_space(a)) + discount_factor * sum(P(state_space(i), :, a) * value_old);
        end
        [value_new(i), policy(i)] = max(action_rewards);
    end
    if max(abs(value_new - value_old)) < tolerance
        break;
    end
    value_old = value_new;
end
