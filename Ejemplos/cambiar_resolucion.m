clc
Datos =  round(out.simout/max(out.simout(:))*(2^12-1));
mplab = sprintf('%.0f,',Datos);
mplab = mplab(1:end-1)
