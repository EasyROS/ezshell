//
// Created by dean on 18-11-30.
//
#pragma once
#include "ClientShell.hpp"
#include "../EZTools/EZTools.hpp"
#include "../EZCommand/EZCommand.hpp"
#include "ClientToServer.hpp"
#include "EZInput.hpp"

ClientShell::ClientShell() {}

ClientShell::~ClientShell() {}

void ClientShell::success() {
    this->state = 4;
}

void ClientShell::error() {
    this->state = -1;
}

void ClientShell::info() {
    this->state = 3;
}
int ClientShell::getState() {
    return this->state;
}
