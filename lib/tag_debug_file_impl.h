/* -*- c++ -*- */
/*
 * Copyright 2018 National Technology & Engineering Solutions of Sandia, LLC (NTESS). Under the terms of Contract DE-NA0003525 with NTESS, the U.S. Government retains certain rights in this software.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_SANDIA_UTILS_TAG_DEBUG_FILE_IMPL_H
#define INCLUDED_SANDIA_UTILS_TAG_DEBUG_FILE_IMPL_H

#include <sandia_utils/tag_debug_file.h>
#include <gnuradio/thread/thread.h>
#include <stddef.h>

namespace gr {
  namespace sandia_utils {

    class tag_debug_file_impl : public tag_debug_file
    {
    private:
      std::string d_name;
      std::string d_filename;
      std::vector<tag_t> d_tags;
      std::vector<tag_t>::iterator d_tags_itr;
      bool d_display;
      bool d_write_file;
      pmt::pmt_t d_filter;
      gr::thread::mutex d_mutex;

     public:
      tag_debug_file_impl(size_t sizeof_stream_item, const std::string &name, const std::string &key_filter, const std::string &filename);
      ~tag_debug_file_impl();

      void setup_rpc();

      std::vector<tag_t> current_tags();
      int num_tags();

      void set_display(bool d);
      void set_filewrite(bool w, bool clear);

      void set_key_filter(const std::string &key_filter);
      std::string key_filter() const;

      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace sandia_utils
} // namespace gr

#endif /* INCLUDED_SANDIA_UTILS_TAG_DEBUG_FILE_IMPL_H */
