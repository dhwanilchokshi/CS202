#include "string.h"

class applications
{
    public:
        applications();
        ~applications();
        int add_apps(String &, String &, String &, String &, int &);
        int display_applications();
        int get_usage_sum();
        int apps_copy(applications &);
        int check(String &t_name);

    protected:
        String name_application;
        String information;
        String date;
        String session_length;
        int usage;

    private:

};
