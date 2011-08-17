#ifndef FILESYSTEM_DIRECTORY_ITERATOR_HPP
#define FILESYSTEM_DIRECTORY_ITERATOR_HPP

#include <boost/system/api_config.hpp>
#include <boost/assert.hpp>
#include <stdexcept>

#ifdef BOOST_WINDOWS_API
    #define NOMINMAX
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else // POSIX
    #include <dirent.h>
    #include <errno.h>
#endif

namespace filesystem
{
    class directory_iterator
    {
    public:
    #ifdef BOOST_WINDOWS_API
        directory_iterator( char const * const path )
            :
            handle_              ( ::FindFirstFileA( path, &state_ ) ),
            p_current_entry_name_( state_.cFileName                  )
        {
            if ( !handle_ )
                throw std::runtime_error( "Error opening a directory." );
        }
    #else // POSIX
         directory_iterator( char const * const path )
            :
            p_dir_( ::opendir( path ) )
        {
            if ( !p_dir_ )
                throw std::runtime_error( "Error opening a directory." );
            get_next_entry();
        }
    #endif // OS API
    
        ~directory_iterator()
        {
            #ifdef BOOST_WINDOWS_API
                BOOST_VERIFY( ::FindClose( handle_ ) );
            #else // POSIX
                ::closedir( p_dir_ );
            #endif // OS API
        }
    
        char const * operator* () const { return p_current_entry_name_; }
    
        directory_iterator & operator++()
        {
            get_next_entry();
            return *this;
        }
    
    private:
        void get_next_entry()
        {
            #ifdef BOOST_WINDOWS_API
                bool failed( false );
                if ( !::FindNextFile( handle_, &state_ ) )
                {
                    p_current_entry_name_ = NULL;
                    failed = ( ::GetLastError() != ERROR_NO_MORE_FILES );
                }
            #else // POSIX
                BOOST_ASSERT_MSG( *this, "Already reached the end of the directory." );
                errno = 0;
                dirent * const p_entry( ::readdir( p_dir_ ) );
                p_current_entry_name_ = p_entry ? p_entry->d_name : NULL;
                bool const failed( !p_entry && errno );
            #endif // OS API
    
            if ( failed )
                throw std::runtime_error( "Error reading a directory." );
        }
    
        #ifdef BOOST_WINDOWS_API
            HANDLE          const handle_;
            WIN32_FIND_DATA       state_ ;
        #else // POSIX
            DIR * const p_dir_;
        #endif // OS API
        char const * p_current_entry_name_;
    };
}

#endif
