# Require any additional compass plugins here.
require 'toolkit'
require 'breakpoint'
require 'singularitygs'
require 'color-schemer'
require 'sassy-buttons'

# Set this to the root of your project when deployed:
http_path = "/"
css_dir = "css"
sass_dir = "sass"
images_dir = "img"
javascripts_dir = "js"
fonts_dir = "fonts"

# To enable relative paths to assets via compass helper functions. Since Drupal
# themes can be installed in multiple locations, we don't need to worry about
# the absolute path to the theme from the server root.
relative_assets = true

# To disable debugging comments that display the original location of your selectors. Uncomment:
line_comments = false

# Assuming this theme is in sites/*/themes/THEMENAME, you can add the partials
# included with a module by uncommenting and modifying one of the lines below:
#add_import_path "../../../default/modules/FOO"
#add_import_path "../../../all/modules/FOO"
#add_import_path "../../../../modules/FOO"

# If you prefer the indented syntax, you might want to regenerate this
# project again passing --syntax sass, or you can uncomment this:
# preferred_syntax = :sass
# and then run:
# sass-convert -R --from scss --to sass sass scss && rm -rf sass && mv scss sass

# Change this to :production when ready to deploy the CSS to the live server.
environment = :development
#environment = :production

# In development, we can turn on the debug_info to use with FireSass or Chrome Web Inspector.
#debug = false
debug = true

##
## You probably don't need to edit anything below this.
##

# Disable cache busting on image assets
asset_cache_buster :none

# You can select your preferred output style here (can be overridden via the command line):
# output_style = :expanded or :nested or :compact or :compressed
output_style = (environment == :development) ? :expanded : :compressed

# Pass options to sass. For development, we turn on the FireSass-compatible
# debug_info if the debug config variable above is true.
sass_options = (environment == :development && debug == true) ? {:debug_info => true} : {}
