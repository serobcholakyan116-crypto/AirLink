#pragma once
#include <string>
#include <vector>

struct SimAuditEvent {
    std::string simId;
    std::string action;
    std::string timestamp;
};

class SimAudit {
public:
    void record(const SimAuditEvent& event);
    const std::vector<SimAuditEvent>& getEvents() const;

private:
    std::vector<SimAuditEvent> events;
};
