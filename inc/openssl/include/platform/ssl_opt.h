// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _SSL_OPT_H_
#define _SSL_OPT_H_

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * if not define "ESP32_IDF_PLATFORM", system will use esp8266 platform interface
 */
#define ESP32_IDF_PLATFORM

/**
 * openssl debug print function enable
 */
#define SSL_DEBUG_ENBALE 0

/** 
 * openssl debug print function level. function whose level is lower that "SSL_DEBUG_LEVEL"
 * will not print message
 */
#define SSL_DEBUG_LEVEL 0

/**
 * openssl assert function enable, it will check the input paramter and print the message
 */
#define SSL_ASSERT_ENABLE 0

/**
 * openssl location function enable, it will print location of the positioning esp_error
 */
#define SSL_DEBUG_LOCATION_ENABLE 0

#endif
