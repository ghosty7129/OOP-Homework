#pragma once
#include <string>

class Member {
    std::string name;
    std::string memberId;
    int yearJoined;

public:
    Member() = default;
    Member(const std::string &n, const std::string &id, int y) : name(n), memberId(id), yearJoined(y) {}

    void setMemberId(std::string id) { 
        if (!id.empty()) {
           memberId = id;  
        }
    }

    std::string getName() const { 
        return name; 
    }

    std::string getMemberId() const { 
        return memberId; 
    }

    int getYearJoined() const { 
        return yearJoined; 
    }

    std::string to_string() const { 
        return name + " (" + memberId + "), joined: " + std::to_string(yearJoined); 
    }
};
