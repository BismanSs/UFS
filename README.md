# UFS
## Ultimate Fighting Statistics
#### UFC statistics tool
#### Group #16: Paul Scoropan, Gouri Sikha, Bisman Sawnhey, Omer Noor, Jordan Avelar

## How to run:
UFS utilizes the sportsdata.io MMA API endpoints, as such an API key is required. All development of UFS was completed using a free trial key however providing a paid subscription key offers the advantages of more accurate data for some minor statistics provided by the API (see <https://sportsdata.io/developers/faq#scrambled-data>).

The API key must be passed as a command line argument at program execution the first time the program is run or whenever you wish to update the API key saved in the program.

Provided below is a free trial API key provided by us for simplicity

`22e46252d5bf42188e84792db12f8c5c`

UFS reads and writes to a local cache file while it runs, the output path of this cache file can be specified as a second command line argument. If no path is specified, the cache will be saved to `.cache` in the application directory. Please note that if you wish to specify an output path you must also pass the API key as the first argument.

Below are some example program executions

`$ ./UFS 22e46252d5bf42188e84792db12f8c5c`
`$ ./UFS` (this will only work if an api key had been specified previously)
`$ ./UFS 22e46252d5bf42188e84792db12f8c5c C:/path/to/cache`
`$ ./UFS 22e46252d5bf42188e84792db12f8c5c cache.txt`
