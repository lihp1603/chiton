#ifndef __CHITON_CONFIG_HPP__
#define __CHITON_CONFIG_HPP__
/**************************************************************************
 *
 *     This file is part of Chiton.
 *
 *   Chiton is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Chiton is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Chiton.  If not, see <https://www.gnu.org/licenses/>.
 *
 *   Copyright 2020 Ed Martin <edman007@edman007.com>
 *
 **************************************************************************
 */
#include <string>
#include <map>



/*
 * List of global config values:
 * === Config options required in the .cfg if default is unnacceptable) ===
 * db-host - string for DB server
 * db-user - user for DB server
 * db-password - password for DB server
 * db-database - database to use
 * db-socket - path to socket for db server
 * db-port - port of the DB server
 *
 * === Can be set essentially anywhere (.cfg or database) ==
 * timezone (defaults to system timezone)
 * output-dir - the location to store videos
 * ffmpeg-demux-options - options for the demuxer
 * reorder_queue_len - how many packets to cache to properly resort frames
 * seconds-per-file - how long a file should be, files are split at the next opprotunity after this, in seconds
 * === Applies to a specific camera ===
 * video-url - ffmpeg compatible URL for camera N
 * active - set to "1" when the camera is active
 *
 *
 *
 */

//default config values that absolutly must be set, we define defaults in case we get a bad value
const long DEFAULT_SECONDS_PER_FILE = 360;

class Config {
public:
    bool load_default_config();
    bool load_config(const std::string& path);

    
    const std::string get_value(const std::string& key);
    int get_value_int(const std::string& key);//returns the value as an int
    double get_value_double(const std::string& key);//returns the value as an double
    
    void set_value(const std::string& key, const std::string& value);
    
private:
    std::map<std::string,std::string> cfg_db;
};
#endif
