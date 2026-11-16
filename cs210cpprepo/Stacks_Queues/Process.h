//
// Created by cheno on 10/6/2026.
//

#pragma once
#include <iostream>
#include <ostream>
#include <string>

class Process {
public:
    Process(int PID, const std::string& processName, const std::string& desc) : PID_(PID), processName_(processName), desc_(desc) {}

    bool operator==(const Process& other) const {
        return PID_ == other.PID_ &&
               processName_ == other.processName_ &&
               desc_ == other.desc_;
    }

    friend std::ostream& operator<<(std::ostream& out,
                                    const Process& process) {
        out << process.PID_ << " "
            << process.processName_ << " "
            << process.desc_;
        return out;
    }

    void setPID(int newPID) {
        PID_ = newPID;
    }
    void setProcessName(const std::string& newProcessName) {
        processName_ = newProcessName;
    }
    void setDesc(const std::string& newDesc) {
        desc_ = newDesc;
    }
    void print() {
        std::cout << PID_ << " " << processName_ << " " << desc_ << std::endl;
    }
private:
    int PID_;
    std::string processName_;
    std::string desc_;

};


