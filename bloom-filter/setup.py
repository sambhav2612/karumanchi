import setuptools

with open("readme.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name='bloomf',
    version='0.2',
    description='Simple Bloom Filter implmentation in Python',
    long_description=long_description,
    long_description_content_type="text/markdown",
    url='https://github.com/sambhav2612/karumanchi/tree/master/bloom-filter',
    author='Sambhav Jain',
    author_email='sambhavjain2612@gmail.com',
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: GNU General Public License v3 (GPLv3)",
        "Operating System :: OS Independent",
    ],
)
