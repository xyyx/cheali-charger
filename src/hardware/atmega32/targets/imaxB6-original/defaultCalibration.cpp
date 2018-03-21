/*
    cheali-charger - open source firmware for a variety of LiPo chargers
    Copyright (C) 2015  Paweł Stawicki. All right reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "AnalogInputsPrivate.h"
#include "memory.h"
#include "Utils.h"

const AnalogInputs::DefaultValues AnalogInputs::inputsP_[] PROGMEM = {

    {{0,  0},         {52992,  24484}},   //Vout_plus_pin
    {{0,  0},         {52992,  24484}},   //Vout_minus_pin
    {{362,  50},         {10522,  1000}},   //Ismps
    {{1090,  50},         {7744,  300}},   //Idischarge

    {{0,  0},         {0,  0}},   //VoutMux
    {{0,  0},         {0,  0}},   //Tintern
    {{0,  0},         {42432,  12440}},   //Vin
    {{5884,  2280},         {0,  0}},   //Textern

    {{0,  0},         {53628,  4332}},   //Vb0_pin
    {{0,  0},         {53628,  4332}},   //Vb1_pin
    {{0,  0},         {53696,  8432}},   //Vb2_pin
    {{0,  0},         {53569,  4099}},   //Vb3_pin
    {{0,  0},         {51648,  4013}},   //Vb4_pin
    {{0,  0},         {53696,  4062}},   //Vb5_pin
    {{0,  0},         {53155,  4093}},   //Vb6_pin

#if MAX_BALANCE_CELLS > 6
    {{0,  0},         {53155,  4093}},   //Vb7_pin
    {{0,  0},         {53155,  4093}},   //Vb8_pin
#endif

    {{355,  50},         {10520,  1000}},   //IsmpsSet
    {{390,  50},         {2895,  300}},   //IdischargeSet
};

namespace {
    void assert() {
        STATIC_ASSERT(sizeOfArray(AnalogInputs::inputsP_) == AnalogInputs::PHYSICAL_INPUTS);
    }
}
