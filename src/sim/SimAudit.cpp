#include "SimAudit.hpp"

void SimAudit::record(const SimAuditEvent& event) {
    events.push_back(event);
}

const std::vector<SimAuditEvent>& SimAudit::getEvents() const {
    return events;
}
