# Weathermon sensor records database
#
# v0.1


CREATE DATABASE IF NOT EXISTS `hydrodb`;

USE records;


CREATE TABLE IF NOT EXISTS `environment`
(
    rec_id          INT             AUTO_INCREMENT PRIMARY KEY,
    rec_time        TIMESTAMP       NOT NULL DEFAULT CURRENT_TIMESTAMP,
    device_id       VARHCHAR(25)    NOT NULL,
    air_temp        DECIMAL(5,2)    NULL,
    air_humid       DECIMAL(5,2)    NULL,
    air_press       DECIMAL(8,2)    NULL,
    water_temp      DECIMAL(5,2)    NULL

);


CREATE USER 'dbworker'@'localhost' IDENTIFIED BY 'hydroponics';

GRANT ALL PRIVILEGES ON hydrodb.* TO 'dbworker'@'localhost';




