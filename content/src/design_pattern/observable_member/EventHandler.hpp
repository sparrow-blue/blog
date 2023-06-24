// Copyright (c) 2023, Kumazawa (sparrow-blue)
// This source code is licensed under the BSD 3-Clause License.
// See https://github.com/sparrow-blue/blog/blob/main/LICENSE for details.

#ifndef DESIGN_PATTERN_OBSERVABLE_MEMBER_EVENTHANDLER_HPP_
#define DESIGN_PATTERN_OBSERVABLE_MEMBER_EVENTHANDLER_HPP_

#include <functional>
#include <memory>
#include <vector>

namespace design_pattern::observable_member {

template <typename T>
class EventArgs {
 public:
  EventArgs(T after, T before) : new_value(after), old_value(before) {}
  T new_value;
  T old_value;
};

template <typename T>
class EventHandler {
  using Event = std::function<void(void*, EventArgs<T>)>;

 public:
  EventHandler() : subscribers_(std::make_unique<std::vector<Event>>()) {}
  void Invoke(void* sender, EventArgs<T> event_args) {
    std::for_each(subscribers_->begin(), subscribers_->end(),
                  [&sender, &event_args](Event& subscriber) { subscriber(sender, event_args); });
  }
  void Subscribe(Event event) { subscribers_->push_back(event); }
  void operator+=(Event&& event) { Subscribe(event); }

 private:
  const std::unique_ptr<std::vector<Event>> subscribers_;
};

}  // namespace design_pattern::observable_member

#endif  // DESIGN_PATTERN_OBSERVABLE_MEMBER_EVENTHANDLER_HPP_
