/*
 * conf_gpio.h
 *
 *  Created on: 29.03.2021
 *      Author: klaud
 */

#ifndef CONF_GPIO_H_
#define CONF_GPIO_H_

#include "stm32f4xx.h"

typedef enum {
	/* Push-Pull; Low, Medium, Full, High Speed. */
	gpio_mode_output_PP_LS = 512,
	gpio_mode_output_PP_MS = 576,
	gpio_mode_output_PP_FS = 640,
	gpio_mode_output_PP_HS = 704,
	/* Open-Drain */
	gpio_mode_output_OD_LS = 768,
	gpio_mode_output_OD_MS = 832,
	gpio_mode_output_OD_FS = 896,
	gpio_mode_output_OD_HS = 960,
	/* Open-Drain with weak Pull-Up */
	gpio_mode_output_OD_PU_LS = 784,
	gpio_mode_output_OD_PU_MS = 848,
	gpio_mode_output_OD_PU_FS = 912,
	gpio_mode_output_OD_PU_HS = 976,
	/* Push-Pull in output state. No pullup in input state. Alternate peripheral controls actual state. */
	gpio_mode_AF0_PP_LS = 1024,
	gpio_mode_AF0_PP_MS = 1088,
	gpio_mode_AF0_PP_FS = 1152,
	gpio_mode_AF0_PP_HS = 1216,
	/* Push-Pull when output. Pull-Up when input. */
	gpio_mode_AF0_PP_PU_LS = 1040,
	gpio_mode_AF0_PP_PU_MS = 1104,
	gpio_mode_AF0_PP_PU_FS = 1168,
	gpio_mode_AF0_PP_PU_HS = 1232,
	/* Push-Pull when output. Pull-Down when input. */
	gpio_mode_AF0_PP_PD_LS = 1056,
	gpio_mode_AF0_PP_PD_MS = 1120,
	gpio_mode_AF0_PP_PD_FS = 1184,
	gpio_mode_AF0_PP_PD_HS = 1248,
	/* Open-Drain */
	gpio_mode_AF0_OD_LS = 1280,
	gpio_mode_AF0_OD_MS = 1344,
	gpio_mode_AF0_OD_FS = 1408,
	gpio_mode_AF0_OD_HS = 1472,
	/* Open-Drain when output. Pull-Up when input. */
	gpio_mode_AF0_OD_PU_LS = 1296,
	gpio_mode_AF0_OD_PU_MS = 1360,
	gpio_mode_AF0_OD_PU_FS = 1424,
	gpio_mode_AF0_OD_PU_HS = 1488,
	/* Open-Drain when output. Pull-Down when input. */
	gpio_mode_AF0_OD_PD_LS = 1312,
	gpio_mode_AF0_OD_PD_MS = 1376,
	gpio_mode_AF0_OD_PD_FS = 1440,
	gpio_mode_AF0_OD_PD_HS = 1504,
	gpio_mode_AF1_PP_LS = 1025,
	gpio_mode_AF1_PP_MS = 1089,
	gpio_mode_AF1_PP_FS = 1153,
	gpio_mode_AF1_PP_HS = 1217,
	gpio_mode_AF1_PP_PU_LS = 1041,
	gpio_mode_AF1_PP_PU_MS = 1105,
	gpio_mode_AF1_PP_PU_FS = 1169,
	gpio_mode_AF1_PP_PU_HS = 1233,
	gpio_mode_AF1_PP_PD_LS = 1057,
	gpio_mode_AF1_PP_PD_MS = 1121,
	gpio_mode_AF1_PP_PD_FS = 1185,
	gpio_mode_AF1_PP_PD_HS = 1249,
	gpio_mode_AF1_OD_LS = 1281,
	gpio_mode_AF1_OD_MS = 1345,
	gpio_mode_AF1_OD_FS = 1409,
	gpio_mode_AF1_OD_HS = 1473,
	gpio_mode_AF7_OD_PU_LS = 1303,
	gpio_mode_AF7_OD_PU_MS = 1367,
	gpio_mode_AF7_OD_PU_FS = 1431,
	gpio_mode_AF7_OD_PU_HS = 1495,
	gpio_mode_AF7_OD_PD_LS = 1319,
	gpio_mode_AF7_OD_PD_MS = 1383,
	gpio_mode_AF7_OD_PD_FS = 1447,
	gpio_mode_AF7_OD_PD_HS = 1511,
	gpio_mode_AF8_PP_LS = 1032,
	gpio_mode_AF8_PP_MS = 1096,
	gpio_mode_AF8_PP_FS = 1160,
	gpio_mode_AF8_PP_HS = 1224,
	gpio_mode_AF8_PP_PU_LS = 1048,
	gpio_mode_AF8_PP_PU_MS = 1112,
	gpio_mode_AF8_PP_PU_FS = 1176,
	gpio_mode_AF8_PP_PU_HS = 1240,
	gpio_mode_AF8_PP_PD_LS = 1064,
	gpio_mode_AF8_PP_PD_MS = 1128,
	gpio_mode_AF8_PP_PD_FS = 1192,
	gpio_mode_AF8_PP_PD_HS = 1256,
	gpio_mode_AF8_OD_LS = 1288,
	gpio_mode_AF8_OD_MS = 1352,
	gpio_mode_AF8_OD_FS = 1416,
	gpio_mode_AF8_OD_HS = 1480,
	gpio_mode_AF8_OD_PU_LS = 1304,
	gpio_mode_AF8_OD_PU_MS = 1368,
	gpio_mode_AF8_OD_PU_FS = 1432,
	gpio_mode_AF8_OD_PU_HS = 1496,
	gpio_mode_AF8_OD_PD_LS = 1320,
	gpio_mode_AF8_OD_PD_MS = 1384,
	gpio_mode_AF8_OD_PD_FS = 1448,
	gpio_mode_AF8_OD_PD_HS = 1512,
	gpio_mode_AF9_PP_LS = 1033,
	gpio_mode_AF9_PP_MS = 1097,
	gpio_mode_AF9_PP_FS = 1161,
	gpio_mode_AF9_PP_HS = 1225,
	gpio_mode_AF9_PP_PU_LS = 1049,
	gpio_mode_AF9_PP_PU_MS = 1113,
	gpio_mode_AF9_PP_PU_FS = 1177,
	gpio_mode_AF9_PP_PU_HS = 1241,
	gpio_mode_AF9_PP_PD_LS = 1065,
	gpio_mode_AF9_PP_PD_MS = 1129,
	gpio_mode_AF9_PP_PD_FS = 1193,
	gpio_mode_AF9_PP_PD_HS = 1257,
	gpio_mode_AF9_OD_LS = 1289,
	gpio_mode_AF9_OD_MS = 1353,
	gpio_mode_AF9_OD_FS = 1417,
	gpio_mode_AF9_OD_HS = 1481,
	gpio_mode_AF9_OD_PU_LS = 1305,
	gpio_mode_AF9_OD_PU_MS = 1369,
	gpio_mode_AF9_OD_PU_FS = 1433,
	gpio_mode_AF9_OD_PU_HS = 1497,
	gpio_mode_AF9_OD_PD_LS = 1321,
	gpio_mode_AF9_OD_PD_MS = 1385,
	gpio_mode_AF9_OD_PD_FS = 1449,
	gpio_mode_AF9_OD_PD_HS = 1513,
	gpio_mode_AF10_PP_LS = 1034,
	gpio_mode_AF10_PP_MS = 1098,
	gpio_mode_AF10_PP_FS = 1162,
	gpio_mode_AF10_PP_HS = 1226,
	gpio_mode_AF10_PP_PU_LS = 1050,
	gpio_mode_AF10_PP_PU_MS = 1114,
	gpio_mode_AF10_PP_PU_FS = 1178,
	gpio_mode_AF10_PP_PU_HS = 1242,
	gpio_mode_AF10_PP_PD_LS = 1066,
	gpio_mode_AF10_PP_PD_MS = 1130,
	gpio_mode_AF10_PP_PD_FS = 1194,
	gpio_mode_AF10_PP_PD_HS = 1258,
	gpio_mode_AF1_OD_PU_LS = 1297,
	gpio_mode_AF1_OD_PU_MS = 1361,
	gpio_mode_AF1_OD_PU_FS = 1425,
	gpio_mode_AF1_OD_PU_HS = 1489,
	gpio_mode_AF1_OD_PD_LS = 1313,
	gpio_mode_AF1_OD_PD_MS = 1377,
	gpio_mode_AF1_OD_PD_FS = 1441,
	gpio_mode_AF1_OD_PD_HS = 1505,
	gpio_mode_AF2_PP_LS = 1026,
	gpio_mode_AF2_PP_MS = 1090,
	gpio_mode_AF2_PP_FS = 1154,
	gpio_mode_AF2_PP_HS = 1218,
	gpio_mode_AF2_PP_PU_LS = 1042,
	gpio_mode_AF2_PP_PU_MS = 1106,
	gpio_mode_AF2_PP_PU_FS = 1170,
	gpio_mode_AF2_PP_PU_HS = 1234,
	gpio_mode_AF2_PP_PD_LS = 1058,
	gpio_mode_AF2_PP_PD_MS = 1122,
	gpio_mode_AF2_PP_PD_FS = 1186,
	gpio_mode_AF2_PP_PD_HS = 1250,
	gpio_mode_AF2_OD_LS = 1282,
	gpio_mode_AF2_OD_MS = 1346,
	gpio_mode_AF2_OD_FS = 1410,
	gpio_mode_AF2_OD_HS = 1474,
	gpio_mode_AF2_OD_PU_LS = 1298,
	gpio_mode_AF2_OD_PU_MS = 1362,
	gpio_mode_AF2_OD_PU_FS = 1426,
	gpio_mode_AF2_OD_PU_HS = 1490,
	gpio_mode_AF2_OD_PD_LS = 1314,
	gpio_mode_AF2_OD_PD_MS = 1378,
	gpio_mode_AF2_OD_PD_FS = 1442,
	gpio_mode_AF2_OD_PD_HS = 1506,
	gpio_mode_AF3_PP_LS = 1027,
	gpio_mode_AF3_PP_MS = 1091,
	gpio_mode_AF3_PP_FS = 1155,
	gpio_mode_AF3_PP_HS = 1219,
	gpio_mode_AF3_PP_PU_LS = 1043,
	gpio_mode_AF3_PP_PU_MS = 1107,
	gpio_mode_AF3_PP_PU_FS = 1171,
	gpio_mode_AF3_PP_PU_HS = 1235,
	gpio_mode_AF3_PP_PD_LS = 1059,
	gpio_mode_AF3_PP_PD_MS = 1123,
	gpio_mode_AF3_PP_PD_FS = 1187,
	gpio_mode_AF3_PP_PD_HS = 1251,
	gpio_mode_AF3_OD_LS = 1283,
	gpio_mode_AF3_OD_MS = 1347,
	gpio_mode_AF3_OD_FS = 1411,
	gpio_mode_AF3_OD_HS = 1475,
	gpio_mode_AF3_OD_PU_LS = 1299,
	gpio_mode_AF3_OD_PU_MS = 1363,
	gpio_mode_AF3_OD_PU_FS = 1427,
	gpio_mode_AF3_OD_PU_HS = 1491,
	gpio_mode_AF3_OD_PD_LS = 1315,
	gpio_mode_AF3_OD_PD_MS = 1379,
	gpio_mode_AF3_OD_PD_FS = 1443,
	gpio_mode_AF3_OD_PD_HS = 1507,
	gpio_mode_AF4_PP_LS = 1028,
	gpio_mode_AF4_PP_MS = 1092,
	gpio_mode_AF4_PP_FS = 1156,
	gpio_mode_AF4_PP_HS = 1220,
	gpio_mode_AF4_PP_PU_LS = 1044,
	gpio_mode_AF4_PP_PU_MS = 1108,
	gpio_mode_AF4_PP_PU_FS = 1172,
	gpio_mode_AF4_PP_PU_HS = 1236,
	gpio_mode_AF4_PP_PD_LS = 1060,
	gpio_mode_AF4_PP_PD_MS = 1124,
	gpio_mode_AF4_PP_PD_FS = 1188,
	gpio_mode_AF4_PP_PD_HS = 1252,
	gpio_mode_AF4_OD_LS = 1284,
	gpio_mode_AF4_OD_MS = 1348,
	gpio_mode_AF10_OD_LS = 1290,
	gpio_mode_AF10_OD_MS = 1354,
	gpio_mode_AF10_OD_FS = 1418,
	gpio_mode_AF10_OD_HS = 1482,
	gpio_mode_AF10_OD_PU_LS = 1306,
	gpio_mode_AF10_OD_PU_MS = 1370,
	gpio_mode_AF10_OD_PU_FS = 1434,
	gpio_mode_AF10_OD_PU_HS = 1498,
	gpio_mode_AF10_OD_PD_LS = 1322,
	gpio_mode_AF10_OD_PD_MS = 1386,
	gpio_mode_AF10_OD_PD_FS = 1450,
	gpio_mode_AF10_OD_PD_HS = 1514,
	gpio_mode_AF11_PP_LS = 1035,
	gpio_mode_AF11_PP_MS = 1099,
	gpio_mode_AF11_PP_FS = 1163,
	gpio_mode_AF11_PP_HS = 1227,
	gpio_mode_AF11_PP_PU_LS = 1051,
	gpio_mode_AF11_PP_PU_MS = 1115,
	gpio_mode_AF11_PP_PU_FS = 1179,
	gpio_mode_AF11_PP_PU_HS = 1243,
	gpio_mode_AF11_PP_PD_LS = 1067,
	gpio_mode_AF11_PP_PD_MS = 1131,
	gpio_mode_AF11_PP_PD_FS = 1195,
	gpio_mode_AF11_PP_PD_HS = 1259,
	gpio_mode_AF11_OD_LS = 1291,
	gpio_mode_AF11_OD_MS = 1355,
	gpio_mode_AF11_OD_FS = 1419,
	gpio_mode_AF11_OD_HS = 1483,
	gpio_mode_AF11_OD_PU_LS = 1307,
	gpio_mode_AF11_OD_PU_MS = 1371,
	gpio_mode_AF11_OD_PU_FS = 1435,
	gpio_mode_AF11_OD_PU_HS = 1499,
	gpio_mode_AF11_OD_PD_LS = 1323,
	gpio_mode_AF11_OD_PD_MS = 1387,
	gpio_mode_AF11_OD_PD_FS = 1451,
	gpio_mode_AF11_OD_PD_HS = 1515,
	gpio_mode_AF12_PP_LS = 1036,
	gpio_mode_AF12_PP_MS = 1100,
	gpio_mode_AF12_PP_FS = 1164,
	gpio_mode_AF12_PP_HS = 1228,
	gpio_mode_AF12_PP_PU_LS = 1052,
	gpio_mode_AF12_PP_PU_MS = 1116,
	gpio_mode_AF12_PP_PU_FS = 1180,
	gpio_mode_AF12_PP_PU_HS = 1244,
	gpio_mode_AF12_PP_PD_LS = 1068,
	gpio_mode_AF12_PP_PD_MS = 1132,
	gpio_mode_AF12_PP_PD_FS = 1196,
	gpio_mode_AF12_PP_PD_HS = 1260,
	gpio_mode_AF12_OD_LS = 1292,
	gpio_mode_AF12_OD_MS = 1356,
	gpio_mode_AF12_OD_FS = 1420,
	gpio_mode_AF12_OD_HS = 1484,
	gpio_mode_AF12_OD_PU_LS = 1308,
	gpio_mode_AF12_OD_PU_MS = 1372,
	gpio_mode_AF12_OD_PU_FS = 1436,
	gpio_mode_AF12_OD_PU_HS = 1500,
	gpio_mode_AF12_OD_PD_LS = 1324,
	gpio_mode_AF12_OD_PD_MS = 1388,
	gpio_mode_AF12_OD_PD_FS = 1452,
	gpio_mode_AF12_OD_PD_HS = 1516,
	gpio_mode_AF13_PP_LS = 1037,
	gpio_mode_AF13_PP_MS = 1101,
	gpio_mode_AF13_PP_FS = 1165,
	gpio_mode_AF13_PP_HS = 1229,
	gpio_mode_AF13_PP_PU_LS = 1053,
	gpio_mode_AF13_PP_PU_MS = 1117,
	gpio_mode_AF13_PP_PU_FS = 1181,
	gpio_mode_AF13_PP_PU_HS = 1245,
	gpio_mode_AF13_PP_PD_LS = 1069,
	gpio_mode_AF13_PP_PD_MS = 1133,
	gpio_mode_AF13_PP_PD_FS = 1197,
	gpio_mode_AF4_OD_FS = 1412,
	gpio_mode_AF4_OD_HS = 1476,
	gpio_mode_AF4_OD_PU_LS = 1300,
	gpio_mode_AF4_OD_PU_MS = 1364,
	gpio_mode_AF4_OD_PU_FS = 1428,
	gpio_mode_AF4_OD_PU_HS = 1492,
	gpio_mode_AF4_OD_PD_LS = 1316,
	gpio_mode_AF4_OD_PD_MS = 1380,
	gpio_mode_AF4_OD_PD_FS = 1444,
	gpio_mode_AF4_OD_PD_HS = 1508,
	gpio_mode_AF5_PP_LS = 1029,
	gpio_mode_AF5_PP_MS = 1093,
	gpio_mode_AF5_PP_FS = 1157,
	gpio_mode_AF5_PP_HS = 1221,
	gpio_mode_AF5_PP_PU_LS = 1045,
	gpio_mode_AF5_PP_PU_MS = 1109,
	gpio_mode_AF5_PP_PU_FS = 1173,
	gpio_mode_AF5_PP_PU_HS = 1237,
	gpio_mode_AF5_PP_PD_LS = 1061,
	gpio_mode_AF5_PP_PD_MS = 1125,
	gpio_mode_AF5_PP_PD_FS = 1189,
	gpio_mode_AF5_PP_PD_HS = 1253,
	gpio_mode_AF5_OD_LS = 1285,
	gpio_mode_AF5_OD_MS = 1349,
	gpio_mode_AF5_OD_FS = 1413,
	gpio_mode_AF5_OD_HS = 1477,
	gpio_mode_AF5_OD_PU_LS = 1301,
	gpio_mode_AF5_OD_PU_MS = 1365,
	gpio_mode_AF5_OD_PU_FS = 1429,
	gpio_mode_AF5_OD_PU_HS = 1493,
	gpio_mode_AF5_OD_PD_LS = 1317,
	gpio_mode_AF5_OD_PD_MS = 1381,
	gpio_mode_AF5_OD_PD_FS = 1445,
	gpio_mode_AF5_OD_PD_HS = 1509,
	gpio_mode_AF6_PP_LS = 1030,
	gpio_mode_AF6_PP_MS = 1094,
	gpio_mode_AF6_PP_FS = 1158,
	gpio_mode_AF6_PP_HS = 1222,
	gpio_mode_AF6_PP_PU_LS = 1046,
	gpio_mode_AF6_PP_PU_MS = 1110,
	gpio_mode_AF6_PP_PU_FS = 1174,
	gpio_mode_AF6_PP_PU_HS = 1238,
	gpio_mode_AF6_PP_PD_LS = 1062,
	gpio_mode_AF6_PP_PD_MS = 1126,
	gpio_mode_AF6_PP_PD_FS = 1190,
	gpio_mode_AF6_PP_PD_HS = 1254,
	gpio_mode_AF6_OD_LS = 1286,
	gpio_mode_AF6_OD_MS = 1350,
	gpio_mode_AF6_OD_FS = 1414,
	gpio_mode_AF6_OD_HS = 1478,
	gpio_mode_AF6_OD_PU_LS = 1302,
	gpio_mode_AF6_OD_PU_MS = 1366,
	gpio_mode_AF6_OD_PU_FS = 1430,
	gpio_mode_AF6_OD_PU_HS = 1494,
	gpio_mode_AF6_OD_PD_LS = 1318,
	gpio_mode_AF6_OD_PD_MS = 1382,
	gpio_mode_AF6_OD_PD_FS = 1446,
	gpio_mode_AF6_OD_PD_HS = 1510,
	gpio_mode_AF7_PP_LS = 1031,
	gpio_mode_AF7_PP_MS = 1095,
	gpio_mode_AF7_PP_FS = 1159,
	gpio_mode_AF7_PP_HS = 1223,
	gpio_mode_AF7_PP_PU_LS = 1047,
	gpio_mode_AF7_PP_PU_MS = 1111,
	gpio_mode_AF7_PP_PU_FS = 1175,
	gpio_mode_AF7_PP_PU_HS = 1239,
	gpio_mode_AF7_PP_PD_LS = 1063,
	gpio_mode_AF7_PP_PD_MS = 1127,
	gpio_mode_AF7_PP_PD_FS = 1191,
	gpio_mode_AF7_PP_PD_HS = 1255,
	gpio_mode_AF13_PP_PD_HS = 1261,
	gpio_mode_AF13_OD_LS = 1293,
	gpio_mode_AF13_OD_MS = 1357,
	gpio_mode_AF13_OD_FS = 1421,
	gpio_mode_AF13_OD_HS = 1485,
	gpio_mode_AF13_OD_PU_LS = 1309,
	gpio_mode_AF13_OD_PU_MS = 1373,
	gpio_mode_AF13_OD_PU_FS = 1437,
	gpio_mode_AF13_OD_PU_HS = 1501,
	gpio_mode_AF13_OD_PD_LS = 1325,
	gpio_mode_AF13_OD_PD_MS = 1389,
	gpio_mode_AF13_OD_PD_FS = 1453,
	gpio_mode_AF13_OD_PD_HS = 1517,
	gpio_mode_AF14_PP_LS = 1038,
	gpio_mode_AF14_PP_MS = 1102,
	gpio_mode_AF14_PP_FS = 1166,
	gpio_mode_AF14_PP_HS = 1230,
	gpio_mode_AF14_PP_PU_LS = 1054,
	gpio_mode_AF14_PP_PU_MS = 1118,
	gpio_mode_AF14_PP_PU_FS = 1182,
	gpio_mode_AF14_PP_PU_HS = 1246,
	gpio_mode_AF14_PP_PD_LS = 1070,
	gpio_mode_AF14_PP_PD_MS = 1134,
	gpio_mode_AF14_PP_PD_FS = 1198,
	gpio_mode_AF14_PP_PD_HS = 1262,
	gpio_mode_AF14_OD_LS = 1294,
	gpio_mode_AF14_OD_MS = 1358,
	gpio_mode_AF14_OD_FS = 1422,
	gpio_mode_AF14_OD_HS = 1486,
	gpio_mode_AF14_OD_PU_LS = 1310,
	gpio_mode_AF14_OD_PU_MS = 1374,
	gpio_mode_AF14_OD_PU_FS = 1438,
	gpio_mode_AF14_OD_PU_HS = 1502,
	gpio_mode_AF14_OD_PD_LS = 1326,
	gpio_mode_AF14_OD_PD_MS = 1390,
	gpio_mode_AF14_OD_PD_FS = 1454,
	gpio_mode_AF14_OD_PD_HS = 1518,
	gpio_mode_AF15_PP_LS = 1039,
	gpio_mode_AF15_PP_MS = 1103,
	gpio_mode_AF15_PP_FS = 1167,
	gpio_mode_AF15_PP_HS = 1231,
	gpio_mode_AF15_PP_PU_LS = 1055,
	gpio_mode_AF15_PP_PU_MS = 1119,
	gpio_mode_AF15_PP_PU_FS = 1183,
	gpio_mode_AF15_PP_PU_HS = 1247,
	gpio_mode_AF15_PP_PD_LS = 1071,
	gpio_mode_AF15_PP_PD_MS = 1135,
	gpio_mode_AF15_PP_PD_FS = 1199,
	gpio_mode_AF15_PP_PD_HS = 1263,
	gpio_mode_AF15_OD_LS = 1295,
	gpio_mode_AF15_OD_MS = 1359,
	gpio_mode_AF15_OD_FS = 1423,
	gpio_mode_AF15_OD_HS = 1487,
	gpio_mode_AF15_OD_PU_LS = 1311,
	gpio_mode_AF15_OD_PU_MS = 1375,
	gpio_mode_AF15_OD_PU_FS = 1439,
	gpio_mode_AF15_OD_PU_HS = 1503,
	gpio_mode_AF15_OD_PD_LS = 1327,
	gpio_mode_AF15_OD_PD_MS = 1391,
	gpio_mode_AF15_OD_PD_FS = 1455,
	gpio_mode_AF15_OD_PD_HS = 1519,
	/* Digital floating input. */
	gpio_mode_in_floating = 0,
	/* Digital input with Pull-Up */
	gpio_mode_in_PU = 16,
	/* Digital input with Pull-Down */
	gpio_mode_in_PD = 32,
	gpio_mode_AF7_OD_LS = 1287,
	gpio_mode_AF7_OD_MS = 1351,
	gpio_mode_AF7_OD_FS = 1415,
	gpio_mode_AF7_OD_HS = 1479,
	/* Analog input/output */
	gpio_mode_analog = 1536
} GpioMode_t;

typedef enum{
	PA0	= 0x00000001,
	PA1	= 0x00000002,
	PA2	= 0x00000004,
	PA3	= 0x00000008,
	PA4	= 0x00000010,
	PA5	= 0x00000020,
	PA6	= 0x00000040,
	PA7	= 0x00000080,
	PA8	= 0x00000100,
	PA9	= 0x00000200,
	PA10= 0x00000400,
	PA11= 0x00000800,
	PA12= 0x00001000,
	PA13= 0x00002000,
	PA14= 0x00004000,
	PA15= 0x00008000,
	PB0	= 0x00000001,
	PB1	= 0x00000002,
	PB2	= 0x00000004,
	PB3	= 0x00000008,
	PB4	= 0x00000010,
	PB5	= 0x00000020,
	PB6	= 0x00000040,
	PB7	= 0x00000080,
	PB8	= 0x00000100,
	PB9	= 0x00000200,
	PB10= 0x00000400,
	PB11= 0x00000800,
	PB12= 0x00001000,
	PB13= 0x00002000,
	PB14= 0x00004000,
	PB15= 0x00008000,
	PC13= 0x00002000,
	PC14= 0x00004000,
	PC15= 0x00008000,

	P0	= 0x00000001,
	P1	= 0x00000002,
	P2	= 0x00000004,
	P3	= 0x00000008,
	P4	= 0x00000010,
	P5	= 0x00000020,
	P6	= 0x00000040,
	P7	= 0x00000080,
	P8	= 0x00000100,
	P9	= 0x00000200,
	P10	= 0x00000400,
	P11	= 0x00000800,
	P12	= 0x00001000,
	P13	= 0x00002000,
	P14	= 0x00004000,
	P15	= 0x00008000,
} GpioPin_t;

void gpio_pin_cfg(GPIO_TypeDef * const __restrict__ port, GpioPin_t pin, GpioMode_t mode);

#endif /* CONF_GPIO_H_ */
