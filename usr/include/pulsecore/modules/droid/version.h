#ifndef foodroidversionfoo
#define foodroidversionfoo

/*
 * Copyright (C) 2018-2022 Jolla Ltd.
 *
 * Contact: Juho Hämäläinen <juho.hamalainen@jolla.com>
 *
 * These PulseAudio Modules are free software; you can redistribute
 * it and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 * USA.
 */


#include <android-config.h>
#if defined(QCOM_BSP) || defined(DROID_DEVICE_SBJ)
#define QCOM_HARDWARE
#endif

#include <hardware/audio.h>

#if !defined(ANDROID_VERSION_MAJOR) || !defined(ANDROID_VERSION_MINOR) || !defined(ANDROID_VERSION_PATCH)
#error "ANDROID_VERSION_* not defined. Did you get your headers via extract-headers.sh?"
#endif

/* We currently support API version up to 3.1 */
#define DROID_API_VERSION_SUPPORT       HARDWARE_DEVICE_API_VERSION(3, 1)

#if AUDIO_DEVICE_API_VERSION_CURRENT > DROID_API_VERSION_SUPPORT
#warning Compiling against higher audio device API version than currently supported!
#warning Compile likely fails or module may malfunction.
#endif

#define AUDIO_API_VERSION_MAJ           ((AUDIO_DEVICE_API_VERSION_CURRENT >> 8) & 0xff)
#define AUDIO_API_VERSION_MIN           (AUDIO_DEVICE_API_VERSION_CURRENT & 0xff)

#define AUDIO_API_VERSION_GET_MAJ(x)    ((x >> 8) & 0xff)
#define AUDIO_API_VERSION_GET_MIN(x)    (x & 0xff)

#if AUDIO_API_VERSION_MAJ < 3
#error This module only supports audio API version 3 and upwards.
#endif

#endif
