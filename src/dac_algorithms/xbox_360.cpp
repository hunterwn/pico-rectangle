#include "dac_algorithms/xbox_360.hpp"

namespace DACAlgorithms {
namespace Xbox360 {

// Back is inaccessible, idk whether that's a problem, is it *ever* mandatory in place of B ?

void actuateXbox360Report(GpioToButtonSets::F1::ButtonSet buttonSet) {
    bool left = buttonSet.left && !(buttonSet.ms);
    bool right = buttonSet.right && !(buttonSet.ms);
    bool up = buttonSet.up && !(buttonSet.ms);
    bool down = buttonSet.down && !(buttonSet.ms);

    bool dLeft = buttonSet.left && buttonSet.ms;
    bool dRight = buttonSet.right && buttonSet.ms;
    bool dUp = buttonSet.up && buttonSet.ms;
    bool dDown = buttonSet.down && buttonSet.ms;

    USBConfigurations::Xbox360::ControllerReport &xInputReport = USBConfigurations::Xbox360::xInputReport;
    xInputReport.reportId = 0;
    xInputReport.rightStickPress = 0;
    xInputReport.leftStickPress = 0;
    xInputReport.back = buttonSet.cRight;
    xInputReport.start = buttonSet.ls;
    xInputReport.dRight = buttonSet.extra;
    xInputReport.dLeft = buttonSet.x;
    xInputReport.dDown = buttonSet.y;
    xInputReport.dUp = buttonSet.z;
    xInputReport.zl = buttonSet.down;
    xInputReport.zr = buttonSet.left;
    xInputReport.home = 0;
    xInputReport.pad1 = 0;
    xInputReport.a = buttonSet.right;
    xInputReport.b = buttonSet.start;
    xInputReport.x = buttonSet.b;
    xInputReport.y = buttonSet.r;
	xInputReport.leftTrigger = buttonSet.l ? 255 : 0;
	xInputReport.rightTrigger = buttonSet.cDown ? 255 : 0;
	xInputReport.leftStickX = 0;
	xInputReport.leftStickY = 0;
	xInputReport.rightStickX = 0;
	xInputReport.rightStickY = 0;
};

}
}